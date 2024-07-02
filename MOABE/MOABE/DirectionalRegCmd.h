#ifndef DIRECTIONALREGCMD_H
#define DIRECTIONALREGCMD_H

#include "RegistrationCommand.h"

class MOABEDirectionalLight;

class DirectionalRegCmd : public RegistrationCommand
{
public:
	DirectionalRegCmd() = delete;
	DirectionalRegCmd(const DirectionalRegCmd& other) = default;
	DirectionalRegCmd& operator=(const DirectionalRegCmd& other) = default;
	DirectionalRegCmd(DirectionalRegCmd&& other) = default;
	DirectionalRegCmd& operator=(DirectionalRegCmd&& other) = default;
	~DirectionalRegCmd() = default;

	DirectionalRegCmd(MOABEDirectionalLight* _pLight);

	virtual void Execute() const override;

private:
	MOABEDirectionalLight* pLight;
};

#endif // DIRECTIONALREGCMD_H
