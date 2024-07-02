#include "MOABEPointLight.h"

#include "PointRegCmd.h"
#include "PointDeRegCmd.h"

#include "SceneAttorney.h"
#include <Colors.h>

MOABEPointLight::MOABEPointLight() : 
	pointLight(),
	pRegCmd(new PointRegCmd(this)),
	pDeRegCmd(new PointDeRegCmd(this)),
	Range(50.0f)
{
	this->pointLight.Attenuation = 0.2f * Vect(0.0f, 1.0f, 0.0f);
	this->pointLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->pointLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->pointLight.Light.Specular = 0.25 * Vect(1, 1, 1);
}

MOABEPointLight::~MOABEPointLight()
{
	delete this->pRegCmd;
	delete this->pDeRegCmd;
}

MOABEPointLight::MOABEPointLight(LightBehaviourCommand* _pBehaviour) :
	pointLight(),
	pRegCmd(new PointRegCmd(this)),
	pDeRegCmd(new PointDeRegCmd(this)),
	Range(50.0f)
{
	this->pointLight.Attenuation = 0.2f * Vect(0.0f, 1.0f, 0.0f);
	this->pointLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->pointLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->pointLight.Light.Specular = 0.25 * Vect(1, 1, 1);

	this->SetBehaviour(_pBehaviour);
}

MOABEPointLight::MOABEPointLight(const Vect& Position, const Vect& Attenuation, const float Range) :
	pointLight(),
	pRegCmd(new PointRegCmd(this)),
	pDeRegCmd(new PointDeRegCmd(this)),
	Range(Range)
{
	this->pointLight.Position = Position;
	this->pointLight.Attenuation = Attenuation;

	this->pointLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->pointLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->pointLight.Light.Specular = 0.25 * Vect(1, 1, 1);
}

MOABEPointLight::MOABEPointLight(const Vect& Position, const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) :
	pointLight(),
	pRegCmd(new PointRegCmd(this)),
	pDeRegCmd(new PointDeRegCmd(this)),
	Range(50.0f)
{
	this->pointLight.Position = Position;
	this->pointLight.Light.Ambient = Ambient;
	this->pointLight.Light.Diffuse = Diffuse;
	this->pointLight.Light.Specular = Specular;
}

const PointLight& MOABEPointLight::GetLight() const
{
	return this->pointLight;
}

void MOABEPointLight::SetAmbDifSpec(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular)
{
	this->pointLight.Light.Ambient = Ambient;
	this->pointLight.Light.Diffuse = Diffuse;
	this->pointLight.Light.Specular = Specular;
}

void MOABEPointLight::SetAmbient(const Vect& Ambient)
{
	this->pointLight.Light.Ambient = Ambient;
}

void MOABEPointLight::SetDiffuse(const Vect& Diffuse)
{
	this->pointLight.Light.Diffuse = Diffuse;
}

void MOABEPointLight::SetSpecular(const Vect& Specular)
{
	this->pointLight.Light.Specular = Specular;
}

const Vect& MOABEPointLight::GetAmbient() const
{
	// TODO: insert return statement here
	return this->pointLight.Light.Ambient;
}

const Vect& MOABEPointLight::GetDiffuse() const
{
	// TODO: insert return statement here
	return this->pointLight.Light.Diffuse;
}

const Vect& MOABEPointLight::GetSpecular() const
{
	// TODO: insert return statement here
	return this->pointLight.Light.Specular;
}

void MOABEPointLight::DimLight(const float dimFactor)
{
	this->pointLight.Light.Ambient *= dimFactor;
	this->pointLight.Light.Diffuse *= dimFactor;
	this->pointLight.Light.Specular *= dimFactor;
}

void MOABEPointLight::BrightenLight(const float brightFactor)
{
	this->pointLight.Light.Ambient *= brightFactor;
	this->pointLight.Light.Diffuse *= brightFactor;
	this->pointLight.Light.Specular *= brightFactor;
}

void MOABEPointLight::SetPosition(const Vect& Position)
{
	this->pointLight.Position = Position;
}

void MOABEPointLight::SetRange(const float _Range)
{
	this->Range = _Range;
	this->pointLight.Range = this->Range;
}

const Vect& MOABEPointLight::GetPosition() const
{
	return this->pointLight.Position;
}

void MOABEPointLight::SetPointLightParams(const Vect& Position, const Vect& Attenuation, const float _Range)
{
	this->pointLight.Position = Position;
	this->pointLight.Attenuation = Attenuation;
	this->Range = _Range;
	this->pointLight.Range = this->Range;
}

void MOABEPointLight::RegisterLight()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_DEREGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
	this->regStatus = RegistrationStatus::PENDING_REGISTRATION;
}

void MOABEPointLight::DeregisterLight()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
	this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
}

void MOABEPointLight::TurnOn()
{
	this->pointLight.Range = this->Range;
}

void MOABEPointLight::TurnOff()
{
	this->pointLight.Range = 0;
}
