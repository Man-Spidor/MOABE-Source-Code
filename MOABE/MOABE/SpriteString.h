#ifndef SPRITESTRING_H
#define SPRITESTRING_H

#include <vector>
#include <string>

class SpriteFont;
class MOABESprite;

/// Represents a string of sprites using a specified font.
/// ### Usage Example:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// // Loading a SpriteFont
/// void SomeFunc() {
/// 	FontManager::SetDefaultPath("../Assets/Fonts/");
///     FontManager::LoadFont("Arial30pt");
/// };
/// 
/// // Creating a 
/// void MySpriteString::MySpriteString() {
///     this->mySpriteString = new SpriteString(FontManager::Get("Arial30pt"), "This is a test :)");
/// }
/// 
/// virtual void Draw2D() override {
///     this->mySpriteString->Render();
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
/// @see FontManager
/// @see MOABESprite
/// @see SpriteFont
/// 
/// @note The SpriteString class only handles the special characters '\n' and '\t'. Anything else will need to be handled by the font 
class SpriteString
{
    using Glyph = MOABESprite;
    using GlyphCollection = std::vector<Glyph*>;

public:
    /// Default constructor.
    SpriteString();

    /// Copy constructor.
    SpriteString(const SpriteString& other) = default;

    /// Copy assignment operator.
    SpriteString& operator=(const SpriteString& other) = default;

    /// Move constructor.
    SpriteString(SpriteString&& other) = default;

    /// Move assignment operator.
    SpriteString& operator=(SpriteString&& other) = default;

    /// Destructor.
    ~SpriteString() = default;

    /// Constructor that initializes the string with a font and a std::string.
    ///
    /// @param pFont Pointer to the font used to create the string.
    /// @param pString std::string representing the text.
    /// @param x The x-coordinate of the initial position.
    /// @param y The y-coordinate of the initial position.
    SpriteString(SpriteFont* pFont, const std::string& pString, float x, float y);

    /// Constructor that initializes the string with a font and a std::string.
    ///
    /// @param pFont Pointer to the font used to create the string.
    /// @param pString std::string representing the text.
    SpriteString(SpriteFont* pFont, const std::string& pString);

    /// Constructor that initializes the string with a font and a no string.
    ///
    /// @param pFont Pointer to the font used to create the string.
    SpriteString(SpriteFont* pFont);

    /// Set the font of the string.
    ///
    /// @param pFont Pointer to the new font.
    void SetFont(SpriteFont* pFont);

    /// Set the string.
    ///
    /// @param pString std::string representing the new text.
    void SetString(const std::string& pString);

    /// Set the position of the string.
    ///
    /// @param x The x-coordinate of the new position.
    /// @param y The y-coordinate of the new position.
    void SetPosition(float x, float y);

    /// Render the string.
    void Render();

private:
    /// Initialize the glyphs based on the string and font.
    ///
    /// @param pFont Pointer to the font.
    /// @param pString std::string representing the text.
    void privInitializeGlyphs(SpriteFont* pFont, const std::string& pString);

private:
    std::string str;
    GlyphCollection glyphs;
    SpriteFont* font;
    float width;
    float height;
    float posX;
    float posY;
};

#endif // SPRITESTRING_H
