#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "SpriteFont.h"

class Texture;

/// This singleton class provides functionality to load fonts from 
/// tga textures and an accompanying .xml file containing the settings. 
/// Loaded fonts can be retrieved by their unique keys, and all 
/// 
/// All loaded SpriteFonts are deleted at the end of the game loop.
/// 
/// Example usage of the ModelManager class:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// void MOABE::LoadAllContent() { 
///     // The Path To The Font Is Constructed in the SpriteFont class, so make sure the texture and xml files are placed in the Font folder
///     FontManager::Load("DefaultFont", "ExampleFont");
/// }
/// 
/// // ...
/// 
/// SomeGameObject() {
///     this->spriteString = new SpriteString(FontManager::Get("DefaultFont");
/// }
/// 
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class FontManager
{
private:
    FontManager();
    FontManager(const FontManager& other) = delete;
    FontManager& operator=(const FontManager& other) = delete;
    FontManager(FontManager&& other) = delete;
    FontManager& operator=(FontManager&& other) = delete;
    ~FontManager();

public:
    /// Allows users to change the default path when loading Fonts
    /// 
    /// @param NewPath The new default path
    static void SetDefaultPath(const char* const NewPath);

    /// Load a font from the specified path and associate it with the given key.
    /// 
    /// @param key The key to associate with the loaded font.
    /// @param path The path to the font file.
    static void LoadFont(const char* const key, const char* const path);

    /// Retrieve a font associated with the given key.
    /// 
    /// @param key The key associated with the desired font.
    /// @return A pointer to the SpriteFont associated with the key.
    static SpriteFont* Get(const char* const key);

    /// Unload all loaded fonts.
    static void Unload();

private:
    /// Load a font from the specified path and associate it with the given key (private implementation).
    /// 
    /// @param key The key to associate with the loaded font.
    /// @param path The path to the font file.
    void privLoad(const char* const key, const char* const path);

    /// Retrieve the singleton instance of the FontManager.
    /// 
    /// @return A reference to the singleton instance.
    static FontManager& Instance();

private:
    static FontManager* instance; ///< Singleton instance of the FontManager.
    using FontMap = std::map<const char* const, SpriteFont*>;
    using FontTextureMap = std::map<const char* const, Texture*>;

    std::string DefaultPath; ///< The default path for loading fonts.
    FontMap savedFonts; ///< Map of keys to loaded fonts
};

#endif // FONTMANAGER_H