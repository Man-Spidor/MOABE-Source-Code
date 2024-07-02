#include "GameObject.h"
#include "SceneManager.h"
#include "GameObjectRegCmd.h"
#include "GameObjectDeRegCmd.h"
#include "SceneAttorney.h"

GameObject::GameObject() :
	regStatus(RegistrationStatus::CURRENTLY_DEREGISTERED),
	pRegCmd(new GameObjectRegCmd(this)),
	pDeRegCmd(new GameObjectDeRegCmd(this))
{
	assert(this->pRegCmd);
	assert(this->pDeRegCmd);
}

GameObject::~GameObject()
{
	delete this->pRegCmd;
	delete this->pDeRegCmd;
}

void GameObject::ConnectToScene()
{
	if (this->regStatus == RegistrationStatus::PENDING_REGISTRATION) {
		this->regStatus = RegistrationStatus::CURRENTLY_REGISTERED;

		this->SceneEntry();
	}
}

void GameObject::DisconnectFromScene()
{
	if (this->regStatus == RegistrationStatus::PENDING_DEREGISTRATION) {
		this->regStatus = RegistrationStatus::CURRENTLY_DEREGISTERED;

		this->SceneExit();
	}
}

void GameObject::SubmitEntry()
{
	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
	this->regStatus = RegistrationStatus::PENDING_REGISTRATION;
}

void GameObject::SubmitExit()
{
	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
	this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
}
