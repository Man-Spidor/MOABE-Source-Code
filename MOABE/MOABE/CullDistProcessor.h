#ifndef CULLDISTPROCESSINGSTRATEGY_H
#define CULLDISTPROCESSINGSTRATEGY_H

#include "LightProcessor.h"

/// Only renders the lights up to a minimum render distance
class CullDistProcessor : public LightProcessor
{
public:
	virtual void ProcessLights(const LightList& pointList, const LightList& spotList, const float distSqr) const override;
};

#endif // CULLDISTPROCESSINGSTRATEGY_H
