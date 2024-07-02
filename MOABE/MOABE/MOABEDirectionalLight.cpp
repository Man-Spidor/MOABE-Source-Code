#include "MOABEDirectionalLight.h"

#include "DirectionalRegCmd.h"
#include "DirectionalDeRegCmd.h"

#include <Colors.h>
#include "SceneAttorney.h"

const Vect MOABEDirectionalLight::OFF_VECT = Vect(0.0f, 1.0f, 0.0f);

MOABEDirectionalLight::MOABEDirectionalLight() :
	dirLight(),
	Direction(),
	pRegCmd(new DirectionalRegCmd(this)),
	pDeRegCmd(new DirectionalDeRegCmd(this))
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->dirLight.Direction = Vect(0.0f, -1.0f, 0.0f);
	this->dirLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->dirLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->dirLight.Light.Specular = 0.25 * Vect(1, 1, 1);
}

MOABEDirectionalLight::~MOABEDirectionalLight()
{
	delete this->pRegCmd;
	delete this->pDeRegCmd;
}

MOABEDirectionalLight::MOABEDirectionalLight(LightBehaviourCommand* _pBehaviour) :
	dirLight(),
	Direction(),
	pRegCmd(new DirectionalRegCmd(this)),
	pDeRegCmd(new DirectionalDeRegCmd(this))
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->dirLight.Direction = Vect(0.0f, -1.0f, 0.0f);
	this->dirLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->dirLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->dirLight.Light.Specular = 0.25 * Vect(1, 1, 1);

	this->SetBehaviour(_pBehaviour);
}

MOABEDirectionalLight::MOABEDirectionalLight(const Vect& Direction) :
	dirLight(),
	Direction(),
	pRegCmd(new DirectionalRegCmd(this)),
	pDeRegCmd(new DirectionalDeRegCmd(this))
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->dirLight.Direction = Direction;
	this->dirLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->dirLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->dirLight.Light.Specular = 0.25 * Vect(1, 1, 1);
}

MOABEDirectionalLight::MOABEDirectionalLight(const Vect& Direction, const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) :
	dirLight(),
	Direction(),
	pRegCmd(new DirectionalRegCmd(this)),
	pDeRegCmd(new DirectionalDeRegCmd(this))
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->dirLight.Direction = Direction;

	this->dirLight.Light.Ambient = Ambient;
	this->dirLight.Light.Diffuse = Diffuse;
	this->dirLight.Light.Specular = Specular;
}

const DirectionalLight& MOABEDirectionalLight::GetLight() const
{
	return this->dirLight;
}

void MOABEDirectionalLight::SetAmbDifSpec(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular)
{
	this->dirLight.Light.Ambient = Ambient;
	this->dirLight.Light.Diffuse = Diffuse;
	this->dirLight.Light.Specular = Specular;
}
void MOABEDirectionalLight::SetAmbient(const Vect& Ambient)
{
	this->dirLight.Light.Ambient = Ambient;
}

void MOABEDirectionalLight::SetDiffuse(const Vect& Diffuse)
{
	this->dirLight.Light.Diffuse = Diffuse;
}

void MOABEDirectionalLight::SetSpecular(const Vect& Specular)
{
	this->dirLight.Light.Specular = Specular;
}

const Vect& MOABEDirectionalLight::GetAmbient() const
{
	// TODO: insert return statement here
	return this->dirLight.Light.Ambient;
}

const Vect& MOABEDirectionalLight::GetDiffuse() const
{
	// TODO: insert return statement here
	return this->dirLight.Light.Diffuse;
}

const Vect& MOABEDirectionalLight::GetSpecular() const
{
	// TODO: insert return statement here
	return this->dirLight.Light.Specular;
}


void MOABEDirectionalLight::DimLight(const float dimFactor)
{
	this->dirLight.Light.Ambient *= dimFactor;
	this->dirLight.Light.Diffuse *= dimFactor;
	this->dirLight.Light.Specular *= dimFactor;
}

void MOABEDirectionalLight::BrightenLight(const float brightFactor)
{

	this->dirLight.Light.Ambient *= brightFactor;
	this->dirLight.Light.Diffuse *= brightFactor;
	this->dirLight.Light.Specular *= brightFactor;
}

void MOABEDirectionalLight::SetDirectionalLightParams(const Vect& _Direction)
{
	this->Direction = _Direction;
	this->dirLight.Direction = _Direction;
}

void MOABEDirectionalLight::RegisterLight()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_DEREGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
	this->regStatus = RegistrationStatus::PENDING_REGISTRATION;
}

void MOABEDirectionalLight::DeregisterLight()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
	this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
}

void MOABEDirectionalLight::TurnOn()
{
	this->dirLight.Direction = this->Direction;
	this->pBehaviour->StartProcessing();
}

void MOABEDirectionalLight::TurnOff()
{
	this->dirLight.Direction = OFF_VECT;
}

void MOABEDirectionalLight::TiltUpDown(float ang)
{
	Matrix Rot = Matrix(ROT_X, ang);
	this->dirLight.Direction *= Rot;
}

void MOABEDirectionalLight::TurnLeftRight(float ang)
{
	Matrix Rot = Matrix(ROT_Y, ang);
	this->dirLight.Direction *= Rot;
}
