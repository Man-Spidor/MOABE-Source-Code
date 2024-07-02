#ifndef DIRECTIONALDEREGCMD_H
#define DIRECTIONALDEREGCMD_H

#include "RegistrationCommand.h"

class MOABEDirectionalLight;

class DirectionalDeRegCmd : public RegistrationCommand
{
public:
	DirectionalDeRegCmd() = delete;
	DirectionalDeRegCmd(const DirectionalDeRegCmd& other) = default;
	DirectionalDeRegCmd& operator=(const DirectionalDeRegCmd& other) = default;
	DirectionalDeRegCmd(DirectionalDeRegCmd&& other) = default;
	DirectionalDeRegCmd& operator=(DirectionalDeRegCmd&& other) = default;
	~DirectionalDeRegCmd() = default;

	DirectionalDeRegCmd(MOABEDirectionalLight* _pLight);

	virtual void Execute() const override;

private:
	MOABEDirectionalLight* pLight;
};

#endif // DIRECTIONALDEREGCMD_H
