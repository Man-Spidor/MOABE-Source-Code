#include "CollisionTestTerrainCmd.h"

#include "CV_BSphere.h"
#include "TerrainArea.h"
#include "TerrainAreaIterator.h"

#include "Colors.h"
#include "EngineMath.h"
#include "Visualizer.h"

#include "SceneManager.h"
#include "VolumeAttorney.h"
#include "GameObjectAttorney.h"

CollisionTestTerrainCmd::~CollisionTestTerrainCmd()
{
	delete this->pDispatch;
}

CollisionTestTerrainCmd::CollisionTestTerrainCmd(CollisionDispatchProxy* _pDispatch, CollidableGroup& _colGroup) :
	pDispatch(_pDispatch),
	colGroup(_colGroup)
{
}

void CollisionTestTerrainCmd::Execute() const
{
	const CollidableGroup::CollidableCollection& Collection1 = colGroup.GetColliderCollection();

	for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++) {
		const CollisionVolume& pPrimVol1 = GameObjectAttorney::Collision::GetColPrimitiveVolume(*it1);
		const CollisionVolume& pColVol1 = GameObjectAttorney::Collision::GetColVol(*it1);

		const TerrainModel& Terrain = SceneManager::GetCurrScene().GetTerrainModel();

		const Vect Center = ((CV_BSphere*)&pPrimVol1)->GetCenter();
		const float Radius = ((CV_BSphere*)&pPrimVol1)->GetRadius();
		const float CellWidth = Terrain.GetCellWidth();

		Vect min = Center - Vect(Radius, Radius, Radius);
		Vect max = Center + Vect(Radius, Radius, Radius);

		const TerrainArea& Area = SceneManager::GetCurrScene().GetTerrainArea(min, max);
		TerrainAreaIterator itT = Area.begin();

		bool notColliding = true;
		while (notColliding && itT != Area.end()) {
			const TerrainCell& Cell = *itT;

			if (VolumeAttorney::IntersectVisit(pPrimVol1, Cell)) {
				if (VolumeAttorney::IntersectVisit(pColVol1, Cell)) {
					const TerrainCell& CenterCell = Area.GetTerrainCell(Center.X(), Center.Z());
					Visualizer::ShowTerrainCell(CenterCell, Colors::Red);
					float height;
					Vect normal;
					EngineMath::CalculateBarycentricCord(height, normal, CenterCell, Center, CellWidth);

					this->pDispatch->ProcessCallbacks(*it1, height, normal);
					notColliding = false;
				}
				// else {
				// 	Visualizer::SetLowestTestVolume(*it1, &pPrimVol1);
				// 	Visualizer::ShowTerrainCell(Cell);
				// }
			}
			itT++;
		}
	}
}
