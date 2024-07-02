#include "SpotRegCmd.h"

#include "MOABESpotLight.h"

#include "SceneAttorney.h"
#include "LightAttorney.h"

SpotRegCmd::SpotRegCmd(MOABESpotLight* _pLight) :
	pLight(_pLight)
{
}

void SpotRegCmd::Execute() const
{
	SceneAttorney::Registration::RegisterLight(SceneManager::GetCurrScene(), this->pLight);
	LightAttorney::Light::SetRegStatusRegistered(this->pLight);
}
