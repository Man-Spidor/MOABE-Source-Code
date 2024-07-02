#ifndef LIGHTBLINKINGCMD_H
#define LIGHTBLINKINGCMD_H

#include "LightBehaviourCommand.h"
#include "LightAlarm.h"

class MOABELight;

/// Command for blinking light behaviour.
/// 
/// This class defines a blinking light behaviour where the light alternates between on and off states.
/// It uses LightAlarm to handle the timing of the blinking intervals.
/// 
/// @see LightAlarm
class LightBlinkingCmd : public LightBehaviourCommand
{
public:
	/// All the constructors are deleted since Light Behaviours exist on a per light basis.
	LightBlinkingCmd() = delete;
	LightBlinkingCmd(const LightBlinkingCmd& other) = delete;
	LightBlinkingCmd& operator=(const LightBlinkingCmd& other) = delete;
	LightBlinkingCmd(LightBlinkingCmd&& other) = delete;
	LightBlinkingCmd& operator=(LightBlinkingCmd&& other) = delete;
	~LightBlinkingCmd() = default;

	/// Constructor to initialize the command with a light.
	/// 
	/// @param _Light The light to be controlled by the blinking behaviour.
	LightBlinkingCmd(MOABELight& _Light);

	/// Starts The Behaviour
	virtual void StartBehaviour() override;
	/// Stops The Behaviour
	virtual void StopBehaviour() override;

	/// Set the on and off times for the blinking behaviour.
	/// 
	/// @param on_time The duration for which the light stays on.
	/// @param off_time The duration for which the light stays off.
	void SetOnOffTime(const float on_time, const float off_time);

private:
	/// Update Light Method Left Empty Since LightAlarm Handles Timing
	virtual void UpdateLight() override { };

	/// Behaviour Callback To Turn Light Off
	virtual void Callback0() override;

	/// Behaviour Callback To Turn Light On
	virtual void Callback1() override;
	
private:
	LightAlarm Alarm; ///< The alarm used for timing the blinking behaviour.
	MOABELight& Light; ///< Reference to the light being controlled.

	float onTime; ///< Duration for which the light stays on.
	float offTime; ///< Duration for which the light stays off.
};

#endif // LIGHTBLINKINGCMD_H
