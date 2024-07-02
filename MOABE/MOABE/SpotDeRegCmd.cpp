#include "SpotDeRegCmd.h"

#include "MOABESpotLight.h"

#include "SceneAttorney.h"
#include "LightAttorney.h"

SpotDeRegCmd::SpotDeRegCmd(MOABESpotLight* _pLight) :
	pLight(_pLight)
{
}

void SpotDeRegCmd::Execute() const
{
	SceneAttorney::Registration::DeregisterLight(SceneManager::GetCurrScene(), this->pLight);
	LightAttorney::Light::SetRegStatusDeregistered(this->pLight);
}
