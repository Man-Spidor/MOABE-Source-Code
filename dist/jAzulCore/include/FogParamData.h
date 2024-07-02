#ifndef FOGDATA_H
#define FOGDATA_H

#include <Vect.h>

struct FogData 
{
	FogData() : FogStart((float)UINT_MAX), FogRange((float)UINT_MAX), FogColor()
	{};

	float FogStart = (float)UINT_MAX;
	float FogRange = (float)UINT_MAX;
	Vect FogColor;
};

#endif // FOGDATA_H