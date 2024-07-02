#ifndef SPRITEFONT_H
#define SPRITEFONT_H

#include <map>
#include <string>
#include <xmllite.h>

class Texture;
class MOABESprite;

/// Represents a font created from a tga font texture and xml font stat sheet.
/// 
/// Two methods of creating and using fonts.
/// 
/// 1.) SpriteFont 2 https://web.archive.org/web/20140812183126/http://www.nubik.com/SpriteFont/SpriteFont2Installer.zip 
/// 2.) Use this Bitmap Font Generator: http://www.angelcode.com/products/bmfont/
///         Create your font tga and make sure to specify the output as .xml
///         Rename the .fnt output to .xml
///         Use the XML Formatter String Converter
/// 
/// All fonts can be created on a per instance basis or be pre loaded using the FontManager.
/// 
/// ### Usage Example:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// // Loading a SpriteFont
/// void SomeFunc() {
/// 	FontManager::SetDefaultPath("../Assets/Fonts/");
///     FontManager::LoadFont("Arial30pt");
/// };
/// 
/// // Using a SpriteFont
/// void MySpriteString::MySpriteString() {
///     this->mySpriteString = new SpriteString(FontManager::Get("Arial30pt"), "This is a test :)");
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
/// @see FontManager
/// @see SpriteString
/// @see MOABESprite
/// 
/// @note The SpriteFont class implicitly assumes that the tga and xml files have identical names.
class SpriteFont
{
public:
    /// Alias for the key type used in the font map.
    using Key = int;

    /// Alias for the glyph type, which is a sprite.
    using Glyph = MOABESprite;

    using FontMap = std::map<Key, Glyph*>;

public:
    /// Constructor that initializes the font from an XML file.
    /// 
    /// @param path The path to the XML file describing the font
    SpriteFont(std::string path);

    /// Default constructor (deleted).
    SpriteFont() = delete;

    /// Copy constructor (deleted).
    SpriteFont(const SpriteFont&) = delete;

    /// Copy assignment operator (deleted).
    SpriteFont& operator=(const SpriteFont&) = delete;

    /// Destructor.
    ~SpriteFont();

    /// Get the glyph associated with a character.
    /// 
    /// @param c The character to get the glyph for
    /// @return Pointer to the glyph representing the character
    Glyph* GetGlyph(char c);

    /// Get the size of a \t character in this font
    /// 
    /// uses 2 * the width of the 'A' character. Keep this in mind when your picking your fonts
    /// 
    /// @return The size of of \t char
    const float GetTabSize() const;

    /// Get the size of a \n character in this font
    /// 
    /// uses the height of the 'A' character. Keep this in mind when your picking your fonts
    /// 
    /// @return The size of of \n char
    const float GetNewLineSize() const;

private:
    /// Parse the XML file to build the font collection.
    /// 
    /// @param filename The path to the XML file
    void XMLtoCollection(std::string filename);

    /// Tool: Reads and converts an XML attribute into an int.
    /// 
    /// @param pReader Pointer to the XML reader
    /// @param out Reference to the int to store the converted value
    void ElementTextToInt(IXmlReader* pReader, int& out);

private:
    std::string Name; ///< The name of the font
    FontMap fontmap; ///< Map of character keys to glyphs
    Texture* FontTexture; ///< The texture containing the font's glyphs
    float tabSize;
    float newLineSize;
};

#endif // SPRITEFONT_H
