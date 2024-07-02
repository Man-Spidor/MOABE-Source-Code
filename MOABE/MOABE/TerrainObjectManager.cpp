#include "TerrainObjectManager.h"

#include "MOABETerrain.h"

TerrainObjectManager* TerrainObjectManager::instance = nullptr;

TerrainObjectManager::TerrainObjectManager() :
	savedTerrains(),
	DefaultPath(L"../Assets/Textures")
{
}

TerrainObjectManager::~TerrainObjectManager()
{
	for (auto MapPair : Instance().savedTerrains) {
		delete MapPair.second;
	}
}

void TerrainObjectManager::Load(const char* const key, LPCWSTR heightmapFile, float len, float maxheight, float ytrans, int RepeatU, int RepeatV)
{
	Instance().savedTerrains[key] = new MOABETerrain(heightmapFile, len, maxheight, ytrans, RepeatU, RepeatV);
}

MOABETerrain* TerrainObjectManager::Get(const char* const key)
{
	auto search = Instance().savedTerrains.begin();

	while (search != Instance().savedTerrains.end()) {
		if (strcmp(key, search->first) == 0) {
			return search->second;
		}
		search++;
	}

	if (search == Instance().savedTerrains.end()) {
		Trace::out("\n------->  [TerrainObjectManager] Key: '%s' Not Found  <-------\n\n", key);
		assert(false);
	}

	return nullptr;
}

void TerrainObjectManager::Unload()
{
	delete instance;
}

TerrainObjectManager& TerrainObjectManager::Instance()
{
	if (!instance)
		instance = new TerrainObjectManager();
	
	return *instance;
}
