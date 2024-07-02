#include "CollidableGroup.h"
#include "Collidable.h"

#include "CV_AABB.h"
#include "CV_BSphere.h"
#include "GameObjectAttorney.h"

#include <EngineMath.h>
#include <Visualizer.h>

using CollidableCollection = std::list<Collidable*>;

CollidableGroup::CollidableGroup() :
	collidableCollection(),
	pGroupBox(new CV_AABB())
{
	assert(pGroupBox);
}

CollidableGroup::~CollidableGroup()
{
	delete this->pGroupBox;
}

void CollidableGroup::Register(Collidable* pCol)
{
	this->collidableCollection.push_back(pCol);
}

void CollidableGroup::Deregister(Collidable* pCol)
{
	this->collidableCollection.remove(pCol);
}

const CollidableCollection& CollidableGroup::GetColliderCollection() const
{
	return this->collidableCollection;
}

void CollidableGroup::UpdateGroupColData()
{
	if (this->collidableCollection.size() < 1)
		return;

	auto it = this->collidableCollection.begin();

	Vect min, max;
	const CV_BSphere* pBSphere;
	pBSphere = (CV_BSphere*)&GameObjectAttorney::Collision::GetColPrimitiveVolume(*it);
	it++;

	const float radius = pBSphere->GetRadius();
	const Vect radiusOffset = Vect(radius, radius, radius);
	
	((CV_AABB*)this->pGroupBox)->SetMin(pBSphere->GetCenter() - radiusOffset);
	((CV_AABB*)this->pGroupBox)->SetMax(pBSphere->GetCenter() + radiusOffset);

	// iterate through the rest of the collidable centers to find all the mins/maxes
	while (it != this->collidableCollection.end()) {
		pBSphere = (CV_BSphere*)&GameObjectAttorney::Collision::GetColPrimitiveVolume(*it);
		((CV_AABB*)this->pGroupBox)->ComputeData(*pBSphere);
		it++;
	}
}

const CollisionVolume& CollidableGroup::GetGroupColVol() const
{
	return *this->pGroupBox;
}
