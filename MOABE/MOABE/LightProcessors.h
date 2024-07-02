#ifndef LIGHTPROCESSORS_H
#define LIGHTPROCESSORS_H

#include "NormalProcessor.h"
#include "CullDistProcessor.h"
#include "CullViewProcessor.h"

class LightProcessors
{
public:
	static NormalProcessor NormalMode;
	static CullDistProcessor CullDistMode;
	static CullViewProcessor CullViewMode;
};

#endif // LIGHTPROCESSORS_H
