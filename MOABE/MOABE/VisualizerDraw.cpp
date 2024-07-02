#include "VisualizerDraw.h"
#include "VisualizerAttorney.h"

#include "CV_AABB.h"

void VisualizerDrawDefault::Draw() const
{
	VisualizerAttorney::VisStrats::VisualizeAll();
}

void VisualizerDrawDefault::ShowBSphere(const CV_BSphere& BSphere, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushBsphereCmd(BSphere, color);
}

void VisualizerDrawDefault::ShowAABB(const CV_AABB& AABB, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushAABBCmd(AABB, color);
}

void VisualizerDrawDefault::ShowOBB(const CV_OBB& OBB, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushOBBCmd(OBB, color);
}

void VisualizerDrawDefault::ShowTerrainCollision(const TerrainCell& Cell, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushTerrainCellCmd(Cell, color);
}

void VisualizerDrawDefault::ShowMarkerPoint(const Vect& point, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushPointCmd(point, color);
}

void VisualizerDrawDefault::ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushLineSegmentCmd(startPoint, endPoint, color);
}

void VisualizerDrawDefault::ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushLineRayCmd(startPoint, targetPos, color);
}

void VisualizerDrawDefault::ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushLineCmd(startPoint, targetPos, color);
}

void VisualizerDrawDefault::SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) const
{
	VisualizerAttorney::VisStrats::SetLowestTestVolume(pCol, ColVol);
}

void VisualizerDrawDefault::SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) const
{
	VisualizerAttorney::VisStrats::SetLowestTestVolume(pCol, ColVol, color);
}

void VisualizerDrawDefault::ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection) const
{
	UNREFERENCED_PARAMETER(ColGroupCollection);
	VisualizerAttorney::VisStrats::ShowCollisions();
}
