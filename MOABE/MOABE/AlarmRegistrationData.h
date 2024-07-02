#ifndef REGISTRATIONDATA_H
#define REGISTRATIONDATA_H

#include "RegistrationStatus.h"
#include "AlarmableManager.h"
#include "AlarmID.h"

class Alarmable;
class AlarmableRegCmd;
class AlarmableDeRegCmd;

/// Manages the registration data for an alarmable object.
///
/// @note This class is for internal use only.
class AlarmableRegData : public Align16
{
public:
    /// Default constructor.
    AlarmableRegData();
    /// Copy constructor defaulted.
    AlarmableRegData(const AlarmableRegData& other) = default;
    /// Copy assignment operator defaulted.
    AlarmableRegData& operator=(const AlarmableRegData& other) = default;
    /// Move constructor defaulted.
    AlarmableRegData(AlarmableRegData&& other) = default;
    /// Move assignment operator defaulted.
    AlarmableRegData& operator=(AlarmableRegData&& other) = default;
    /// Destructor.
    ~AlarmableRegData();

    /// Sets the alarmable object and its ID.
    ///
    /// @param _pAlarm Pointer to the alarmable object.
    /// @param _myID The ID of the alarm.
    void SetAlarmable(Alarmable* _pAlarm, ALARM_ID _myID);

    /// Sets the registration status to registered.
    void SetStatusRegistered();

    /// Sets the registration status to deregistered.
    void SetStatusDeregistered();

    /// Returns True If Alarm is Active, False Otherwise
    const bool isActive() const;

    /// Sends the registration command for the alarmable object.
    ///
    /// @param time The time for the alarm.
    void SendRegCmd(float time);

    /// Sends the deregistration command for the alarmable object.
    void SendDeRegCmd();

    /// Sets the reference for deletion.
    ///
    /// @param deleteRef Reference for deletion.
    void SetDeleteRef(AlarmableManager::AlarmableListRef deleteRef);

    /// Retrieves the reference for deletion.
    ///
    /// @return Reference for deletion.
    AlarmableManager::AlarmableListRef& GetDeleteRef();

private:
    /// Gets the absolute time.
    ///
    /// @param relTime The relative time.
    ///
    /// @return The absolute time.
    const float privGetAbsTime(float relTime);

private:
    ALARM_ID myID; ///< The ID of the alarm.
    Alarmable* pAlarm; ///< Pointer to the alarmable object.
    RegistrationStatus regStatus; ///< The registration status.
    AlarmableRegCmd* pRegCmd; ///< Pointer to the registration command.
    AlarmableDeRegCmd* pDeRegCmd; ///< Pointer to the deregistration command.
    AlarmableManager::AlarmableListRef myDeleteRef; ///< Reference for deletion.
};


#endif // REGISTRATIONDATA_H