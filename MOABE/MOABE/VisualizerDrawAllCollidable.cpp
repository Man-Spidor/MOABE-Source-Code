#include "VisualizerDrawAllCollidable.h"
#include "VisualizerAttorney.h"

#include "Collidable.h"
#include "CollidableGroup.h"

#include <GameObjectAttorney.h>

void VisualizerDrawAllCollidable::Draw() const
{
	VisualizerAttorney::VisStrats::VisualizeAll();
}

void VisualizerDrawAllCollidable::ShowBSphere(const CV_BSphere& BSphere, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushBsphereCmd(BSphere, color);
}

void VisualizerDrawAllCollidable::ShowAABB(const CV_AABB& AABB, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushAABBCmd(AABB, color);
}

void VisualizerDrawAllCollidable::ShowOBB(const CV_OBB& OBB, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushOBBCmd(OBB, color);
}

void VisualizerDrawAllCollidable::ShowTerrainCollision(const TerrainCell& Cell, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushTerrainCellCmd(Cell, color);
}

void VisualizerDrawAllCollidable::ShowMarkerPoint(const Vect& point, const Vect& color) const
{
	UNREFERENCED_PARAMETER(point);
	UNREFERENCED_PARAMETER(color);
}

void VisualizerDrawAllCollidable::ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const
{
	UNREFERENCED_PARAMETER(startPoint);
	UNREFERENCED_PARAMETER(endPoint);
	UNREFERENCED_PARAMETER(color);
}

void VisualizerDrawAllCollidable::ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const
{
	UNREFERENCED_PARAMETER(color);
	UNREFERENCED_PARAMETER(startPoint);
	UNREFERENCED_PARAMETER(targetPos);
}

void VisualizerDrawAllCollidable::ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const
{
	UNREFERENCED_PARAMETER(color);
	UNREFERENCED_PARAMETER(startPoint);
	UNREFERENCED_PARAMETER(targetPos);
}

void VisualizerDrawAllCollidable::SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) const
{
	UNREFERENCED_PARAMETER(pCol);
	UNREFERENCED_PARAMETER(ColVol);
}

void VisualizerDrawAllCollidable::SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) const
{
	UNREFERENCED_PARAMETER(pCol);
	UNREFERENCED_PARAMETER(ColVol);
	UNREFERENCED_PARAMETER(color);
}

void VisualizerDrawAllCollidable::ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection) const
{	
	VisualizerAttorney::VisStrats::ShowCollidables(ColGroupCollection);
}
