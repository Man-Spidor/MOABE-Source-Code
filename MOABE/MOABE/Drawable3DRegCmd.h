#ifndef DRAWABLEREGCMD_H
#define DRAWABLEREGCMD_H

#include "RegistrationCommand.h"

class Drawable;

class Drawable3DRegCmd : public RegistrationCommand
{
public:
	Drawable3DRegCmd() = delete;
	Drawable3DRegCmd(const Drawable3DRegCmd& other) = default;
	Drawable3DRegCmd& operator=(const Drawable3DRegCmd& other) = default;
	Drawable3DRegCmd(Drawable3DRegCmd&& other) = default;
	Drawable3DRegCmd& operator=(Drawable3DRegCmd&& other) = default;
	~Drawable3DRegCmd() = default;

	Drawable3DRegCmd(Drawable* _pDrawable);

	virtual void Execute() const override;

private:
	Drawable* pDrawable;
};

#endif // DRAWABLEREGCMD_H
