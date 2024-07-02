#include "MOABESkybox.h"

#include "ModelManager.h"

#include <SceneManager.h>
#include <GraphicsObject_Texture.h>

MOABESkybox::~MOABESkybox()
{
	delete this->pSkyGO;
	delete this->pSkyModel;
}

MOABESkybox::MOABESkybox(Texture* pTexture, const float scale) :
	ScaleMatrix(Matrix(SCALE, scale, scale, scale)),
	pSkyModel(new SkyBox(0.5f)),
	pSkyGO(nullptr)
{
	assert(this->pSkyModel);

	this->pSkyGO = new GraphicsObject_Texture(this->pSkyModel);
	this->pSkyGO->SetWorld(this->ScaleMatrix);
	this->pSkyGO->SetTexture(pTexture);
}

void MOABESkybox::Render()
{
	Vect CamPos;
	SceneManager::GetCurrScene().GetMainCamera().getPos(CamPos);

	this->pSkyGO->SetWorld(ScaleMatrix * Matrix(TRANS, CamPos));
	this->pSkyGO->Render();
}
