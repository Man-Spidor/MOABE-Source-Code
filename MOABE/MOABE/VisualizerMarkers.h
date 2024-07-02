#ifndef VISUALIZERBARYCENTRIC_H
#define VISUALIZERBARYCENTRIC_H

#include "VisualizerStrategy.h"

/// @class VisualizerMarkers
/// @brief Represents the visualization strategy that draws markers.
class VisualizerMarkers : public VisualizerStrategy
{
public:
    VisualizerMarkers() = default;
    VisualizerMarkers(const VisualizerMarkers& other) = default;
    VisualizerMarkers& operator=(const VisualizerMarkers& other) = default;
    VisualizerMarkers(VisualizerMarkers&& other) = default;
    VisualizerMarkers& operator=(VisualizerMarkers&& other) = default;
    ~VisualizerMarkers() = default;

    virtual void Draw() const override;
    virtual void ShowBSphere(const CV_BSphere& BSphere, const Vect& color) const override { UNREFERENCED_PARAMETER(BSphere); UNREFERENCED_PARAMETER(color); };
    virtual void ShowAABB(const CV_AABB& AABB, const Vect& color) const override { UNREFERENCED_PARAMETER(AABB); UNREFERENCED_PARAMETER(color); };
    virtual void ShowOBB(const CV_OBB& OBB, const Vect& color) const override { UNREFERENCED_PARAMETER(OBB); UNREFERENCED_PARAMETER(color); };
    virtual void ShowTerrainCollision(const TerrainCell& Cell, const Vect& color) const override { UNREFERENCED_PARAMETER(Cell); UNREFERENCED_PARAMETER(color); };
    virtual void ShowMarkerPoint(const Vect& point, const Vect& color) const override;
    virtual void ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const override;
    virtual void ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const override;
    virtual void ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const override;
    virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) const override { UNREFERENCED_PARAMETER(pCol); UNREFERENCED_PARAMETER(ColVol); };
    virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) const override { UNREFERENCED_PARAMETER(pCol); UNREFERENCED_PARAMETER(ColVol); UNREFERENCED_PARAMETER(color); };
    virtual void ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection) const override { UNREFERENCED_PARAMETER(ColGroupCollection); };
};

#endif // VISUALIZERBARYCENTRIC_H
