#ifndef DRAWABLE2DREGCMD_H
#define DRAWABLE2DREGCMD_H

#include "RegistrationCommand.h"

class Drawable;

class Drawable2DRegCmd : public RegistrationCommand
{
public:
	Drawable2DRegCmd() = default;
	Drawable2DRegCmd(const Drawable2DRegCmd& other) = default;
	Drawable2DRegCmd& operator=(const Drawable2DRegCmd& other) = default;
	Drawable2DRegCmd(Drawable2DRegCmd&& other) = default;
	Drawable2DRegCmd& operator=(Drawable2DRegCmd&& other) = default;
	~Drawable2DRegCmd() = default;

	Drawable2DRegCmd(Drawable* _pDrawble);

	virtual void Execute() const override;

private:
	Drawable* pDrawable;
};

#endif // DRAWABLE2DREGCMD_H
