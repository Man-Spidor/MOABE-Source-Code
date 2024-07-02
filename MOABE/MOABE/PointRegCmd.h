#ifndef POINTREGCMD_H
#define POINTREGCMD_H

#include "RegistrationCommand.h"

class MOABEPointLight;

class PointRegCmd : public RegistrationCommand
{
public:
	PointRegCmd() = delete;
	PointRegCmd(const PointRegCmd& other) = default;
	PointRegCmd& operator=(const PointRegCmd& other) = default;
	PointRegCmd(PointRegCmd&& other) = default;
	PointRegCmd& operator=(PointRegCmd&& other) = default;
	~PointRegCmd() = default;

	PointRegCmd(MOABEPointLight* _pLight);

	virtual void Execute() const override;

private:
	MOABEPointLight* pLight;
};

#endif // POINTREGCMD_H
