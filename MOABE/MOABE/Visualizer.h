#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "VisualizerCmdBroker.h"
#include "VisualizeCmdPool.h"
#include "VisualizerMode.h"

#include <vector>
#include <map>

class VisualizerStrategy;

class CollidableGroup;
class CollisionVolume;
class Collidable;
class CV_BSphere;
class CV_AABB;
class CV_OBB;

struct TerrainCell;

/// @brief Provides functionality for visualizing collision volumes and markers.
///
/// The Visualizer class provides functionality for visualizing collision volumes such as bounding spheres,
/// AABBs, OBBs, and terrain cells. It offers four main strategies for visualization:
///
/// 1. DRAW_NONE: Ignores all draw requests.
/// 2. DRAW_DEFAULT: Processes every draw command it receives and visualizes the collision tests.
/// 3. DRAW_MARKERS: Processes only the marker draw commands, useful for visualizing tests.
/// 4. DRAW_COLLIDABLES: Shows only the base collision volume of each collidable.
///
/// ### Example Usage:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// // Activate the visualizer with the default mode.
/// Visualizer::Activate(VisualizeMode::DRAW_DEFAULT);
///
/// // Show a bounding sphere.
/// CV_BSphere bsphere({ 0, 0, 0 }, 5.0f);
/// Visualizer::ShowBSphere(bsphere, Vect(1, 0, 0)); // Visualize in red color.
///
/// // Show a point.
/// Vect point = Vect(0.0f, 0.0f, 0.0f);
/// Visualizer::ShowMarkerPoint(point); // Visualize in Visualizer's default color.
///
/// // Show a line.
/// Vect startpoint = Vect(0.0f, 0.0f, 0.0f);
/// Vect endpoint = Vect(10.0f, 0.0f, 10.0f);
/// Visualizer::ShowMarkerLine(startpoint, endpoint, Vect(1, 0, 0)); // Visualize in red color.
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Visualizer
{
    friend class VisualizerAttorney;
    using CollidableGroupCollection = std::vector<CollidableGroup*>;
    using VolumeDrawPair = std::pair<const CollisionVolume*, Vect>;
    using CollidableDrawList = std::map<const Collidable*, VolumeDrawPair>;

private:
    /// @brief Default constructor.
    Visualizer();

    /// @brief Copy constructor.
    Visualizer(const Visualizer& other) = default;

    /// @brief Copy assignment operator.
    Visualizer& operator=(const Visualizer& other) = default;

    /// @brief Move constructor.
    Visualizer(Visualizer&& other) = default;

    /// @brief Move assignment operator.
    Visualizer& operator=(Visualizer&& other) = default;

    /// @brief Destructor.
    ~Visualizer() = default;

private:
    /// @brief Static function to draw visualizations.
    static void Draw();

    /// @brief Static function to visualize all objects.
    static void VisualizeAll();

    /// @brief Static function to visualize only collisions.
    static void VisualizeAllCollidable();

    /// @brief Static function to delete objects.
    static void Delete();

public:
    /// @brief Activates the visualizer with the specified mode.
    /// @param mode The visualization mode to use.
    static void Activate(VisualizeMode mode);

    /// @brief Deactivates the visualizer.
    static void Deactivate();

    /// @brief Displays a collision volume with the default color.
    /// @param ColVol The collision volume to visualize.
    static void ShowVolume(const CollisionVolume& ColVol);

    /// @brief Displays a collision volume with a specific color.
    /// @param ColVol The collision volume to visualize.
    /// @param color The color to use for visualization.
    static void ShowVolume(const CollisionVolume& ColVol, const Vect& color);

    /// @brief Displays a bounding sphere with the default color.
    /// @param BSphere The bounding sphere to visualize.
    static void ShowBSphere(const CV_BSphere& BSphere);

    /// @brief Displays a bounding sphere with a specific color.
    /// @param BSphere The bounding sphere to visualize.
    /// @param color The color to use for visualization.
    static void ShowBSphere(const CV_BSphere& BSphere, const Vect& color);

    /// @brief Displays an AABB with the default color.
    /// @param AABB The AABB to visualize.
    static void ShowAABB(const CV_AABB& AABB);

    /// @brief Displays an AABB with a specific color.
    /// @param AABB The AABB to visualize.
    /// @param color The color to use for visualization.
    static void ShowAABB(const CV_AABB& AABB, const Vect& color);

    /// @brief Displays an OBB with the default color.
    /// @param OBB The OBB to visualize.
    static void ShowOBB(const CV_OBB& OBB);

    /// @brief Displays an OBB with a specific color.
    /// @param OBB The OBB to visualize.
    /// @param color The color to use for visualization.
    static void ShowOBB(const CV_OBB& OBB, const Vect& color);

    /// @brief Displays a terrain cell with the default color.
    /// @param Cell The terrain cell to visualize.
    static void ShowTerrainCell(const TerrainCell& Cell);

    /// @brief Displays a terrain cell with a specific color.
    /// @param Cell The terrain cell to visualize.
    /// @param Color The color to use for visualization.
    static void ShowTerrainCell(const TerrainCell& Cell, const Vect& Color);

    /// @brief Displays a marker point with the default color.
    /// @param point The point to visualize.
    static void ShowMarkerPoint(const Vect& point);

    /// @brief Displays a line segment with the default color.
    /// @param startPoint The start point of the line segment.
    /// @param endPoint The end point of the line segment.
    static void ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint);

    /// @brief Displays a line ray with the default color.
    /// @param startPoint The start point of the line ray.
    /// @param targetPos The target position of the line ray.
    static void ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos);

    /// @brief Displays a line with the default color.
    /// @param startPoint The start point of the line.
    /// @param targetPos The target position of the line.
    static void ShowMarkerLine(const Vect& startPoint, const Vect& targetPos);

    /// @brief Displays a marker point with a specific color.
    /// @param point The point to visualize.
    /// @param color The color to use for visualization.
    static void ShowMarkerPoint(const Vect& point, const Vect& color);

    /// @brief Displays a line segment with a specific color.
    /// @param startPoint The start point of the line segment.
    /// @param endPoint The end point of the line segment.
    /// @param color The color to use for visualization.
    static void ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color);

    /// @brief Displays a line ray with a specific color.
    /// @param startPoint The start point of the line ray.
    /// @param targetPos The target position of the line ray.
    /// @param color The color to use for visualization.
    static void ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color);

    /// @brief Displays a line with a specific color.
    /// @param startPoint The start point of the line.
    /// @param targetPos The target position of the line.
    /// @param color The color to use for visualization.
    static void ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color);

    /// @brief Sets the lowest test volume for a collidable object.
    /// @param pCol Pointer to the collidable object.
    /// @param ColVol Pointer to the collision volume.
    static void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol);

    /// @brief Sets the lowest test volume for a collidable object with a specific color.
    /// @param pCol Pointer to the collidable object.
    /// @param ColVol Pointer to the collision volume.
    /// @param color The color to use for visualization.
    static void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color);

    /// @brief Shows the collidable group list.
    /// @param ColGroupCollection The collection of collidable groups.
    static void ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection);

