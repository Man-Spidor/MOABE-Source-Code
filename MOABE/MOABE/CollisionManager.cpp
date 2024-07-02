#include "CollisionManager.h"
#include "CollisionTestCommand.h"

#include "GameObjectAttorney.h"
#include <Visualizer.h>

CollisionManager::ColID CollisionManager::TypeIDNextNumber = 0;
CollisionManager::CollidableGroupCollection CollisionManager::ColGroupCollection;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
    for (unsigned int i = 0; i < this->ColGroupCollection.size(); i++) {
        if (ColGroupCollection[i] != nullptr) {
            CollidableGroup::CollidableCollection colGroup = ColGroupCollection[i]->GetColliderCollection();
            for (auto pCol : colGroup) {
                GameObjectAttorney::Collision::SetRegStatusDeregistered(pCol);
            }
        }

        delete ColGroupCollection[i];
        ColGroupCollection[i] = nullptr;
    }

    while (!this->colTestCommands.empty()) {
        delete this->colTestCommands.front();
        this->colTestCommands.pop_front();
    }
}

void CollisionManager::ProcessCollisions()
{
    // Update the collidable groups AABB
    for (unsigned int i = 0; i < this->ColGroupCollection.size(); i++) {
        if (this->ColGroupCollection[i] != nullptr)
            this->ColGroupCollection[i]->UpdateGroupColData();
    }

    // Run all the tests
    for (CollisionTestCommands::iterator it = colTestCommands.begin(); it != colTestCommands.end(); it++) {
        (*it)->Execute();
    }

    Visualizer::ShowCollidableGroupList(this->ColGroupCollection);
}

void CollisionManager::ResetCollisionID()
{
    TypeIDNextNumber = 0;
}

void CollisionManager::Register(Collidable* pCol)
{
    const ColID id = GameObjectAttorney::Collision::GetCollisionID(pCol);
    assert(id < this->ColGroupCollection.size());
    this->ColGroupCollection[id]->Register(pCol);
}

void CollisionManager::Deregister(Collidable* pCol)
{
    const ColID id = GameObjectAttorney::Collision::GetCollisionID(pCol);
    assert(id < this->ColGroupCollection.size());
    this->ColGroupCollection[id]->Deregister(pCol);
}

void CollisionManager::InitializeColGroupCollection()
{
    ColGroupCollection.reserve(100);
    ColGroupCollection.push_back(nullptr);
}

CollidableGroup* CollisionManager::GetCollisionGroup(const ColID id) const
{
    assert(id < this->ColGroupCollection.size() - 1);
    return this->ColGroupCollection[id];
}

void CollisionManager::SetGroupForTypeID(const ColID ind)
{
    if (ind >= this->ColGroupCollection.size())
        ColGroupCollection.push_back(nullptr);

    else if (this->ColGroupCollection[ind] == nullptr) {
        this->ColGroupCollection[ind] = new CollidableGroup();
        this->ColGroupCollection.push_back(nullptr);
    }
}
