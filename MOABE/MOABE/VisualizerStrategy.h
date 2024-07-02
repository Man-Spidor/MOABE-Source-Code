#ifndef VISUALIZERSTRATEGY_H
#define VISUALIZERSTRATEGY_H

#include <vector>

class CollidableGroup;
class CollisionVolume;
class Collidable;
class CV_BSphere;
class CV_AABB;
class CV_OBB;
class Vect;

struct TerrainCell;

class VisualizerStrategy
{
protected:
	using CollidableGroupCollection = std::vector<CollidableGroup*>;

public:
	VisualizerStrategy() = default;
	VisualizerStrategy(const VisualizerStrategy& other) = default;
	VisualizerStrategy(VisualizerStrategy&& other) = default;
	VisualizerStrategy& operator=(const VisualizerStrategy& other) = default;
	VisualizerStrategy& operator=(VisualizerStrategy&& other) = default;
	~VisualizerStrategy() = default;

	virtual void Draw() const = 0;

	virtual void ShowBSphere(const CV_BSphere& BSphere, const Vect& color) const = 0;
	virtual void ShowAABB(const CV_AABB& AABB, const Vect& color) const = 0;
	virtual void ShowOBB(const CV_OBB& OBB, const Vect& color) const = 0;

	virtual void ShowTerrainCollision(const TerrainCell& Cell, const Vect& color) const = 0;

	virtual void ShowMarkerPoint(const Vect& point, const Vect& color) const = 0;
	virtual void ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const = 0;
	virtual void ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const = 0;
	virtual void ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const = 0;

	virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) const = 0;
	virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) const = 0;
	virtual void ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection) const = 0;
};

#endif