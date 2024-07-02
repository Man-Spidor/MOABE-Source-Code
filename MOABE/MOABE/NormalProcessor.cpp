#include "NormalProcessor.h"

#include "MOABELight.h"
#include "MOABEPointLight.h"
#include "MOABESpotLight.h"

#include "LightAttorney.h"
#include "SceneManager.h"

#include <LightParamData.h>

#include <ShaderContextManager.h>

void NormalProcessor::ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const
{
	UNREFERENCED_PARAMETER(distSqr);

	if (pointList.size() < MAX_POINT_LIGHTS)
		this->privProcessAllPoint(pointList);
	else
		this->privProcessClosestPoint(pointList);

	if (spotList.size() < MAX_SPOT_LIGHTS)
		this->privProcessAllSpot(spotList);
	else
		this->privProcessClosestSpot(spotList);
}

void NormalProcessor::privProcessAllPoint(const LightList& lightList) const
{
	unsigned int i = 0;
	for (MOABELight* pLight : lightList) {
		LightAttorney::Light::UpdateLight(pLight);
		ShaderContextManager::SetPointLightParameters(LIGHTNUM(i), &((MOABEPointLight*)pLight)->GetLight());
		i++;
	}
}

void NormalProcessor::privProcessAllSpot(const LightList& lightList) const
{
	unsigned int i = 0;
	for (MOABELight* pLight : lightList) {
		LightAttorney::Light::UpdateLight(pLight);
		ShaderContextManager::SetSpotLightParameters(LIGHTNUM(i), &((MOABESpotLight*)pLight)->GetLight());
		i++;
	}
}

void NormalProcessor::privProcessClosestPoint(const LightList& lightList) const
{
	static LightDistList dists;

	Vect CamPos;
	SceneManager::GetCurrScene().GetMainCamera().getPos(CamPos);

	for (MOABELight* pLight : lightList) {
		dists.push_back(LightDistPair((((MOABEPointLight&)*pLight).GetPosition() - CamPos).magSqr(), pLight));
	}

	std::sort(dists.begin(), dists.end(), LightManager::CompareLightDists);

	unsigned int i = 0;
	while (i < MAX_POINT_LIGHTS) {
		LightAttorney::Light::UpdateLight(dists[i].second);
		ShaderContextManager::SetPointLightParameters(LIGHTNUM(i), &((MOABEPointLight*)dists[i].second)->GetLight());
		i++;
	}

	dists.clear();
}

void NormalProcessor::privProcessClosestSpot(const LightList& lightList) const
{
	static LightDistList dists;

	Vect CamPos;
	SceneManager::GetCurrScene().GetMainCamera().getPos(CamPos);

	for (MOABELight* pLight : lightList) {
		dists.push_back(LightDistPair((((MOABESpotLight&)*pLight).GetPosition() - CamPos).magSqr(), pLight));
	}

	std::sort(dists.begin(), dists.end(), LightManager::CompareLightDists);

	unsigned int i = 0;
	while (i < MAX_POINT_LIGHTS) {
		LightAttorney::Light::UpdateLight(dists[i].second);
		ShaderContextManager::SetSpotLightParameters(LIGHTNUM(i), &((MOABESpotLight*)dists[i].second)->GetLight());
		i++;
	}

	dists.clear();
}
