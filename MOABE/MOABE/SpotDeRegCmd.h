#ifndef SPOTDEREGCMD_H
#define SPOTDEREGCMD_H

#include "RegistrationCommand.h"

class MOABESpotLight;

class SpotDeRegCmd : public RegistrationCommand
{
public:
	SpotDeRegCmd() = delete;
	SpotDeRegCmd(const SpotDeRegCmd& other) = default;
	SpotDeRegCmd& operator=(const SpotDeRegCmd& other) = default;
	SpotDeRegCmd(SpotDeRegCmd&& other) = default;
	SpotDeRegCmd& operator=(SpotDeRegCmd&& other) = default;
	~SpotDeRegCmd() = default;

	SpotDeRegCmd(MOABESpotLight* _pLight);

	virtual void Execute() const override;

private:
	MOABESpotLight* pLight;
};

#endif // SPOTDEREGCMD_H
