#include "PointDeRegCmd.h"

#include "MOABEPointLight.h"

#include "SceneAttorney.h"
#include "LightAttorney.h"

PointDeRegCmd::PointDeRegCmd(MOABEPointLight* _pLight) :
	pLight(_pLight)
{
}

void PointDeRegCmd::Execute() const
{
	SceneAttorney::Registration::DeregisterLight(SceneManager::GetCurrScene(), this->pLight);
	LightAttorney::Light::SetRegStatusDeregistered(this->pLight);
}
