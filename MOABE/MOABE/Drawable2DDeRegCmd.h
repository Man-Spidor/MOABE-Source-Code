#ifndef DRAWABLE3DDEREGCMD_H
#define DRAWABLE3DDEREGCMD_H

#include "RegistrationCommand.h"

class Drawable;

class Drawable2DDeRegCmd : public RegistrationCommand
{
public:
	Drawable2DDeRegCmd() = default;
	Drawable2DDeRegCmd(const Drawable2DDeRegCmd& other) = default;
	Drawable2DDeRegCmd& operator=(const Drawable2DDeRegCmd& other) = default;
	Drawable2DDeRegCmd(Drawable2DDeRegCmd&& other) = default;
	Drawable2DDeRegCmd& operator=(Drawable2DDeRegCmd&& other) = default;
	~Drawable2DDeRegCmd() = default;

	Drawable2DDeRegCmd(Drawable* _pDrawble);

	virtual void Execute() const override;

private:
	Drawable* pDrawable;
};

#endif // DRAWABLE3DDEREGCMD_H
