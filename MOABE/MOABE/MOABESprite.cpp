#include "MOABESprite.h"
#include "AssetManagers.h"

#include "Image.h"
#include "Texture.h"
#include "jAzulRect.h"
#include "GraphicsObject_Sprite.h"

MOABESprite::~MOABESprite()
{
	delete this->goSprite;
	delete this->pImage;
	delete pRect;
}

MOABESprite::MOABESprite(Image* _pImage) :
	pRect(new jAzulRect(0.0f, 0.0f, static_cast<float>(_pImage->pRect->w), static_cast<float>(_pImage->pRect->h))),
	pImage(_pImage),
	goSprite(new GraphicsObject_Sprite(ModelManager::Get("UnitSquare"), this->pImage, this->pRect)),
	angle(0.0f),
	posX(0.0f),
	posY(0.0f),
	CenterX(0.0f),
	CenterY(0.0f),
	ScaleX(1.0f),
	ScaleY(1.0f)
{
	assert(this->pRect);
	assert(this->pImage);
}

MOABESprite::MOABESprite(const char* const SpriteName) :
	pRect(nullptr),
	pImage(nullptr),
	goSprite(nullptr),
	angle(0.0f),
	posX(0.0f),
	posY(0.0f),
	CenterX(0.0f),
	CenterY(0.0f),
	ScaleX(1.0f),
	ScaleY(1.0f)
{
	Texture* pText = TextureManager::Get(SpriteName);
	this->pRect = new jAzulRect(0.0f, 0.0f, (float)pText->getWidth(), (float)pText->getHeight());
	this->pImage = new Image();
	this->pImage->Set(pText, new jAzulRect(0.0f, 0.0f, (float)pText->getWidth(), (float)pText->getHeight()));

	this->goSprite = new GraphicsObject_Sprite(ModelManager::Get("UnitSquare"), pImage, pRect);
	this->goSprite->SetWorld(Matrix(IDENTITY));
}

const float MOABESprite::GetAngle() const
{
	return this->angle;
}

void MOABESprite::SetAngle(const float _angle)
{
	this->angle = _angle;
}

const float MOABESprite::GetWidth() const
{
	return this->pRect->w;
}

const float MOABESprite::GetHeight() const
{
	return this->pRect->h;
}

void MOABESprite::SetCenter(const float _CenterX, const float _CenterY)
{
	this->CenterX = _CenterX;
	this->CenterY = _CenterY;
}

void MOABESprite::SetScaleFactor(const float _ScaleX, const float _ScaleY)
{
	this->ScaleX = _ScaleX;
	this->ScaleY = _ScaleY;
}

void MOABESprite::SetScalePixel(const float width, const float height)
{
	this->ScaleX = width / this->pImage->pRect->w;
	this->ScaleY = height / this->pImage->pRect->h;
}

void MOABESprite::SetPosition(const float x, const float y)
{
	this->posX = x;
	this->posY = y;
}

void MOABESprite::Render() const
{
	Matrix world = Matrix(TRANS, -this->CenterX, -this->CenterY, 0.0f);
	Matrix s = Matrix(SCALE, this->ScaleX, this->ScaleY, 0.0f);
	Matrix t = Matrix(TRANS, this->pRect->x + this->posX, this->pRect->y - this->posY, 0.1f);
	Matrix r = Matrix(ROT_Z, this->angle);
	
	world *= s * r * t;
	
	this->goSprite->SetWorld(world);
	this->goSprite->Render();
}
