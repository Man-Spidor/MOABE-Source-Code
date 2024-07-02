#ifndef LIGHTSTATICCMD_H
#define LIGHTSTATICCMD_H

#include "LightBehaviourCommand.h"

/// Command for static light behaviour (no updates).
/// 
/// This class defines a static light behaviour where the light does not change over time.
/// It inherits from LightBehaviourCommand and provides an empty implementation of the UpdateLight method.
/// 
/// This class is totally locked away as it is the default behaviour of every light.
/// As such there is no need to create copies or extensions of this class as all 
/// references to this command point to the same command in LightManager
/// 
/// @see LightManager
class LightStaticCmd : public LightBehaviourCommand
{
    friend class LightManager;

private:
    LightStaticCmd() = default;
    LightStaticCmd(const LightStaticCmd& other) = default;
    LightStaticCmd& operator=(const LightStaticCmd& other) = default;
    LightStaticCmd(LightStaticCmd&& other) = default;
    LightStaticCmd& operator=(LightStaticCmd&& other) = default;
    ~LightStaticCmd() = default;

    /// Update the light (does nothing).
    /// 
    /// This method is overridden from LightBehaviourCommand and provides an empty implementation,
    /// indicating that the light remains static and does not require updates.
    virtual void UpdateLight() override { }
};

#endif // LIGHTSTATICCMD_H
