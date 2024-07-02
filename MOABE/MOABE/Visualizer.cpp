#include "Visualizer.h"

#include "Colors.h"
#include "VisualizeOBBCmd.h"
#include "VisualizeAABBCmd.h"
#include "VisualizeLineCmd.h"
#include "VisualizeBSphereCmd.h"
#include "VisualizeTerrainCellCmd.h"
#include "VisualizerStrategies.h"

#include "VolumeAttorney.h"

#include "AssetManagers.h"
#include "SceneManager.h"
#include "VisualizePointCmd.h"
#include "VisualizeLineRayCmd.h"
#include "VisualizeLineSegmentCmd.h"

// TEMPORARY FOR NOW
#include "CollidableGroup.h"
#include <GameObjectAttorney.h>
// TEMPORARY FOR NOW

Visualizer* Visualizer::instance = nullptr;
Vect Visualizer::DEFAULT_COLOR = Colors::GreenYellow;

const VisualizerStrategy* Visualizer::myStrategy = &VisualizerStrategies::VisualizeDefault;

Visualizer::Visualizer() :
	cmdBroker(),
	cmdPool(DEFAULT_COLOR),
	colDrawList()
{
}

void Visualizer::Draw()
{
	myStrategy->Draw();
}

void Visualizer::VisualizeAll()
{
	Instance().cmdBroker.ProcessCommands();
}

void Visualizer::VisualizeAllCollidable()
{
	// Get all the registered collidables from the CollisionManager

	// Create commands for all those collidables and push them to cmdbroker

	// Process commands
	Instance().cmdBroker.ProcessCommands();
}

void Visualizer::Delete()
{
	delete instance;
}

void Visualizer::Activate(VisualizeMode mode)
{
	switch (mode)
	{
		case VisualizeMode::DRAW_DEFAULT:
			myStrategy = &VisualizerStrategies::VisualizeDrawDefault;
			break;
		case VisualizeMode::DRAW_MARKERS:
			myStrategy = &VisualizerStrategies::VisualizeMarkers;
			break;
		case VisualizeMode::DRAW_COLLIDABLES:
			myStrategy = &VisualizerStrategies::VisualizeCollidable;
			break;
		case VisualizeMode::DRAW_NONE:
			myStrategy = &VisualizerStrategies::VisualizeDefault;
			break;
	}
}

void Visualizer::Deactivate()
{
	myStrategy = &VisualizerStrategies::VisualizeDefault;
}

void Visualizer::ShowVolume(const CollisionVolume& ColVol)
{
	VolumeAttorney::debug(ColVol);
}

void Visualizer::ShowVolume(const CollisionVolume& ColVol, const Vect& color)
{
	VolumeAttorney::debug(ColVol, color);
}

void Visualizer::ShowBSphere(const CV_BSphere& BSphere)
{
	myStrategy->ShowBSphere(BSphere, DEFAULT_COLOR);
}

void Visualizer::ShowBSphere(const CV_BSphere& BSphere, const Vect& color)
{
	myStrategy->ShowBSphere(BSphere, color);
}

void Visualizer::ShowAABB(const CV_AABB& AABB)
{
	myStrategy->ShowAABB(AABB, DEFAULT_COLOR);
}

void Visualizer::ShowAABB(const CV_AABB& AABB, const Vect& color)
{
	myStrategy->ShowAABB(AABB, color);
}

void Visualizer::ShowOBB(const CV_OBB& OBB)
{
	myStrategy->ShowOBB(OBB, Visualizer::DEFAULT_COLOR);
}
\
void Visualizer::ShowOBB(const CV_OBB& OBB, const Vect& color)
{
	myStrategy->ShowOBB(OBB, color);
}

void Visualizer::ShowTerrainCell(const TerrainCell& Cell)
{
	myStrategy->ShowTerrainCollision(Cell, DEFAULT_COLOR);
}

void Visualizer::ShowTerrainCell(const TerrainCell& Cell, const Vect& Color)
{
	myStrategy->ShowTerrainCollision(Cell, Color);
}

void Visualizer::ShowMarkerPoint(const Vect& point)
{
	myStrategy->ShowMarkerPoint(point, DEFAULT_COLOR);
}

void Visualizer::ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint)
{
	myStrategy->ShowMarkerLineSegment(startPoint, endPoint, DEFAULT_COLOR);
}

void Visualizer::ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos)
{
	myStrategy->ShowMarkerLineRay(startPoint, targetPos, DEFAULT_COLOR);
}

void Visualizer::ShowMarkerLine(const Vect& startPoint, const Vect& targetPos)
{
	myStrategy->ShowMarkerLine(startPoint, targetPos, DEFAULT_COLOR);
}

void Visualizer::ShowMarkerPoint(const Vect& point, const Vect& color)
{
	myStrategy->ShowMarkerPoint(point, color);
}

void Visualizer::ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color)
{
	myStrategy->ShowMarkerLineSegment(startPoint, endPoint, color);
}

void Visualizer::ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color)
{
	myStrategy->ShowMarkerLineRay(startPoint, targetPos, color);
}

void Visualizer::ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color)
{
	myStrategy->ShowMarkerLine(startPoint, targetPos, color);
}

