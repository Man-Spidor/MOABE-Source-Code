#include "MOABELight.h"

#include "LightManager.h"

#include "LightAttorney.h"

MOABELight::MOABELight() :
	regStatus(RegistrationStatus::CURRENTLY_DEREGISTERED),
	pBehaviour(&LightManager::StaticBehaviour)
{
}

void MOABELight::SetBehaviourStatic()
{
	if (this->pBehaviour != &LightManager::StaticBehaviour) {
		delete this->pBehaviour;
		this->pBehaviour = &LightManager::StaticBehaviour;
	}
}

void MOABELight::SetBehaviour(LightBehaviourCommand* _pBehaviour)
{
	if (this->pBehaviour != &LightManager::StaticBehaviour) 
		delete this->pBehaviour;
	
	this->pBehaviour = _pBehaviour;
}

MOABELight::~MOABELight()
{
	if (this->pBehaviour != &LightManager::StaticBehaviour)
		delete this->pBehaviour;
}

void MOABELight::SetRegStatusRegistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_REGISTERED;
	this->TurnOn();
	this->pBehaviour->StartProcessing();
}

void MOABELight::SetRegStatusDeregistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_DEREGISTERED;
	this->TurnOff();
	this->pBehaviour->StopProcessing();
}

void MOABELight::SetColor(const Vect& Color)
{
	this->SetAmbDifSpec(Color, 0.5f * Color, 0.1f * Color);
}

void MOABELight::UpdateLight() const
{
	LightAttorney::Behaviour::ProcessLight(this->pBehaviour);
}

LightBehaviourCommand& MOABELight::GetBehaviour() const
{
	return *this->pBehaviour;
}
