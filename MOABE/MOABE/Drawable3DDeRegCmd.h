#ifndef DRAWABLEDEREGCMD_H
#define DRAWABLEDEREGCMD_H

#include "RegistrationCommand.h"

class Drawable;

class Drawable3DDeRegCmd : public RegistrationCommand
{
public:
	Drawable3DDeRegCmd() = delete;
	Drawable3DDeRegCmd(const Drawable3DDeRegCmd& other) = default;
	Drawable3DDeRegCmd& operator=(const Drawable3DDeRegCmd& other) = default;
	Drawable3DDeRegCmd(Drawable3DDeRegCmd&& other) = default;
	Drawable3DDeRegCmd& operator=(Drawable3DDeRegCmd&& other) = default;
	~Drawable3DDeRegCmd() = default;

	Drawable3DDeRegCmd(Drawable* _pDrawble);

	virtual void Execute() const override;

private:
	Drawable* pDrawable;
};

#endif // DRAWABLEDEREGCMD_H