void Visualizer::ShowCollidableGroupList(const CollidableGroupCollection& ColGroupCollection)
{
	myStrategy->ShowCollidableGroupList(ColGroupCollection);
}

void Visualizer::SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol)
{
	myStrategy->SetLowestTestVolume(pCol, ColVol);
}

void Visualizer::SetLowestTestVolume(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color)
{
	myStrategy->SetLowestTestVolume(pCol, ColVol, color);
}

void Visualizer::pushBSphereCmd(const CV_BSphere& BSphere, const Vect& color)
{
	VisualizeBSphereCmd* pCmd = Instance().cmdPool.GetDrawBSphere();
	pCmd->SetData(&BSphere, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushAABBCmd(const CV_AABB& AABB, const Vect& color)
{
	VisualizeAABBCmd* pCmd = Instance().cmdPool.GetDrawAABBCmd();
	pCmd->SetData(&AABB, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushOBBCmd(const CV_OBB& OBB, const Vect& color)
{
	VisualizeOBBCmd* pCmd = Instance().cmdPool.GetDrawOBBCmd();
	pCmd->SetData(&OBB, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushTerrainCellCmd(const TerrainCell& Cell, const Vect& color)
{
	VisualizeTerrainCellCmd* pCmd = Instance().cmdPool.GetDrawTerrainCellCmd();
	pCmd->SetData(&Cell, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushPointCmd(const Vect& point, const Vect& color)
{
	VisualizePointCmd* pCmd = Instance().cmdPool.GetDrawPointMarkerCmd();
	pCmd->SetData(point, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushLineCmd(const Vect& startPoint, const Vect& targetPos, const Vect& color)
{
	VisualizeLineCmd* pCmd = Instance().cmdPool.GetDrawLineMarkerCmd();
	pCmd->SetData(startPoint, targetPos, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushLineRayCmd(const Vect& startPoint, const Vect& targetPos, const Vect& color)
{
	VisualizeLineRayCmd* pCmd = Instance().cmdPool.GetDrawLineRayMarkerCmd();
	pCmd->SetData(startPoint, targetPos, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::pushLineSegmentCmd(const Vect& startPoint, const Vect& endPoint, const Vect& color)
{
	VisualizeLineSegmentCmd* pCmd = Instance().cmdPool.GetDrawLineSegmentMarkerCmd();
	pCmd->SetData(startPoint, endPoint, color);
	Instance().cmdBroker.PushCommand(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeBSphereCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawBSphereCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeAABBCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawAABBCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeOBBCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawOBBCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeTerrainCellCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawTerrainCellCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeLineCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawLineCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizePointCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawPointCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeLineRayCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawLineRayCmd(pCmd);
}

void Visualizer::ReturnDrawCmd(VisualizeLineSegmentCmd* pCmd)
{
	Instance().cmdPool.ReturnDrawLineSegmentCmd(pCmd);
}

void Visualizer::setLowestTestVolumeStrategy(const Collidable* pCol, const CollisionVolume* ColVol)
{
	static CollidableDrawList& colDrawList = Instance().colDrawList;
	auto it = colDrawList.find(pCol);

	if (it == colDrawList.end()) {
		VolumeDrawPair volDrawPair = VolumeDrawPair(ColVol, DEFAULT_COLOR);
		Instance().colDrawList.insert(std::pair<const Collidable*, VolumeDrawPair>(pCol, volDrawPair));
	}
	else {
		VolumeDrawPair& volDrawPair = it->second;

		if (volDrawPair.first != &GameObjectAttorney::Collision::GetColVol(pCol)) {
			volDrawPair.first = ColVol;
		}
	}
}

void Visualizer::setLowestTestVolumeStrategy(const Collidable* pCol, const CollisionVolume* ColVol, const Vect& color)
{
	static CollidableDrawList& colDrawList = Instance().colDrawList;
	auto it = colDrawList.find(pCol);

	if (it == colDrawList.end()) {
		VolumeDrawPair volDrawPair = VolumeDrawPair(ColVol, color);
		Instance().colDrawList.insert(std::pair<const Collidable*, VolumeDrawPair>(pCol, volDrawPair));
	}
	else {
		VolumeDrawPair& volDrawPair = it->second;

		if (volDrawPair.first != &GameObjectAttorney::Collision::GetColVol(pCol)) {
			volDrawPair.first = ColVol;
			volDrawPair.second = color;
		}
	}
}

void Visualizer::showCollisions()
{
	static CollidableDrawList& colDrawList = Instance().colDrawList;

	for (const auto& pair : colDrawList) {
		const auto& ColVol = pair.second.first;
		const auto& Color = pair.second.second;

		ShowVolume(*ColVol, Color);
	}
		
	colDrawList.clear();
}

void Visualizer::showCollidables(const CollidableGroupCollection& ColGroupCollection)
{
	for (auto ColGroup : ColGroupCollection) {
		if (ColGroup != nullptr) {
			auto ColCollection = ColGroup->GetColliderCollection();
			for (auto Col : ColCollection) {
				Col->DrawCollidable();
			}
		}
	}
}

Visualizer& Visualizer::Instance()
{
	if (!instance) {
		instance = new Visualizer();
	}

	return *instance;
}
