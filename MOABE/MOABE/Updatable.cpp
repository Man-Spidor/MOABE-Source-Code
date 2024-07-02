#include "Updatable.h"
#include "SceneManager.h"
#include "SceneAttorney.h"
#include "UpdatableRegCmd.h"
#include "UpdatableDeRegCmd.h"

#include "UpdatableRegCmd.h"
#include "UpdatableDeRegCmd.h"

Updatable::Updatable() :
	regStatus(RegistrationStatus::CURRENTLY_DEREGISTERED),
	pRegCmd(new UpdatableRegCmd(this)),
	pDeRegCmd(new UpdatableDeRegCmd(this))
{
	assert(pRegCmd);
	assert(pDeRegCmd);
}

Updatable::~Updatable()
{
	delete this->pRegCmd;
	delete this->pDeRegCmd;
}

void Updatable::SetRegStatusRegistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_REGISTERED;
}

void Updatable::SetRegStatusDeregistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_DEREGISTERED;
}

void Updatable::SetDeleteRef(UpdatableManager::UpdatableListRef deleteRef)
{
	this->myDeleteRef = deleteRef;
}

UpdatableManager::UpdatableListRef& Updatable::GetDeleteRef()
{
	return this->myDeleteRef;
}

void Updatable::RegisterToScene()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_DEREGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
	this->regStatus = RegistrationStatus::PENDING_REGISTRATION;
}

void Updatable::DeregisterFromScene()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
	this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
}
