#include "DirectionalDeRegCmd.h"

#include "MOABEDirectionalLight.h"

#include "SceneAttorney.h"
#include "LightAttorney.h"

DirectionalDeRegCmd::DirectionalDeRegCmd(MOABEDirectionalLight* _pLight) :
	pLight(_pLight)
{
}

void DirectionalDeRegCmd::Execute() const
{
	SceneAttorney::Registration::DeregisterLight(SceneManager::GetCurrScene(), this->pLight);
	LightAttorney::Light::SetRegStatusDeregistered(this->pLight);
}
