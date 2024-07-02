#include "FontManager.h"

FontManager* FontManager::instance = nullptr;

FontManager::FontManager() :
	DefaultPath("../Assets/Fonts/"),
	savedFonts()
{
}

FontManager::~FontManager()
{
	for (auto MapPair : Instance().savedFonts) {
		delete MapPair.second;
	}
}

void FontManager::SetDefaultPath(const char* const NewPath)
{
	Instance().DefaultPath = NewPath;
}

void FontManager::LoadFont(const char* const key, const char* const path)
{
	Instance().privLoad(key, path);
}

SpriteFont* FontManager::Get(const char* const key)
{
	auto search = Instance().savedFonts.begin();

	while (search != Instance().savedFonts.end()) {
		if (strcmp(key, search->first) == 0) {
			return search->second;
		}
		search++;
	}

	if (search == Instance().savedFonts.end()) {
		Trace::out("\n------->  [FontManager] Key: '%s' Not Found  <-------\n\n", key);
		assert(false);
	}

	return nullptr;
}

void FontManager::Unload()
{
	delete instance;
}

void FontManager::privLoad(const char* const key, const char* const path)
{
	size_t combinedPathSize = strlen(this->DefaultPath.c_str()) + strlen(path) + 1;

	char* combinedPath = new char[combinedPathSize];

	// Copy defaultPath to combinedPath
	strcpy_s(combinedPath, combinedPathSize, this->DefaultPath.c_str());

	// Concatenate path to combinedPath
	strcat_s(combinedPath, combinedPathSize, path);

	assert(combinedPath);

	SpriteFont* newFont = new SpriteFont(combinedPath);
	this->savedFonts[key] = newFont;

	// Remember to free the allocated memory when done
	delete[] combinedPath;
}

FontManager& FontManager::Instance()
{
	if (!instance)
		instance = new FontManager();

	return *instance;
}
