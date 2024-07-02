#include "LightManager.h"

#include "EngineMath.h"
#include "SceneManager.h"
#include "MOABEAttorney.h"
#include "LightAttorney.h"

#include "MOABEDirectionalLight.h"
#include "MOABEPointLight.h"
#include "MOABESpotLight.h"

#include "LightProcessors.h"

#include <ShaderContextManager.h>

LightStaticCmd LightManager::StaticBehaviour;

const DirectionalLight LightManager::emptyDirLight;
const PointLight LightManager::emptyPointLight;
const SpotLight LightManager::emptySpotLight;

DirectionalLight LightManager::DefaultLight;

const LightProcessor* LightManager::ProcessMode = &LightProcessors::NormalMode;
float LightManager::minRenderDistanceSqr = 0.0f;

LightManager::LightManager() :
	dirList(),
	pointList(),
	spotList()
{
	DefaultLight.Direction = Vect(0.0f, -1.0f, 0.0f);
	DefaultLight.Light.Ambient = .25 * Vect(1, 1, 1);
	DefaultLight.Light.Diffuse = .25 * Vect(1, 1, 1);
	DefaultLight.Light.Specular = Vect(1, 1, 1);

	this->pointList.reserve(MAX_POINT_LIGHTS);
	this->spotList.reserve(MAX_SPOT_LIGHTS);
	this->dirList.reserve(MAX_DIR_LIGHTS);

	// Need to define an empty light to "turn off" all the lights that might be active
	for (int i = 0; i < MAX_DIR_LIGHTS; i++) {
		ShaderContextManager::SetDirectionalLightParameters(LIGHTNUM(i), &this->emptyDirLight);
	}

	for (int i = 0; i < MAX_POINT_LIGHTS; i++) {
		ShaderContextManager::SetPointLightParameters(LIGHTNUM(i), &this->emptyPointLight);
	}

	for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
		ShaderContextManager::SetSpotLightParameters(LIGHTNUM(i), &this->emptySpotLight);
	}
}

void LightManager::ClearLights()
{
	for (MOABELight* pLight : this->dirList) {
		LightAttorney::Light::SetRegStatusDeregistered(pLight);
	}

	for (MOABELight* pLight : this->pointList) {
		LightAttorney::Light::SetRegStatusDeregistered(pLight);
	}

	for (MOABELight* pLight : this->spotList) {
		LightAttorney::Light::SetRegStatusDeregistered(pLight);
	}
}

void LightManager::ActivateBaseLight() const
{
	ShaderContextManager::SetDirectionalLightParameters(LIGHTNUM::LIGHT_1, &this->DefaultLight);
}

void LightManager::DisableBaseLight() const
{
	ShaderContextManager::SetDirectionalLightParameters(LIGHTNUM::LIGHT_1, &this->emptyDirLight);
}

void LightManager::SetModeNormal()
{
	this->ProcessMode = &LightProcessors::NormalMode;
}

void LightManager::SetModeCullByDist(const float minRenderDist)
{
	this->minRenderDistanceSqr = minRenderDist * minRenderDist;
	this->ProcessMode = &LightProcessors::CullDistMode;
}

void LightManager::SetModeCullByView(const float minRenderDist)
{
	this->minRenderDistanceSqr = minRenderDist * minRenderDist;
	this->ProcessMode = &LightProcessors::CullViewMode;
}

void LightManager::ProcessLights() const
{
	unsigned int i = 0;
	for (MOABELight* pLight : this->dirList) {
		LightAttorney::Light::UpdateLight(pLight);
		ShaderContextManager::SetDirectionalLightParameters(LIGHTNUM(i), &((MOABEDirectionalLight*)pLight)->GetLight());
		i++;
	}

	this->ProcessMode->ProcessLights(this->pointList, this->spotList, this->minRenderDistanceSqr);
}

#pragma region Light Registration Methods
void LightManager::RegisterLight(MOABEDirectionalLight* pDirLight)
{
	if (this->dirList.size() < MAX_DIR_LIGHTS) {
		this->dirList.push_back(pDirLight);
	}
	else {
		Trace::out("MOABE WARNING: Directional Light At Mem: [%p] was not registered as you have exceeded the maximum number of directional lights. Please deregister one before trying again.");
	}
}

void LightManager::RegisterLight(MOABEPointLight* pPointLight)
{
	this->pointList.push_back(pPointLight);
}

void LightManager::RegisterLight(MOABESpotLight* pSpotLight)
{
	this->spotList.push_back(pSpotLight);
}
#pragma endregion

#pragma region Light Deregistration Methods
void LightManager::DeregisterLight(MOABEDirectionalLight* pDirLight)
{
	auto it = std::find(this->dirList.begin(), this->dirList.end(), pDirLight);

	assert(it != this->dirList.end());
	this->dirList.erase(it);
}

void LightManager::DeregisterLight(MOABEPointLight* pPointLight)
{
	auto it = std::find(this->pointList.begin(), this->pointList.end(), pPointLight);
	
	assert(it != this->pointList.end());
	this->pointList.erase(it);
}

void LightManager::DeregisterLight(MOABESpotLight* pSpotLight)
{
	auto it = std::find(this->spotList.begin(), this->spotList.end(), pSpotLight);

	assert(it != this->spotList.end());
	this->spotList.erase(it);
}
#pragma endregion

bool LightManager::CompareLightDists(const LightDistPair& lhs, const LightDistPair& rhs)
{
	return lhs.first < rhs.first;
}
