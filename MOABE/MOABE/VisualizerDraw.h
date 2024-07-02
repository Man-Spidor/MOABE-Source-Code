#ifndef VISUALIZERDRAW_H
#define VISUALIZERDRAW_H

#include "VisualizerStrategy.h"

/// @class VisualizerDrawDefault
/// @brief Represents the default visualization strategy for the Visualizer.
class VisualizerDrawDefault : public VisualizerStrategy
{
public:
    VisualizerDrawDefault() = default;
    VisualizerDrawDefault(const VisualizerDrawDefault& other) = default;
    VisualizerDrawDefault(VisualizerDrawDefault&& other) = default;
    VisualizerDrawDefault& operator=(const VisualizerDrawDefault& other) = default;
    VisualizerDrawDefault& operator=(VisualizerDrawDefault&& other) = default;
    ~VisualizerDrawDefault() = default;

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

#endif // VISUALIZERDRAW_H
