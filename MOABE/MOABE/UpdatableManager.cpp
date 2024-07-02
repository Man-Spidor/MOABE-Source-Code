#include "UpdatableManager.h"
#include "Updatable.h"
#include "GameObjectAttorney.h"

void UpdatableManager::ClearLists()
{
	for (Updatable* pUpdate : this->updateList) {
		GameObjectAttorney::Update::SetRegStatusDeregistered(pUpdate);
	}
}

void UpdatableManager::ProcessElements() const
{
	for (Updatable* pUpdate : this->updateList) {
		GameObjectAttorney::Update::UpdateObject(pUpdate);
	}
}

void UpdatableManager::Register(Updatable* pUpdate)
{
	UpdatableListRef deleteRef = this->updateList.insert(this->updateList.end(), pUpdate);
	GameObjectAttorney::Update::SetDeleteRef(pUpdate, deleteRef);
}

void UpdatableManager::Deregister(Updatable* pUpdate)
{
	this->updateList.erase(GameObjectAttorney::Update::GetDeleteRef(pUpdate));
}
