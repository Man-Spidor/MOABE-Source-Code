#include "CollisionTestSelfCmd.h"
#include "CollisionDispatchProxy.h"
#include "GameObjectAttorney.h"
#include "EngineMath.h"
#include "Visualizer.h"
#include "Colors.h"

CollisionTestSelfCmd::~CollisionTestSelfCmd()
{
	delete this->pDispatch;
}

CollisionTestSelfCmd::CollisionTestSelfCmd(CollisionDispatchProxy* _pDispatch, CollidableGroup& _colGroup) :
	pDispatch(_pDispatch),
	colGroup(_colGroup)
{
}

void CollisionTestSelfCmd::Execute() const
{
	const CollidableGroup::CollidableCollection& Collection1 = colGroup.GetColliderCollection();

	for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++) {
		const CollisionVolume& pPrimVol1 = GameObjectAttorney::Collision::GetColPrimitiveVolume(*it1);
		const CollisionVolume& pColVol1 = GameObjectAttorney::Collision::GetColVol(*it1);

		for (auto it2 = std::next(it1, 1); it2 != Collection1.end(); it2++) {
			const CollisionVolume& pPrimVol2 = GameObjectAttorney::Collision::GetColPrimitiveVolume(*it2);
			if (EngineMath::Intersect(pPrimVol1, pPrimVol2)) {
				const CollisionVolume& pColVol2 = GameObjectAttorney::Collision::GetColVol(*it2);
				if (EngineMath::Intersect(pColVol1, pColVol2)) {
					Visualizer::SetLowestTestVolume(*it1, &pColVol1, Colors::Red);
					Visualizer::SetLowestTestVolume(*it2, &pColVol2, Colors::Red);
					pDispatch->ProcessCallbacks(*it1, *it2);
				}
				else {
					Visualizer::SetLowestTestVolume(*it1, &pColVol1);
					Visualizer::SetLowestTestVolume(*it2, &pColVol2);
				}
			}
			else {
				Visualizer::SetLowestTestVolume(*it1, (CollisionVolume*)&pPrimVol1);
				Visualizer::SetLowestTestVolume(*it2, (CollisionVolume*)&pPrimVol2);
			}
		}
	}
}
