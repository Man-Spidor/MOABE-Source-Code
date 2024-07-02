#include "PointRegCmd.h"

#include "MOABEPointLight.h"

#include "SceneAttorney.h"
#include "LightAttorney.h"

PointRegCmd::PointRegCmd(MOABEPointLight* _pLight) :
	pLight(_pLight)
{
}

void PointRegCmd::Execute() const
{
	SceneAttorney::Registration::RegisterLight(SceneManager::GetCurrScene(), this->pLight);
	LightAttorney::Light::SetRegStatusRegistered(this->pLight);
}
