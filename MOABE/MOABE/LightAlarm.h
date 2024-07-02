#ifndef LIGHTALARM_H
#define LIGHTALARM_H

#include "Alarmable.h"

class LightBehaviourCommand;

/// Alarm Class made for Light Behaviours
/// 
/// A Homebrewed Alarm Class Made For Light Behaviours to have timed behaviour while 
/// outsourcing the time keeping out to MOABE's built-in AlarmableManager
/// 
/// 
/// 
/// ### Usage Example:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// class LightBlinkingCmd
/// {
///		//...
///		
///		LightAlarm alarm;
///		MOABELight& Light;
/// 
///		//...
/// 
///		virtual void StartBehaviour() override {
///			// Starts the alarm to call LightBlinkingCmd::Callback0() in 3 seconds
///			this->alarm.StartAlarm(0, 3.0f);
///		}
///		
///		virtual void Callback0() override {
///			// Turns the light off then sets a timer to turn it back on in 0.5 seconds
///			this->Light.TurnOff();
///			this->alarm.StartAlarm(1, 3.0f);
///		}
/// 
///		virtual void Callback0() override {
///			// Turns the light off then sets a timer to turn it back on in 0.5 seconds
///			this->Light.TurnOn();
///			this->alarm.StartAlarm(0, 3.0f);
///		}
/// }
/// 
/// class LightAlarm
/// {
///		virtual void Alarm0 override {
///			BehaviourCallback.Callback0();
///		}
/// 
///		virtual void Alarm1 override {
///			BehaviourCallback.Callback1();
///		}
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
/// @see Alarmable
/// @see AlarmableManager
/// @see LightBlinkingCmd
class LightAlarm : public Alarmable
{
public:
	/// All the constructors are deleted since LightAlarms exist on a per light basis.
	LightAlarm() = delete;
	LightAlarm(const LightAlarm& other) = delete;
	LightAlarm& operator=(const LightAlarm& other) = delete;
	LightAlarm(LightAlarm&& other) = delete;
	LightAlarm& operator=(LightAlarm&& other) = delete;
	~LightAlarm() = default;

	/// Default Constructor
	/// 
	/// @param _BehaviourCallBack Reference To The Light Behaviour
	LightAlarm(LightBehaviourCommand& _BehaviourCallBack);

	/// Begins The Alarm Timer
	/// 
	/// @note The Alarm Number Coincide With The Callback Number. Take this into 
	/// consideration when designing your Light Behaviour Command
	/// @see LightBlinkingCmd For Usage Example
	/// 
	/// @param alarmNum The Alarm To Be Started
	/// @param timer How Long The Alarm Should Be Set For
	void StartAlarm(const unsigned int alarmNum, const float timer);

	/// Stops The Alarm Timer
	/// 
	/// @note The Alarm Number Coincide With The Callback Number. Take this into 
	/// consideration when designing your Light Behaviour Command
	/// @see LightBlinkingCmd For Usage Example
	/// 
	/// @param alarmNum The Alarm To Be Stopped
	void CancelAlarm(const unsigned int alarmNum);

	/// Checks the registration status to see if it is active.
	/// 
	/// @param alarmNum The identifier of the alarm.
	const bool AlarmActive(const unsigned int alarmNum) const;

private:
	/// Alarms Which When Triggered Callback to the LightBehaviour
	/// 
	/// @note The Alarm Number Coincide With The Callback Number. Take this into 
	/// consideration when designing your Light Behaviour Command
	/// @see LightBlinkingCmd For Usage Example
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// 
	/// void Alarm0 {
	///		BehaviourCallback.Callback0();
	/// }
	/// 
	///	// ...
	/// };
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	virtual void Alarm0() override;
	/// Alarm which when triggered callbacks to the light behaviour (Callback1).
	virtual void Alarm1() override;
	/// Alarm which when triggered callbacks to the light behaviour (Callback2).
	virtual void Alarm2() override;

private:
	LightBehaviourCommand& BehaviourCallback; ///< Reference to the light behaviour callback.
};

#endif // LIGHTALARM_H
