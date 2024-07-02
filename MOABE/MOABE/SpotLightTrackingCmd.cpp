#include "SpotLightTrackingCmd.h"

#include "MOABESpotLight.h"

SpotLightTrackingCmd::SpotLightTrackingCmd(MOABESpotLight& _Light, const Matrix* _TrackingMatrix) :
	LightPosOffset(),
	LightLookOffset(),
	TrackingMatrix(_TrackingMatrix),
	Light(_Light)
{
}

void SpotLightTrackingCmd::SetLookOffset(const Vect& _LightLookOffset)
{
	this->LightLookOffset = _LightLookOffset;
}

void SpotLightTrackingCmd::SetPositionOffset(const Vect& _LightPosOffset)
{
	this->LightPosOffset = _LightPosOffset;
}

void SpotLightTrackingCmd::SetTrackingMatrix(const Matrix* _TrackingMatrix)
{
	this->TrackingMatrix = _TrackingMatrix;
}

void SpotLightTrackingCmd::UpdateLight()
{
	this->Light.SetLookAtTarget(this->LightLookOffset * *this->TrackingMatrix);
	this->Light.SetPosition(this->TrackingMatrix->get(ROW_3) + this->LightPosOffset);
}