private:
    /// @brief Pushes a bounding sphere command to the broker.
    /// @param BSphere The bounding sphere to visualize.
    /// @param color The color to use for visualization.
    static void pushBSphereCmd(const CV_BSphere& BSphere, const Vect& color);

    /// @brief Pushes an AABB draw command to the broker.
    /// @param AABB The AABB to visualize.
    /// @param color The color to use for visualization.
    static void pushAABBCmd(const CV_AABB& AABB, const Vect& color);

    /// @brief Pushes an OBB draw command to the broker.
    /// @param OBB The OBB to visualize.
    /// @param color The color to use for visualization.
    static void pushOBBCmd(const CV_OBB& OBB, const Vect& color);

    /// @brief Pushes a terrain cell draw command to the broker.
    /// @param Cell The terrain cell to visualize.
    /// @param color The color to use for visualization.
    static void pushTerrainCellCmd(const TerrainCell& Cell, const Vect& color);

    /// @brief Pushes a point draw command to the broker.
    /// @param point The point to visualize.
    /// @param color The color to use for visualization.
    static void pushPointCmd(const Vect& point, const Vect& color);

    /// @brief Pushes a line draw command to the broker.
    /// @param startPoint The start point of the line.
    /// @param targetPos The target position of the line.
    /// @param color The color to use for visualization.
    static void pushLineCmd(const Vect& startPoint, const Vect& targetPos, const Vect& color);

    /// @brief Pushes a line ray draw command to the broker.
    /// @param startPoint The start point of the line ray.
    /// @param targetPos The target position of the line ray.
    /// @param color The color to use for visualization.
    static void pushLineRayCmd(const Vect& startPoint, const Vect& targetPos, const Vect& color);

    /// @brief Pushes a line segment draw command to the broker.
    /// @param startPoint The start point of the line segment.
    /// @param endPoint The end point of the line segment.
    /// @param color The color to use for visualization.
    static void pushLineSegmentCmd(const Vect& startPoint, const Vect& endPoint, const Vect& color);

    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeBSphereCmd* pCmd);
    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeAABBCmd* pCmd);
    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeOBBCmd* pCmd);
    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeTerrainCellCmd* pCmd);

    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeLineCmd* pCmd);
    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizePointCmd* pCmd);
    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeLineRayCmd* pCmd);
    /// Returns used DrawCommands to the Pool to avoid constant news and deletes
    static void ReturnDrawCmd(VisualizeLineSegmentCmd* pCmd);

    /// Sets the lowest volume that was tested, to be drawn at a later point
    /// 
    /// Called each time a collision test is run
    static void setLowestTestVolumeStrategy(const Collidable* pCol, const CollisionVolume* ColVol);
    
    /// Sets the lowest volume that was tested, to be drawn at a later point
    /// 
    /// Called each time a collision test is run
    static void setLowestTestVolumeStrategy(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color);
    
    /// /// Shows all the Collidable, CollisionVolume pairs gathered earlier, then clears them
    /// 
    /// Called at the end of all the collision tests
    static void showCollisions();

    /// Shows all the Collidables in the ColGroupCollection
    /// 
    /// Called by the scene depending on the Visualizer mode
    static void showCollidables(const CollidableGroupCollection& ColGroupCollection);

    /// @brief Gets the instance of the Visualizer.
    /// @return Reference to the instance of the Visualizer.
    static Visualizer& Instance();

private:
    static Visualizer* instance; ///< Pointer to the instance of the Visualizer.
    static const VisualizerStrategy* myStrategy; ///< Pointer to the current visualization strategy.
    static Vect DEFAULT_COLOR; ///< The default color used for visualization.

    VisualizerCmdBroker cmdBroker; ///< The command broker for managing visualization commands.
    VisualizeCmdPool cmdPool; ///< The pool of visualize commands.

    CollidableDrawList colDrawList; ///< The list of collidable objects to draw.
};

#endif // VISUALIZER_H
