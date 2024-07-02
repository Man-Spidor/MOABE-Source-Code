#ifndef ALARMLIST_H
#define ALARMLIST_H

#include "AlarmRegistrationData.h"

class Alarmable;
/// AlarmList Class
///
/// This class manages a list of alarms associated with an Alarmable object. It provides functionality
/// to register and deregister alarms, set their status, and manage delete references.
///
/// @note This class is for internal use only.
class AlarmList
{
public:
	static const int ALARM_NUMBER = 3;	// this number must always match the enum

public:
	AlarmList() = delete;
	AlarmList(const AlarmList& other) = default;
	AlarmList& operator=(const AlarmList& other) = default;
	AlarmList(AlarmList&& other) = default;
	AlarmList& operator=(AlarmList&& other) = default;
	~AlarmList() = default;

	AlarmList(Alarmable* _pAlarm);

	/// Register an alarm with the specified time.
	///
	/// This function registers an alarm with the given alarm number and time.
	///
	/// @param alarmNum The identifier of the alarm to register.
	/// @param time The time at which the alarm should trigger.
	void RegisterAlarm(ALARM_ID alarmNum, float time);

	/// Deregister the specified alarm.
	///
	/// This function deregisters the alarm associated with the given alarm number.
	///
	/// @param alarmNum The identifier of the alarm to deregister.
	void DeregisterAlarm(ALARM_ID alarmNum);

	/// Set the registration status of the specified alarm to registered.
	///
	/// This function sets the registration status of the alarm associated with the given alarm number
	/// to registered.
	///
	/// @param alarmNum The identifier of the alarm.
	void SetStatusRegistered(ALARM_ID alarmNum);

	/// Set the registration status of the specified alarm to deregistered.
	///
	/// This function sets the registration status of the alarm associated with the given alarm number
	/// to deregistered.
	///
	/// @param alarmNum The identifier of the alarm.
	void SetStatusDeregistered(ALARM_ID alarmNum);

	/// Checks the registration status to see if it is active.
	/// 
	/// @param alarmNum The identifier of the alarm.
	const bool AlarmActive(const unsigned int alarmNum) const;

	/// Set the delete reference for the specified alarm.
	///
	/// This function sets the delete reference for the alarm associated with the given alarm number.
	///
	/// @param deleteRef The delete reference to set.
	/// @param alarmNum The identifier of the alarm.
	void SetDeleteRef(AlarmableManager::AlarmableListRef deleteRef, ALARM_ID alarmNum);

	/// Get the delete reference for the specified alarm.
	///
	/// This function retrieves the delete reference for the alarm associated with the given alarm number.
	///
	/// @param alarmNum The identifier of the alarm.
	/// @return Reference to the delete reference.
	AlarmableManager::AlarmableListRef& GetDeleteRef(ALARM_ID alarmNum);

private:
	AlarmableRegData RegData[ALARM_NUMBER];

	Alarmable* pAlarm;
};

#endif // ALARMLIST_H
