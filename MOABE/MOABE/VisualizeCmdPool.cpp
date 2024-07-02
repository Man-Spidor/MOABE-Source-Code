#include "VisualizeCmdPool.h"

#include "VisualizeOBBCmd.h"
#include "VisualizeAABBCmd.h"
#include "VisualizeBSphereCmd.h"
#include "VisualizeTerrainCellCmd.h"

#include "VisualizeLineCmd.h"
#include "VisualizePointCmd.h"
#include "VisualizeLineRayCmd.h"
#include "VisualizeLineSegmentCmd.h"

#include "Colors.h"
#include <GraphicsObject_Wireframe.h>

#include "AssetManagers.h"

VisualizeCmdPool::VisualizeCmdPool(Vect& color) :
	UnitBox(ModelManager::Get("UnitBox")),
	UnitBSphere(ModelManager::Get("BSphere")),
	AABBPool(),
	BSpherePool()
{
	this->UnitBox.SetColor(color);
	this->UnitBSphere.SetColor(color);
}

VisualizeCmdPool::~VisualizeCmdPool()
{
	while (!this->OBBPool.empty()) {
		delete this->OBBPool.top();
		this->OBBPool.pop();
	}

	while(!this->AABBPool.empty()) {
		delete this->AABBPool.top();
		this->AABBPool.pop();
	}

	while (!this->BSpherePool.empty()) {
		delete this->BSpherePool.top();
		this->BSpherePool.pop();
	}

	while (!this->PointPool.empty()) {
		delete this->PointPool.top();
		this->PointPool.pop();
	}

	while (!this->LinePool.empty()) {
		delete this->LinePool.top();
		this->LinePool.pop();
	}

	while (!this->LineSegmentPool.empty()) {
		delete this->LineSegmentPool.top();
		this->LineSegmentPool.pop();
	}

	while (!this->LineRayPool.empty()) {
		delete this->LineRayPool.top();
		this->LineRayPool.pop();
	}

	while (!this->TerrainCellPool.empty()) {
		delete this->TerrainCellPool.top();
		this->TerrainCellPool.pop();
	}
}

VisualizeOBBCmd* VisualizeCmdPool::GetDrawOBBCmd()
{
	VisualizeOBBCmd* pOBBCmd;
	if (this->OBBPool.empty()) {
		pOBBCmd = new VisualizeOBBCmd(this->UnitBox);
	}
	else {
		pOBBCmd = static_cast<VisualizeOBBCmd*>(this->OBBPool.top());
		this->OBBPool.pop();
	}

	return pOBBCmd;
}

VisualizeAABBCmd* VisualizeCmdPool::GetDrawAABBCmd()
{
	VisualizeAABBCmd* pAABBCmd;
	if (this->AABBPool.empty()) {
		 pAABBCmd = new VisualizeAABBCmd(this->UnitBox);
	}
	else {
		pAABBCmd = static_cast<VisualizeAABBCmd*>(this->AABBPool.top());
		this->AABBPool.pop();
	}

	return pAABBCmd;
}

VisualizeBSphereCmd* VisualizeCmdPool::GetDrawBSphere()
{
	VisualizeBSphereCmd* pBsphereCmd;
	if (this->BSpherePool.empty()) {
		pBsphereCmd = new VisualizeBSphereCmd(this->UnitBSphere);
	}
	else {
		pBsphereCmd = static_cast<VisualizeBSphereCmd*>(this->BSpherePool.top());
		this->BSpherePool.pop();
	}

	return pBsphereCmd;
}

VisualizeTerrainCellCmd* VisualizeCmdPool::GetDrawTerrainCellCmd()
{
	VisualizeTerrainCellCmd* pTerrainCellCmd;
	if (this->TerrainCellPool.empty()) {
		pTerrainCellCmd = new VisualizeTerrainCellCmd(this->UnitBox);
	}
	else {
		pTerrainCellCmd = static_cast<VisualizeTerrainCellCmd*>(this->TerrainCellPool.top());
		this->TerrainCellPool.pop();
	}

	return pTerrainCellCmd;
}

VisualizeLineCmd* VisualizeCmdPool::GetDrawLineMarkerCmd()
{
	VisualizeLineCmd* pCmd;
	if (this->LinePool.empty()) {
		pCmd = new VisualizeLineCmd(this->UnitBox);
	}
	else {
		pCmd = static_cast<VisualizeLineCmd*>(this->LinePool.top());
		this->LinePool.pop();
	}

	return pCmd;
}

VisualizePointCmd* VisualizeCmdPool::GetDrawPointMarkerCmd()
{
	VisualizePointCmd* pCmd;
	if (this->PointPool.empty()) {
		pCmd = new VisualizePointCmd(this->UnitBox);
	}
	else {
		pCmd = static_cast<VisualizePointCmd*>(this->PointPool.top());
		this->PointPool.pop();
	}

	return pCmd;
}

VisualizeLineRayCmd* VisualizeCmdPool::GetDrawLineRayMarkerCmd()
{
	VisualizeLineRayCmd* pCmd;
	if (this->LineRayPool.empty()) {
		pCmd = new VisualizeLineRayCmd(this->UnitBox);
	}
	else {
		pCmd = static_cast<VisualizeLineRayCmd*>(this->LineRayPool.top());
		this->LineRayPool.pop();
	}

	return pCmd;
}

VisualizeLineSegmentCmd* VisualizeCmdPool::GetDrawLineSegmentMarkerCmd()
{
	VisualizeLineSegmentCmd* pCmd;
	if (this->LineSegmentPool.empty()) {
		pCmd = new VisualizeLineSegmentCmd(this->UnitBox);
	}
	else {
		pCmd = static_cast<VisualizeLineSegmentCmd*>(this->LineSegmentPool.top());
		this->LineSegmentPool.pop();
	}

	return pCmd;
}

void VisualizeCmdPool::ReturnDrawOBBCmd(VisualizeOBBCmd* pCmd)
{
	this->OBBPool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawAABBCmd(VisualizeAABBCmd* pCmd)
{
	this->AABBPool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawBSphereCmd(VisualizeBSphereCmd* pCmd)
{
	this->BSpherePool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawTerrainCellCmd(VisualizeTerrainCellCmd* pCmd)
{
	this->TerrainCellPool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawLineCmd(VisualizeLineCmd* pCmd)
{
	this->LinePool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawPointCmd(VisualizePointCmd* pCmd)
{
	this->PointPool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawLineRayCmd(VisualizeLineRayCmd* pCmd)
{
	this->LineRayPool.push(pCmd);
}

void VisualizeCmdPool::ReturnDrawLineSegmentCmd(VisualizeLineSegmentCmd* pCmd)
{
	this->LineSegmentPool.push(pCmd);
}
