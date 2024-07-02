#ifndef ALARMABLE_H
#define ALARMABLE_H

#include "AlarmList.h"

class AlarmableRegCmd;
class AlarmableDeRegCmd;

/// Contains All Alarm Functionality 
/// 
/// ### Usage Example:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// // Creating an instance of a class derived from Alarmable
/// class MyGameObject : public GameObject {
/// 	// ...
/// };
/// 
/// // Registering an alarm
/// void MyGameObject::SceneEntry() {
///		// ...
///		Alarmable::RegisterAlarm(0, 5.0f); // Registering alarm 0 to trigger after 5 seconds
///		// ... 
///		
///		// Deregistering an alarm
///		Alarmable::DeregisterAlarm(0);
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
/// This is the class responsible for creating alarms for any GameObject.
/// @warning THE MAXIMUM NUMBER OF ALARMS IS 3. ATTEMPTING TO CREATE MORE ALARMS THAN THAT WILL 
/// CAUSE A CRASH. 
class Alarmable : public Align16
{
	/// GameObjectAttorney class restricts access to private Alarmable Methods
	friend class GameObjectAttorney;
public:
	/// Default Constructor
	Alarmable();
	/// Copy Constructor
	Alarmable(const Alarmable& other) = default;
	/// Copy Assignment
	Alarmable& operator=(const Alarmable& other) = default;
	/// Move Constructor
	Alarmable(Alarmable&& other) = default;
	/// Move Assignment
	Alarmable& operator=(Alarmable&& other) = default;
	/// Destructor
	virtual ~Alarmable() = default;

private:
	// Registration Functions
	void SetRegStatusRegistered(const unsigned int alarmNum);
	void SetRegStatusDeregistered(const unsigned int alarmNum);

	void SetDeleteRef(AlarmableManager::AlarmableListRef deleteRef, const unsigned int alarmNum);
	AlarmableManager::AlarmableListRef& GetDeleteRef(const unsigned int alarmNum);
	
	// Alarm Functions
	void TriggerAlarm(const unsigned int alarmNum);
	virtual void Alarm0();
	virtual void Alarm1();
	virtual void Alarm2();
	
protected:
	// Registration Functions
	/// Register an alarm with a specified time
	/// 
	/// @param alarmNum The alarm number
	/// @param time The time for the alarm
	void RegisterAlarm(const unsigned int alarmNum, float time);

	/// Deregister the specified alarm
	/// 
	/// @param alarmNum The alarm number
	void DeregisterAlarm(const unsigned int alarmNum);

	/// Checks the registration status to see if it is active.
	/// 
	/// @param alarmNum The identifier of the alarm.
	const bool AlarmActive(const unsigned int alarmNum) const;

private:
	AlarmList alarmList;
};

#endif // ALARMABLE_H
