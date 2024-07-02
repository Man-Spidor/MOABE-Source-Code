#ifndef SPOTLIGHTTRACKINGCMD_H
#define SPOTLIGHTTRACKINGCMD_H

#include "LightBehaviourCommand.h"
#include <Matrix.h>

class MOABESpotLight;

/// Command to track and update a spot light based on a tracking matrix.
/// 
/// This class updates the position and orientation of a spot light every frame based on a tracking matrix.
class SpotLightTrackingCmd : public LightBehaviourCommand
{
public:
    SpotLightTrackingCmd() = delete;
    SpotLightTrackingCmd(const SpotLightTrackingCmd& other) = delete;
    SpotLightTrackingCmd& operator=(const SpotLightTrackingCmd& other) = delete;
    SpotLightTrackingCmd(SpotLightTrackingCmd&& other) = delete;
    SpotLightTrackingCmd& operator=(SpotLightTrackingCmd&& other) = delete;
    ~SpotLightTrackingCmd() = default;

    /// Constructor to initialize the command with a light and tracking matrix.
    /// 
    /// @param _Light The spot light to be updated.
    /// @param TrackingMatrix Pointer to the matrix used for tracking.
    SpotLightTrackingCmd(MOABESpotLight& _Light, const Matrix* TrackingMatrix);

    /// Set the look offset of the light.
    /// 
    /// @param _LightLookOffset The look offset vector.
    void SetLookOffset(const Vect& _LightLookOffset);

    /// Set the position offset of the light.
    /// 
    /// @param _LightPosOffset The position offset vector.
    void SetPositionOffset(const Vect& _LightPosOffset);

    /// Set the tracking matrix.
    /// 
    /// @param _TrackingMatrix Pointer to the new tracking matrix.
    void SetTrackingMatrix(const Matrix* _TrackingMatrix);

private:
    /// Update the light based on the tracking matrix (overridden).
    virtual void UpdateLight() override;

private:
    Vect LightPosOffset; ///< The position offset of the light.
    Vect LightLookOffset; ///< The look offset of the light.
    const Matrix* TrackingMatrix; ///< Pointer to the tracking matrix.
    MOABESpotLight& Light; ///< Reference to the spot light.
};

#endif // SPOTLIGHTTRACKINGCMD_H
