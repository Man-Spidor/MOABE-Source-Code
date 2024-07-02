#include "TextureManager.h"

#include "SamplerManager.h"

#include <Texture.h>

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager() :
	savedTextures(),
	DefaultPath(L"../Assets/Textures/")
{
}

TextureManager& TextureManager::Instance()
{
	if (!instance) {
		instance = new TextureManager();
	}
	return *instance;
}

void TextureManager::SetDefaultPath(const wchar_t* const NewPath)
{
	Instance().DefaultPath = NewPath;
}

void TextureManager::Load(const char* const key, const wchar_t* const path)
{
	Instance().privLoad(key, path);
}

void TextureManager::Load(const char* const key, Sampler* pSampler, const wchar_t* const path)
{
	Instance().privLoad(key, pSampler, path);
}

Texture* TextureManager::Get(const char* const key)
{
	auto search = Instance().savedTextures.begin();

	while (search != Instance().savedTextures.end()) {
		if (strcmp(key, search->first) == 0) {
			return search->second;
		}
		search++;
	}

	if (search == Instance().savedTextures.end()) {
		Trace::out("\n------->  [TextureManager] Key: '%s' Not Found  <-------\n\n", key);
		assert(false);
	}

	return nullptr;
}

void TextureManager::Unload()
{
	for (auto MapPair : Instance().savedTextures) {
		delete MapPair.second;
	}
	delete instance;
}

void TextureManager::privLoad(const char* const key, const wchar_t* const path)
{
	size_t combinedPathSize = wcslen(this->DefaultPath.c_str()) + wcslen(path) + 2;

	wchar_t* combinedPath = new wchar_t[combinedPathSize];

	// Copy defaultPath to combinedPath
	wcscpy_s(combinedPath, combinedPathSize, this->DefaultPath.c_str());

	// Concatenate path to combinedPath
	wcscat_s(combinedPath, combinedPathSize, path);

	assert(combinedPath);

	Texture* pText = new Texture(combinedPath, SamplerManager::GetDefault());
	this->savedTextures[key] = pText;

	// Remember to free the allocated memory when done
	delete[] combinedPath;
}

void TextureManager::privLoad(const char* const key, Sampler* pSampler, const wchar_t* const path)
{
	size_t combinedPathSize = wcslen(this->DefaultPath.c_str()) + wcslen(path) + 2;

	wchar_t* combinedPath = new wchar_t[combinedPathSize];

	// Copy defaultPath to combinedPath
	wcscpy_s(combinedPath, combinedPathSize, this->DefaultPath.c_str());

	// Concatenate path to combinedPath
	wcscat_s(combinedPath, combinedPathSize, path);

	assert(combinedPath);

	Texture* pText = new Texture(combinedPath, pSampler);
	this->savedTextures[key] = pText;

	// Remember to free the allocated memory when done
	delete[] combinedPath;
}