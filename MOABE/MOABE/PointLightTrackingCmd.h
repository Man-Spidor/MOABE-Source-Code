#ifndef LIGHTTRACKINGCMD_H
#define LIGHTTRACKINGCMD_H

#include "LightBehaviourCommand.h"

#include <Matrix.h>

class MOABEPointLight;

class PointLightTrackingCmd : public LightBehaviourCommand
{
public:
	PointLightTrackingCmd() = delete;
	PointLightTrackingCmd(const PointLightTrackingCmd& other) = delete;
	PointLightTrackingCmd& operator=(const PointLightTrackingCmd& other) = delete;
	PointLightTrackingCmd(PointLightTrackingCmd&& other) = delete;
	PointLightTrackingCmd& operator=(PointLightTrackingCmd&& other) = delete;
	~PointLightTrackingCmd() = default;

	/// Constructor to initialize the command with a light and the matrix to be tracked to.
	/// 
	/// @param _Light The point light to be updated.
	/// @param _TrackingMatrix Pointer to the matrix used for tracking.
	PointLightTrackingCmd(MOABEPointLight& _Light, const Matrix* _TrackingMatrix);

	/// Set the offset of the light.
	/// 
	/// @param _LightOffset The offset vector.
	void SetOffset(const Vect& _LightOffset);

	/// Set the tracking matrix.
	/// 
	/// @param _TrackingMatrix Pointer to the new tracking matrix.
	void SetTrackingMatrix(const Matrix* _TrackingMatrix);

private:
	/// Update the light based on the tracking matrix (overridden).
	virtual void UpdateLight() override;

private:
	Vect LightOffset; ///< The offset of the light.
	const Matrix* TrackingMatrix; ///< Pointer to the tracking matrix.
	MOABEPointLight& Light; ///< Reference to the point light.
};

#endif // LIGHTTRACKINGCMD_H
