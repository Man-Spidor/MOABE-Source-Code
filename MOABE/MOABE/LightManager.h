#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include "LightParamData.h"
#include "LightStaticCmd.h"

#include <vector>

class MOABELight;
class MOABESpotLight;
class MOABEPointLight;
class MOABEDirectionalLight;

class LightProcessor;

class LightManager
{
public:
	static const DirectionalLight emptyDirLight;
	static const PointLight emptyPointLight;
	static const SpotLight emptySpotLight;

private:
	static DirectionalLight DefaultLight;

	using LightList = std::vector<MOABELight*>;
	using LightDistPair = std::pair<float, MOABELight*>;

public:
	static LightStaticCmd StaticBehaviour;
	using ListRef = LightList::iterator;

	LightManager();
	LightManager(const LightManager& other) = default;
	LightManager& operator=(const LightManager& other) = default;
	LightManager(LightManager&& other) = default;
	LightManager& operator=(LightManager&& other) = default;
	~LightManager() = default;

	void ClearLights();

	void ActivateBaseLight() const;
	void DisableBaseLight() const;

	void SetModeNormal();
	void SetModeCullByDist(const float minRenderDist);
	void SetModeCullByView(const float minRenderDist);

	void ProcessLights() const;

	void RegisterLight(MOABEDirectionalLight* pDirLight);
	void RegisterLight(MOABEPointLight* pPointLight);
	void RegisterLight(MOABESpotLight* pSpotLight);

	void DeregisterLight(MOABEDirectionalLight* pDirLight);
	void DeregisterLight(MOABEPointLight* pPointLight);
	void DeregisterLight(MOABESpotLight* pSpotLight);

	static bool CompareLightDists(const LightDistPair& lhs, const LightDistPair& rhs);

private:
	LightList dirList;
	LightList pointList;
	LightList spotList;

	static const LightProcessor* ProcessMode;

	static float minRenderDistanceSqr;
};

#endif // LIGHTMANAGER_H
