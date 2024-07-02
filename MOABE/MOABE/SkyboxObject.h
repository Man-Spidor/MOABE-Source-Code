#ifndef SKYBOXOBJECT_H
#define SKYBOXOBJECT_H

#include "SkyBox.h"

class SkyboxObject
{
public:
	SkyboxObject() = default;
	SkyboxObject(const SkyboxObject& other) = default;
	SkyboxObject& operator=(const SkyboxObject& other) = default;
	SkyboxObject(SkyboxObject&& other) = default;
	SkyboxObject& operator=(SkyboxObject&& other) = default;
	virtual ~SkyboxObject() = default;

	virtual void Render() = 0;
};

#endif // SKYBOXOBJECT_H
