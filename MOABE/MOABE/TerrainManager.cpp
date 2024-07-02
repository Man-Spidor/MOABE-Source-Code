#include "TerrainManager.h"

#include "MOABETerrain.h"

TerrainManager::TerrainManager() :
	NullTerrain(),
	pCurrTerrain(&this->NullTerrain)
{
}

void TerrainManager::RenderTerrain()
{
	pCurrTerrain->Render();
}

void TerrainManager::SwitchTerrain(MOABETerrain* pNextTerrain)
{
	this->pCurrTerrain = pNextTerrain;
}

TerrainObject& TerrainManager::GetTerrainObject() const
{
	return *this->pCurrTerrain;
}

const TerrainModel& TerrainManager::GetCurrTerrain() const
{
	return *this->pCurrTerrain->GetTerrainModel();
}
