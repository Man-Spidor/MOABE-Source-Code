#ifndef VISUALIZERDRAWALLCOLLIDABLE_H
#define VISUALIZERDRAWALLCOLLIDABLE_H

#include "VisualizerStrategy.h"

/// @brief Represents the visualization strategy that draws all collidable objects.
class VisualizerDrawAllCollidable : public VisualizerStrategy
{
public:
    VisualizerDrawAllCollidable() = default;
    VisualizerDrawAllCollidable(const VisualizerDrawAllCollidable& other) = default;
    VisualizerDrawAllCollidable& operator=(const VisualizerDrawAllCollidable& other) = default;
    VisualizerDrawAllCollidable(VisualizerDrawAllCollidable&& other) = default;
    VisualizerDrawAllCollidable& operator=(VisualizerDrawAllCollidable&& other) = default;
    ~VisualizerDrawAllCollidable() = default;

    virtual void Draw() const override;
    virtual void ShowBSphere(const CV_BSphere& BSphere, const Vect& color) const override;
    virtual void ShowAABB(const CV_AABB& AABB, const Vect& color) const override;
    virtual void ShowOBB(const CV_OBB& OBB, const Vect& color) const override;
    virtual void ShowTerrainCollision(const TerrainCell& Cell, const Vect& color) const override;
    virtual void ShowMarkerPoint(const Vect& point, const Vect& color) const override;
    virtual void ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const override;
    virtual void ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const override;
    virtual void ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const override;
    virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) const override;
    virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) const override;
    virtual void ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection) const override;
};

#endif // VISUALIZERDRAWALLCOLLIDABLE_H
