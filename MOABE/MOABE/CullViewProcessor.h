#ifndef CULLVIEWPROCESSINGSTRATEGY_H
#define CULLVIEWPROCESSINGSTRATEGY_H

#include "LightProcessor.h"

/// Only renders the lights up to a minimum render distance and within view of the camera
class CullViewProcessor : public LightProcessor
{
public:
	virtual void ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const override;
};

#endif // CULLVIEWPROCESSINGSTRATEGY_H
