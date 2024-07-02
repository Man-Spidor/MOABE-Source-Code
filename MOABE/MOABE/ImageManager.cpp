#include "ImageManager.h"

#include "Image.h"
#include "TextureManager.h"

ImageManager* ImageManager::instance = nullptr;

ImageManager::ImageManager() :
	savedImages()
{
}

ImageManager::~ImageManager()
{
	for (auto MapPair : Instance().savedImages) {
		// delete MapPair.second;
	}
}

void ImageManager::Load(const char* const key, const char* const textureKey, jAzulRect* pjAzulRect)
{
	Instance().privLoad(key, textureKey, pjAzulRect);
}

void ImageManager::Load(const char* const key, Texture* pText, jAzulRect* pjAzulRect)
{
	Instance().privLoad(key, pText, pjAzulRect);
}

Image* ImageManager::Get(const char* const key)
{
	auto search = Instance().savedImages.begin();

	while (search != Instance().savedImages.end()) {
		if (strcmp(key, search->first) == 0) {
			return search->second;
		}
		search++;
	}

	if (search == Instance().savedImages.end()) {
		Trace::out("\n------->  [ImageManager] Key: '%s' Not Found  <-------\n\n", key);
		assert(false);
	}

	return nullptr;
}

void ImageManager::Unload()
{
	delete instance;
}

void ImageManager::privLoad(const char* const key, const char* const textureKey, jAzulRect* pjAzulRect)
{
	Image* pImage = new Image(TextureManager::Get(textureKey), pjAzulRect);
	this->savedImages[key] = pImage;
}

void ImageManager::privLoad(const char* const key, Texture* pText, jAzulRect* pjAzulRect)
{
	Image* pImage = new Image(pText, pjAzulRect);
	this->savedImages[key] = pImage;
}

ImageManager& ImageManager::Instance()
{
	if (!instance)
		instance = new ImageManager();

	return *instance;
}
