#ifndef NORMALPROCESSINGSTRATEGY_H
#define NORMALPROCESSINGSTRATEGY_H

#include "LightProcessor.h"

/// Default Processing Mode Which Tries To Render All the Lights in the scene
class NormalProcessor : public LightProcessor
{
public:
	virtual void ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const override;

private:
	void privProcessAllPoint(const LightList& lightList) const;
	void privProcessAllSpot(const LightList& lightList) const;
	void privProcessClosestPoint(const LightList& lightList) const;
	void privProcessClosestSpot(const LightList& lightList) const;
};

#endif // NORMALPROCESSINGSTRATEGY_H
