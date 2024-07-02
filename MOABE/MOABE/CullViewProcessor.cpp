#include "CullViewProcessor.h"

#include "MOABEPointLight.h"
#include "MOABESpotLight.h"

#include "LightAttorney.h"
#include "SceneManager.h"

#include <ShaderContextManager.h>


void CullViewProcessor::ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const
{
	Vect CamPos;
	Vect CamDir;
	SceneManager::GetCurrScene().GetMainCamera().getPos(CamPos);
	SceneManager::GetCurrScene().GetMainCamera().getDir(CamDir);

	static LightDistList pointDists;
	static LightDistList spotDists;

#pragma region Process Point Lights
	for (MOABELight* pLight : pointList) {
		LightAttorney::Light::UpdateLight(pLight);

		const Vect toLight = ((MOABEPointLight&)*pLight).GetPosition() - CamPos;
		const float distToLight = toLight.magSqr();

		// First Check if The Light Is Within The Render Distance
		if (distToLight <= distSqr) {
			// Then we check if the lights is "in view" aka in front of the camera
			// We do that by checking the dot product to see if it is greater than 0 aka the angle between them is greater than 90 degrees
			if (toLight.dot(CamDir) <= 0.0f) {
				pointDists.push_back(LightDistPair(distToLight, pLight));
			}
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

		// First Check if The Light Is Within The Render Distance
		if (distToLight <= distSqr) {
			// Then we check if the lights is "in view" aka in front of the camera
			// We do that by checking the dot product to see if it is greater than 0 aka the angle between them is greater than 90 degrees
			if (toLight.dot(CamDir) <= 0.0f) {
				spotDists.push_back(LightDistPair(distToLight, pLight));
			}
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
