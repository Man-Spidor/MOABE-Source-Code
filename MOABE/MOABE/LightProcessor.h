#ifndef LIGHTPROCESSINGSTRATEGY_H
#define LIGHTPROCESSINGSTRATEGY_H

#include <vector>

class MOABELight;

/// Abstract base strategy class for Light Processing Tests
class LightProcessor
{
public:
	/// The list passed by the LightManager
	using LightList = std::vector<MOABELight*>;
	/// A pair between the distance between the light and camera and the light itslef
	using LightDistPair = std::pair<float, MOABELight*>;
	/// list of the above pairs
	using LightDistList = std::vector<LightDistPair>;

	virtual void ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const = 0;
};

#endif // LIGHTPROCESSINGSTRATEGY_H
