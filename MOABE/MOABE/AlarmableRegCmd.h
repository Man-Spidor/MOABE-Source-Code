#ifndef ALARMABLEREGCMD_H
#define ALARMABLEREGCMD_H

#include "RegistrationCommand.h"

class Alarmable;


/// Registration command for registering alarmable objects.
/// 
/// @note This class is for internal use only.
class AlarmableRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    AlarmableRegCmd() = delete;
    /// Copy constructor.
    AlarmableRegCmd(const AlarmableRegCmd& other) = delete;
    /// Copy assignment operator.
    AlarmableRegCmd& operator=(const AlarmableRegCmd& other) = delete;
    /// Move constructor.
    AlarmableRegCmd(AlarmableRegCmd&& other) = delete;
    /// Move assignment operator.
    AlarmableRegCmd& operator=(AlarmableRegCmd&& other) = delete;
    /// Destructor.
    ~AlarmableRegCmd() = default;

    /// Constructs an AlarmableRegCmd object.
    ///
    /// @param _pAlarm Pointer to the Alarmable object to register.
    /// @param _myID The ID of the alarm.
    AlarmableRegCmd(Alarmable* _pAlarm, const unsigned int _myID);

    /// Sets the time for the alarm.
    ///
    /// @param _time The time for the alarm.
    void SetTime(const float _time);

    /// Executes the registration command.
    virtual void Execute() const;

private:
    const unsigned int myID; ///< The ID of the alarm.
    Alarmable* pAlarm; ///< Pointer to the Alarmable object to register.
    float time; ///< The time for the alarm.
};

#endif // ALARMABLEREGCMD_H
