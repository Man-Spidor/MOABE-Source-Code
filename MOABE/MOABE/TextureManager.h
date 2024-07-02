#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>

class Texture;
class Sampler;

/// The TextureManager class manages the loading and retrieval of texture objects.
///
/// This class provides functionality to load texture objects from files and retrieve them using unique keys.
/// It also allows unloading texture objects from memory when they are no longer needed.
class TextureManager
{
private:
	TextureManager();
	TextureManager(const TextureManager& other) = delete;
	TextureManager& operator=(const TextureManager& other) = delete;
	TextureManager(TextureManager&& other) = delete;
	TextureManager& operator=(TextureManager&& other) = delete;
	~TextureManager() = default;

public:
	/// Allows users to change the default path when loading Textures
	/// 
	/// @param NewPath The new default path
	static void SetDefaultPath(const wchar_t* const NewPath);

	/// Loads a texture object from the specified file path and associates it with the given key.
	///
	/// @param key The unique identifier for the texture object.
	/// @param path The file path to the texture file.
	static void Load(const char* const key, const wchar_t* const path);

	/// Loads a texture object from the specified file path and associates it with the given key, with the specified sampler.
	///
	/// @param key The unique identifier for the texture object.
	/// @param path The file path to the texture file.
	static void Load(const char* const key, Sampler* pSampler, const wchar_t* const path);

	/// Retrieves the texture object associated with the specified key.
	///
	/// @param key The unique identifier for the texture object.
	/// @return A pointer to the texture object if found, nullptr otherwise.
	static Texture* Get(const char* const key);

	/// Unloads all texture objects from memory.
	///
	/// This function releases all texture objects loaded into memory by the TextureManager.
	static void Unload();

private:
	/// Private function to load a texture object from the specified file path.
	/// 
	/// @param key The unique identifier for the texture object.
	/// @param path The file path to the texture file.
	void privLoad(const char* const key, const wchar_t* const path);

	/// Private function to load a texture object from the specified file path and sampler.
	/// 
	/// @param key The unique identifier for the texture object.
	/// @param path The file path to the texture file.
	void privLoad(const char* const key, Sampler* pSampler, const wchar_t* const path);


private:
	static TextureManager* instance; ///< Singleton instance of the TextureManager.
	static TextureManager& Instance(); ///< Singleton Accessor of the TextureManager.
	using TextureMap = std::map<const char* const, Texture*>;
	TextureMap savedTextures; ///< Map of keys to loaded textures.

	std::wstring DefaultPath; ///< Default path for loading textures.
};

#endif /// TEXTUREMANAGER_H
