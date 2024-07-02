#include "DirectionalRegCmd.h"

#include "MOABEDirectionalLight.h"

#include "SceneAttorney.h"
#include "LightAttorney.h"

DirectionalRegCmd::DirectionalRegCmd(MOABEDirectionalLight* _pLight) :
	pLight(_pLight)
{
}

void DirectionalRegCmd::Execute() const
{
	SceneAttorney::Registration::RegisterLight(SceneManager::GetCurrScene(), this->pLight);
	LightAttorney::Light::SetRegStatusRegistered(this->pLight);
}
