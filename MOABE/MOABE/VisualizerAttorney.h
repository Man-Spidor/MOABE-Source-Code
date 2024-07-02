#ifndef VISUALIZERATTORNEY_H
#define VISUALIZERATTORNEY_H

#include "Visualizer.h"

class VisualizerAttorney
{
public:
	class Loop
	{
		friend class MOABE;
		static void Draw() { Visualizer::Draw(); };
		static void Delete() { Visualizer::Delete(); };
	};
	class VisStrats
	{
		friend class VisualizerMarkers;
		friend class VisualizeOBBCmd;
		friend class VisualizeAABBCmd;
		friend class VisualizeBSphereCmd;
		friend class VisualizePointCmd;
		friend class VisualizeLineCmd;
		friend class VisualizeLineRayCmd;
		friend class VisualizeLineSegmentCmd;
		friend class VisualizeTerrainCellCmd;

		friend class VisualizerDrawDefault;
		friend class VisualizerDrawAllCollidable;

		static void VisualizeAll() { Visualizer::VisualizeAll(); };
		static void PushBsphereCmd(const CV_BSphere& BSphere, const Vect& color) { Visualizer::pushBSphereCmd(BSphere, color); };
		static void PushAABBCmd(const CV_AABB& AABB, const Vect& color) { Visualizer::pushAABBCmd(AABB, color); };
		static void PushOBBCmd(const CV_OBB& OBB, const Vect& color) { Visualizer::pushOBBCmd(OBB, color); };
		static void PushTerrainCellCmd(const TerrainCell& Cell, const Vect& color) { Visualizer::pushTerrainCellCmd(Cell, color); };

		static void PushPointCmd(const Vect& point, const Vect& color) { Visualizer::pushPointCmd(point, color); };
		static void PushLineCmd(const Vect& startPoint, const Vect& targetPos, const Vect& color) { Visualizer::pushLineCmd(startPoint, targetPos, color); };
		static void PushLineRayCmd(const Vect& startPoint, const Vect& targetPos, const Vect& color) { Visualizer::pushLineRayCmd(startPoint, targetPos, color); };
		static void PushLineSegmentCmd(const Vect& startPoint, const Vect& endPoint, const Vect& color) { Visualizer::pushLineSegmentCmd(startPoint, endPoint, color); };

		static void ReturnDrawCmd(VisualizeLineCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		static void ReturnDrawCmd(VisualizePointCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		static void ReturnDrawCmd(VisualizeLineRayCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		static void ReturnDrawCmd(VisualizeLineSegmentCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		static void ReturnDrawCmd(VisualizeTerrainCellCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };

		static void ReturnDrawCmd(VisualizeOBBCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		static void ReturnDrawCmd(VisualizeAABBCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		static void ReturnDrawCmd(VisualizeBSphereCmd* pCmd) { Visualizer::ReturnDrawCmd(pCmd); };
		
		static void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol) { Visualizer::setLowestTestVolumeStrategy(pCol, ColVol); };
		static void SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color) { Visualizer::setLowestTestVolumeStrategy(pCol, ColVol, color); };
		static void ShowCollidableGroupList(const Visualizer::CollidableGroupCollection& ColGroupCollection) { UNREFERENCED_PARAMETER(ColGroupCollection); Visualizer::showCollisions(); };
		static void ShowCollisions() { Visualizer::showCollisions(); };
		static void ShowCollidables(const Visualizer::CollidableGroupCollection& ColGroupCollection) { Visualizer::showCollidables(ColGroupCollection); };
	};
};

#endif