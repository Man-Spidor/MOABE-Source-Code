#ifndef POINTDEREGCMD_H
#define POINTDEREGCMD_H

#include "RegistrationCommand.h"

class MOABEPointLight;

class PointDeRegCmd : public RegistrationCommand
{
public:
	PointDeRegCmd() = delete;
	PointDeRegCmd(const PointDeRegCmd& other) = default;
	PointDeRegCmd& operator=(const PointDeRegCmd& other) = default;
	PointDeRegCmd(PointDeRegCmd&& other) = default;
	PointDeRegCmd& operator=(PointDeRegCmd&& other) = default;
	~PointDeRegCmd() = default;

	PointDeRegCmd(MOABEPointLight* _pLight);

	virtual void Execute() const override;

private:
	MOABEPointLight* pLight;
};

#endif // POINTDEREGCMD_H
