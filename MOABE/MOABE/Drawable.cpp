#include "Drawable.h"

#include "Drawable3DRegCmd.h"
#include "Drawable3DDeregCmd.h"

#include "Drawable2DRegCmd.h"
#include "Drawable2DDeregCmd.h"

#include "SceneManager.h"
#include "SceneAttorney.h"

Drawable::Drawable() :
	regStatus3D(RegistrationStatus::CURRENTLY_DEREGISTERED),
	regStatus2D(RegistrationStatus::CURRENTLY_DEREGISTERED),
	pRegCmd3D(new Drawable3DRegCmd(this)),
	pDeRegCmd3D(new Drawable3DDeRegCmd(this)),
	pRegCmd2D(new Drawable2DRegCmd(this)),
	pDeRegCmd2D(new Drawable2DDeRegCmd(this))
{
	assert(this->pRegCmd3D);
	assert(this->pDeRegCmd3D);

	assert(this->pRegCmd2D);
	assert(this->pDeRegCmd2D);
}

Drawable::~Drawable()
{
	delete this->pRegCmd3D;
	delete this->pDeRegCmd3D;
	
	delete this->pRegCmd2D;
	delete this->pDeRegCmd2D;
}

void Drawable::Set3DRegStatusRegistered()
{
	this->regStatus3D = RegistrationStatus::CURRENTLY_REGISTERED;
}

void Drawable::Set3DRegStatusDeregistered()
{
	this->regStatus3D = RegistrationStatus::CURRENTLY_DEREGISTERED;
}

void Drawable::Set2DRegStatusRegistered()
{
	this->regStatus2D = RegistrationStatus::CURRENTLY_REGISTERED;
}

void Drawable::Set2DRegStatusDeregistered()
{
	this->regStatus2D = RegistrationStatus::CURRENTLY_DEREGISTERED;
}

void Drawable::SetDeleteRef3D(DrawableManager::DrawableListRef deleteRef)
{
	this->deleteRef3D = deleteRef;
}

DrawableManager::DrawableListRef& Drawable::GetDeleteRef3D()
{
	return this->deleteRef3D;
}

void Drawable::SetDeleteRef2D(DrawableManager::DrawableListRef deleteRef)
{
	this->deleteRef2D = deleteRef;
}

DrawableManager::DrawableListRef& Drawable::GetDeleteRef2D()
{
	return this->deleteRef2D;
}

void Drawable::RegisterToScene3D()
{
	assert(this->regStatus3D == RegistrationStatus::CURRENTLY_DEREGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd3D);
	this->regStatus3D = RegistrationStatus::PENDING_REGISTRATION;
}

void Drawable::DeregisterFromScene3D()
{
	assert(this->regStatus3D == RegistrationStatus::CURRENTLY_REGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd3D);
	this->regStatus3D = RegistrationStatus::PENDING_DEREGISTRATION;
}

void Drawable::RegisterToScene2D()
{
	assert(this->regStatus2D == RegistrationStatus::CURRENTLY_DEREGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd2D);
	this->regStatus2D = RegistrationStatus::PENDING_REGISTRATION;
}

void Drawable::DeregisterFromScene2D()
{
	assert(this->regStatus2D == RegistrationStatus::CURRENTLY_REGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd2D);
	this->regStatus2D = RegistrationStatus::PENDING_DEREGISTRATION;
}
