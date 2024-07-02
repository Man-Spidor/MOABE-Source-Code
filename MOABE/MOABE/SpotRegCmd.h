#ifndef SPOTREGCMD_H
#define SPOTREGCMD_H

#include "RegistrationCommand.h"

class MOABESpotLight;

class SpotRegCmd : public RegistrationCommand
{
public:
	SpotRegCmd() = delete;
	SpotRegCmd(const SpotRegCmd& other) = default;
	SpotRegCmd& operator=(const SpotRegCmd& other) = default;
	SpotRegCmd(SpotRegCmd&& other) = default;
	SpotRegCmd& operator=(SpotRegCmd&& other) = default;
	~SpotRegCmd() = default;

	SpotRegCmd(MOABESpotLight* _pLight);

	virtual void Execute() const override;

private:
	MOABESpotLight* pLight;
};
#endif // SPOTREGCMD_H
