#ifndef VISUALIZECMDPOOL_H
#define VISUALIZECMDPOOL_H

#include <stack>
#include <GraphicsObject_Wireframe.h>

class VisualizeCommand;
class VisualizeOBBCmd;
class VisualizeAABBCmd;
class VisualizeBSphereCmd;
class VisualizeTerrainCellCmd;

class VisualizeLineCmd;
class VisualizePointCmd;
class VisualizeLineRayCmd;
class VisualizeLineSegmentCmd;

class VisualizeCmdPool
{
public:
	VisualizeCmdPool() = delete;
	VisualizeCmdPool(Vect& color);
	VisualizeCmdPool(const VisualizeCmdPool& other) = default;
	VisualizeCmdPool& operator=(const VisualizeCmdPool& other) = default;
	VisualizeCmdPool(VisualizeCmdPool&& other) = default;
	VisualizeCmdPool& operator=(VisualizeCmdPool&& other) = default;
	~VisualizeCmdPool();

	VisualizeOBBCmd* GetDrawOBBCmd();
	VisualizeAABBCmd* GetDrawAABBCmd();
	VisualizeBSphereCmd* GetDrawBSphere();
	VisualizeTerrainCellCmd* GetDrawTerrainCellCmd();

	VisualizeLineCmd* GetDrawLineMarkerCmd();
	VisualizePointCmd* GetDrawPointMarkerCmd();
	VisualizeLineRayCmd* GetDrawLineRayMarkerCmd();
	VisualizeLineSegmentCmd* GetDrawLineSegmentMarkerCmd();

	void ReturnDrawOBBCmd(VisualizeOBBCmd* pCmd);
	void ReturnDrawAABBCmd(VisualizeAABBCmd* pCmd);
	void ReturnDrawBSphereCmd(VisualizeBSphereCmd* pCmd);
	void ReturnDrawTerrainCellCmd(VisualizeTerrainCellCmd* pCmd);

	void ReturnDrawLineCmd(VisualizeLineCmd* pCmd);
	void ReturnDrawPointCmd(VisualizePointCmd* pCmd);
	void ReturnDrawLineRayCmd(VisualizeLineRayCmd* pCmd);
	void ReturnDrawLineSegmentCmd(VisualizeLineSegmentCmd* pCmd);

private:
	GraphicsObject_Wireframe UnitBox;
	GraphicsObject_Wireframe UnitBSphere;

	using CmdPool = std::stack<VisualizeCommand*>;
	CmdPool OBBPool;
	CmdPool AABBPool;
	CmdPool BSpherePool;
	CmdPool TerrainCellPool;
	CmdPool LinePool;
	CmdPool PointPool;
	CmdPool LineRayPool;
	CmdPool LineSegmentPool;
};

#endif // VISUALIZECMDPOOL_H
