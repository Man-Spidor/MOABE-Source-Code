#include "CullDistProcessor.h"

#include "MOABEPointLight.h"
#include "MOABESpotLight.h"

#include "LightAttorney.h"
#include "SceneManager.h"

#include <ShaderContextManager.h>

void CullDistProcessor::ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const
{
	Vect CamPos;
	SceneManager::GetCurrScene().GetMainCamera().getPos(CamPos);

	static LightDistList pointDists;
	static LightDistList spotDists;

#pragma region Process Point Lights
	for (MOABELight* pLight : pointList) {
		LightAttorney::Light::UpdateLight(pLight);

		const Vect toLight = ((MOABEPointLight&)*pLight).GetPosition() - CamPos;
		const float distToLight = toLight.magSqr();

		// Check if The Light Is Within The Render Distance
		if (distToLight <= distSqr) {
			pointDists.push_back(LightDistPair(distToLight, pLight));
		}
	}

	unsigned int i = 0;
	while (i < MAX_POINT_LIGHTS && i < pointDists.size()) {
		ShaderContextManager::SetPointLightParameters(LIGHTNUM(i), &((MOABEPointLight*)pointDists[i].second)->GetLight());
		i++;
	}
	while (i < MAX_POINT_LIGHTS) {
		ShaderContextManager::SetPointLightParameters(LIGHTNUM(i), &LightManager::emptyPointLight);
		i++;
	}
	pointDists.clear();
#pragma endregion

#pragma region Process Spot Lights
	for (MOABELight* pLight : spotList) {
		LightAttorney::Light::UpdateLight(pLight);

		const Vect toLight = ((MOABESpotLight&)*pLight).GetPosition() - CamPos;
		const float distToLight = toLight.magSqr();

		// Check if The Light Is Within The Render Distance
		if (distToLight <= distSqr) {
			spotDists.push_back(LightDistPair(distToLight, pLight));
		}
	}

	i = 0;
	while (i < MAX_POINT_LIGHTS && i < spotDists.size()) {
		ShaderContextManager::SetSpotLightParameters(LIGHTNUM(i), &((MOABESpotLight*)spotDists[i].second)->GetLight());
		i++;
	}
	while (i < MAX_POINT_LIGHTS) {
		ShaderContextManager::SetSpotLightParameters(LIGHTNUM(i), &LightManager::emptySpotLight);
		i++;
	}
	spotDists.clear();
#pragma endregion
}
