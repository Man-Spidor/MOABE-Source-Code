#include "SkyboxObjectManager.h"

#include "MOABESkybox.h"
#include <TextureManager.h>

SkyboxObjectManager* SkyboxObjectManager::instance = nullptr;

SkyboxObjectManager::SkyboxObjectManager() :
	savedSkyboxes(),
	DefaultPath(L"../Assets/Textures")
{
}

SkyboxObjectManager::~SkyboxObjectManager()
{
	for (auto MapPair : Instance().savedSkyboxes) {
		delete MapPair.second;
	}
}

void SkyboxObjectManager::Load(const char* const key, const float scale)
{
	Instance().savedSkyboxes[key] = new MOABESkybox(TextureManager::Get(key), scale);
}

MOABESkybox* SkyboxObjectManager::Get(const char* const key)
{
	auto search = Instance().savedSkyboxes.begin();

	while (search != Instance().savedSkyboxes.end()) {
		if (strcmp(key, search->first) == 0) {
			return search->second;
		}
		search++;
	}

	if (search == Instance().savedSkyboxes.end()) {
		Trace::out("\n------->  [SkyboxObjectManager] Key: '%s' Not Found  <-------\n\n", key);
		assert(false);
	}

	return nullptr;
}

void SkyboxObjectManager::Unload()
{
	delete instance;
}

SkyboxObjectManager& SkyboxObjectManager::Instance()
{
	if (!instance)
		instance = new SkyboxObjectManager();

	return *instance;
}
