#include "SpriteString.h"

#include "SpriteFont.h"
#include "MOABESprite.h"
#include "SceneManager.h"

SpriteString::SpriteString() :
	str(),
	glyphs(),
	font(nullptr),
	width(0.0f),
	height(0.0f),
	posX(0.0f),
	posY(0.0f)
{
}

SpriteString::SpriteString(SpriteFont* pFont) :
	str(),
	glyphs(),
	font(pFont),
	width(0.0f),
	height(0.0f),
	posX(0.0f),
	posY(0.0f)
{
}

SpriteString::SpriteString(SpriteFont* pFont, const std::string& pString) :
	str(pString),
	glyphs(),
	font(pFont),
	width(0.0f),
	height(0.0f),
	posX(0.0f),
	posY(0.0f)
{
	this->privInitializeGlyphs(pFont, pString);
}

SpriteString::SpriteString(SpriteFont* pFont, const std::string& pString, float x, float y) :
	str(pString),
	glyphs(),
	font(pFont),
	width(0.0f),
	height(0.0f),
	posX(x),
	posY(y)
{
	this->privInitializeGlyphs(pFont, pString);
}

void SpriteString::SetFont(SpriteFont* pFont)
{
	this->font = pFont;
	this->privInitializeGlyphs(pFont, this->str);
}

void SpriteString::SetString(const std::string& pString)
{
	assert("Font Not Set!!" && this->font);

	this->str = pString;
	this->privInitializeGlyphs(this->font, pString);
}

void SpriteString::SetPosition(const float x, const float y)
{
	this->posX = x;
	this->posY = y;
}

void SpriteString::Render()
{
	assert("Font Not Set!!" && this->font);
	
	float nextX = this->posX;
	float nextY = this->posY;
	int i = 0;
	for (Glyph* pGlyph : this->glyphs) {
		if (str[i] == '\n') {
			nextX = this->posX;
			nextY += this->font->GetNewLineSize();
		}
		else if (str[i] == '\t')
			nextX = this->font->GetTabSize();

		else {
			pGlyph->SetPosition(nextX, nextY);
			pGlyph->Render();
			nextX += pGlyph->GetWidth() * 2.0f;
		}

		i++;
	}
}

void SpriteString::privInitializeGlyphs(SpriteFont* pFont, const std::string& pString)
{
	glyphs.clear();
	width = 0.0f;
	height = 0.0f;
	for (char c : pString) {
		Glyph* glyph = pFont->GetGlyph(c);
		glyphs.push_back(glyph);

		if (c == '\n') 
			height += pFont->GetNewLineSize();

		else if (c == '\t')
			width += pFont->GetTabSize();
		
		else 
			width += glyph->GetWidth();
	}
}
