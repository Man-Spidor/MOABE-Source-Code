#ifndef MOABESKYBOX_H
#define MOABESKYBOX_H

#include "SkyboxObject.h"

class Texture;
class GraphicsObject_Texture;

class MOABESkybox : public SkyboxObject
{
public:
	MOABESkybox() = delete;
	MOABESkybox(const MOABESkybox& other) = default;
	MOABESkybox& operator=(const MOABESkybox& other) = default;
	MOABESkybox(MOABESkybox&& other) = default;
	MOABESkybox& operator=(MOABESkybox&& other) = default;
	~MOABESkybox();

	MOABESkybox(Texture* pSkyTexture, const float scale);

	virtual void Render() override;

private:
	Matrix ScaleMatrix;
	SkyBox* pSkyModel;
	GraphicsObject_Texture* pSkyGO;
};

#endif // MOABESKYBOX_H
