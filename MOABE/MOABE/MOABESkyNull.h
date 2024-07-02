#ifndef MOABESKYNULL_H
#define MOABESKYNULL_H

#include "SkyboxObject.h"

/// Represents a null skybox object.
/// 
/// This class provides a null implementation of a skybox object with no functionality.
class MOABESkyNull : public SkyboxObject
{
public:
	MOABESkyNull() = default;
	MOABESkyNull(const MOABESkyNull& other) = default;
	MOABESkyNull& operator=(const MOABESkyNull& other) = default;
	MOABESkyNull(MOABESkyNull&& other) = default;
	MOABESkyNull& operator=(MOABESkyNull&& other) = default;
	~MOABESkyNull() = default;

	virtual void Render() override { };
};

#endif // MOABESKYNULL_H
