#include "PointLightTrackingCmd.h"

#include "MOABEPointLight.h"

PointLightTrackingCmd::PointLightTrackingCmd(MOABEPointLight& _Light, const Matrix* _TrackingMatrix) :
	LightOffset(),
	TrackingMatrix(_TrackingMatrix),
	Light(_Light)
{
}

void PointLightTrackingCmd::SetOffset(const Vect& _LightOffset)
{
	this->LightOffset = _LightOffset;
}

void PointLightTrackingCmd::SetTrackingMatrix(const Matrix* _TrackingMatrix)
{
	this->TrackingMatrix = _TrackingMatrix;
}

void PointLightTrackingCmd::UpdateLight()
{
	this->Light.SetPosition(this->TrackingMatrix->get(ROW_3) + this->LightOffset);
}
