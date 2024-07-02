#ifndef VISUALIZERDEFAULT_H
#define VISUALIZERDEFAULT_H

#include "VisualizerStrategy.h"

/// @class VisualizerDefault
/// @brief Represents the default visualization strategy for the Visualizer.
class VisualizerDefault : public VisualizerStrategy
{
public:
    /// Default constructor.
    VisualizerDefault() = default;

    /// Copy constructor.
    VisualizerDefault(const VisualizerDefault& other) = delete;

    /// Move constructor.
    VisualizerDefault(VisualizerDefault&& other) = delete;

    /// Copy assignment operator.
    VisualizerDefault& operator=(const VisualizerDefault& other) = delete;

    /// Move assignment operator.
    VisualizerDefault& operator=(VisualizerDefault&& other) = delete;

    /// Destructor.
    ~VisualizerDefault() = default;

    /// Draw function that does nothing.
    virtual void Draw() const override { };

    /// Show bounding sphere function that does nothing.
    virtual void ShowBSphere(const CV_BSphere& BSphere, const Vect& color) const override { UNREFERENCED_PARAMETER(BSphere); UNREFERENCED_PARAMETER(color); };

    /// Show AABB function that does nothing.
    virtual void ShowAABB(const CV_AABB& AABB, const Vect& color) const override { UNREFERENCED_PARAMETER(AABB); UNREFERENCED_PARAMETER(color); };

    /// Show OBB function that does nothing.
    virtual void ShowOBB(const CV_OBB& OBB, const Vect& color) const override { UNREFERENCED_PARAMETER(OBB); UNREFERENCED_PARAMETER(color); };

    /// Show terrain collision function that does nothing.
    virtual void ShowTerrainCollision(const TerrainCell& Cell, const Vect& color) const override { UNREFERENCED_PARAMETER(Cell); UNREFERENCED_PARAMETER(color); };

    /// Show marker point function that does nothing.
    virtual void ShowMarkerPoint(const Vect& point, const Vect& color) const override { UNREFERENCED_PARAMETER(point); UNREFERENCED_PARAMETER(color); };

    /// Show marker line segment function that does nothing.
    virtual void ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const override { UNREFERENCED_PARAMETER(startPoint); UNREFERENCED_PARAMETER(endPoint); UNREFERENCED_PARAMETER(color); };

    /// Show marker line ray function that does nothing.
    virtual void ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const override { UNREFERENCED_PARAMETER(startPoint); UNREFERENCED_PARAMETER(targetPos); UNREFERENCED_PARAMETER(color); };

    /// Show marker line function that does nothing.
    virtual void ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const override { UNREFERENCED_PARAMETER(startPoint); UNREFERENCED_PARAMETER(targetPos); UNREFERENCED_PARAMETER(color); };

    /// Set lowest test volume function that does nothing.
    virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) const override { UNREFERENCED_PARAMETER(pCol); UNREFERENCED_PARAMETER(ColVol); };

    /// Set lowest test volume function that does nothing with a specific color.
    virtual void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) const override { UNREFERENCED_PARAMETER(pCol); UNREFERENCED_PARAMETER(ColVol); UNREFERENCED_PARAMETER(color); };

    /// Show collidable group list function that does nothing.
    virtual void ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection) const override { UNREFERENCED_PARAMETER(ColGroupCollection); };
};

#endif // VISUALIZERDEFAULT_H
