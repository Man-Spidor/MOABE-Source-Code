#include "MOABESpotLight.h"

#include "SpotRegCmd.h"
#include "SpotDeRegCmd.h"

#include "SceneAttorney.h"
#include <Colors.h>

MOABESpotLight::MOABESpotLight() :
	spotLight(),
	pRegCmd(new SpotRegCmd(this)),
	pDeRegCmd(new SpotDeRegCmd(this)),
	Range(50.0f)
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->spotLight.Attenuation = 0.2f * Vect(1.0f, 1.0f, 1.0f);
	this->spotLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->spotLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->spotLight.Light.Specular = 0.25 * Vect(1, 1, 1);
}

MOABESpotLight::~MOABESpotLight()
{
	delete this->pRegCmd;
	delete this->pDeRegCmd;
}

MOABESpotLight::MOABESpotLight(LightBehaviourCommand* _pBehaviour) :
	spotLight(),
	pRegCmd(new SpotRegCmd(this)),
	pDeRegCmd(new SpotDeRegCmd(this)),
	Range(50.0f)
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->spotLight.Attenuation = 0.2f * Vect(1.0f, 1.0f, 1.0f);
	this->spotLight.Light.Ambient = 0.25f * Colors::Yellow;
	this->spotLight.Light.Diffuse = 0.25f * Colors::Yellow;
	this->spotLight.Light.Specular = 0.25 * Vect(1, 1, 1);

	MOABELight::SetBehaviour(_pBehaviour);
}

MOABESpotLight::MOABESpotLight(const Vect& Color) :
	spotLight(),
	pRegCmd(new SpotRegCmd(this)),
	pDeRegCmd(new SpotDeRegCmd(this)),
	Range(50.0f)
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->spotLight.Attenuation = 0.2f * Vect(1.0f, 1.0f, 1.0f);
	this->spotLight.Light.Ambient = 0.25f * Color;
	this->spotLight.Light.Diffuse = 0.25f * Color;
	this->spotLight.Light.Specular = 0.25 * Color;
}

MOABESpotLight::MOABESpotLight(const Vect& Position, const Vect& Direction, const Vect& Attenuation, const float SpotExponent, const float _Range) :
	spotLight(),
	pRegCmd(new SpotRegCmd(this)),
	pDeRegCmd(new SpotDeRegCmd(this)),
	Range(_Range)
{
	assert(pRegCmd);
	assert(pDeRegCmd);

	this->spotLight.Position = Position;
	this->spotLight.Direction = Direction;
	this->spotLight.Attenuation = Attenuation;
	this->spotLight.SpotExp = SpotExponent;
}

MOABESpotLight::MOABESpotLight(const Vect& Position, const Vect& Direction, const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) :
	spotLight(),
	pRegCmd(new SpotRegCmd(this)),
	pDeRegCmd(new SpotDeRegCmd(this)),
	Range(0.0f)
{
	this->spotLight.Position = Position;
	this->spotLight.Direction = Direction;
	this->spotLight.Attenuation = 0.2f * Vect(1.0f, 1.0f, 1.0f);

	this->spotLight.Light.Ambient = Ambient;
	this->spotLight.Light.Diffuse = Diffuse;
	this->spotLight.Light.Specular = Specular;
}

const SpotLight& MOABESpotLight::GetLight() const
{
	return this->spotLight;
}

void MOABESpotLight::SetAmbDifSpec(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular)
{
	this->spotLight.Light.Ambient = Ambient;
	this->spotLight.Light.Diffuse = Diffuse;
	this->spotLight.Light.Specular = Specular;
}

void MOABESpotLight::SetAmbient(const Vect& Ambient)
{
	this->spotLight.Light.Ambient = Ambient;
}

void MOABESpotLight::SetDiffuse(const Vect& Diffuse)
{
	this->spotLight.Light.Diffuse = Diffuse;
}

void MOABESpotLight::SetSpecular(const Vect& Specular)
{
	this->spotLight.Light.Specular = Specular;
}

const Vect& MOABESpotLight::GetAmbient() const
{
	// TODO: insert return statement here
	return this->spotLight.Light.Ambient;
}

const Vect& MOABESpotLight::GetDiffuse() const
{
	// TODO: insert return statement here
	return this->spotLight.Light.Diffuse;
}

const Vect& MOABESpotLight::GetSpecular() const
{
	// TODO: insert return statement here
	return this->spotLight.Light.Specular;
}

void MOABESpotLight::DimLight(const float dimFactor)
{
	this->spotLight.Light.Ambient *= dimFactor;
	this->spotLight.Light.Diffuse *= dimFactor;
	this->spotLight.Light.Specular *= dimFactor;
}

void MOABESpotLight::BrightenLight(const float brightFactor)
{
	this->spotLight.Light.Ambient *= brightFactor;
	this->spotLight.Light.Diffuse *= brightFactor;
	this->spotLight.Light.Specular *= brightFactor;
}

void MOABESpotLight::SetPosition(const Vect& Position)
{
	this->spotLight.Position = Position;
}

void MOABESpotLight::SetDirection(const Vect& Direction)
{
	this->spotLight.Direction = Direction;
}

void MOABESpotLight::SetLookAtTarget(const Vect& TargetPos)
{
	this->spotLight.Direction = this->spotLight.Position - TargetPos;
}

const Vect& MOABESpotLight::GetPosition() const
{
	return this->spotLight.Position;
}

const Vect& MOABESpotLight::GetDirection() const
{
	return this->spotLight.Direction;
}

void MOABESpotLight::SetRange(const float _Range)
{
	this->Range = _Range;
}

void MOABESpotLight::SetSpotLightParams(const Vect& Position, const Vect& Attenuation, const Vect& Direction, const float SpotExp, const float _Range)
{
	this->spotLight.Position = Position;
	this->spotLight.Attenuation = Attenuation;
	this->spotLight.Direction = Direction;
	this->spotLight.SpotExp = SpotExp;
	this->Range = _Range;
}

void MOABESpotLight::RegisterLight()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_DEREGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
	this->regStatus = RegistrationStatus::PENDING_REGISTRATION;

	this->TurnOn();
}

void MOABESpotLight::DeregisterLight()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED);

	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
	this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
}

void MOABESpotLight::TurnOn()
{
	this->spotLight.Range = this->Range;
}

void MOABESpotLight::TurnOff()
{
	this->spotLight.Range = 0.0f;
}

void MOABESpotLight::TranslateLeftRight(float delta)
{
	this->spotLight.Position.X() += delta;
}

void MOABESpotLight::TranslateUpDown(float delta)
{
	this->spotLight.Position.Y() += delta;
}

void MOABESpotLight::TranslateFwdBack(float delta)
{
	this->spotLight.Position.Z() += delta;
}

void MOABESpotLight::TiltUpDown(float ang)
{
	Matrix Rot = Matrix(ROT_X, ang);
	this->spotLight.Direction *= Rot;
}

void MOABESpotLight::TurnLeftRight(float ang)
{
	Matrix Rot = Matrix(ROT_Y, ang);
	this->spotLight.Direction *= Rot;
}
