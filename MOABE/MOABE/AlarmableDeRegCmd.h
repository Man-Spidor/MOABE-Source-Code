#ifndef ALARMABLEDEREGCMD_H
#define ALARMABLEDEREGCMD_H

#include "RegistrationCommand.h"

class Alarmable;

/// Registration command for deregistering alarmable objects.
/// 
/// @note This class is for internal use only.
class AlarmableDeRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    AlarmableDeRegCmd() = delete;
    /// Copy constructor.
    AlarmableDeRegCmd(const AlarmableDeRegCmd& other) = delete;
    /// Copy assignment operator.
    AlarmableDeRegCmd& operator=(const AlarmableDeRegCmd& other) = delete;
    /// Move constructor.
    AlarmableDeRegCmd(AlarmableDeRegCmd&& other) = delete;
    /// Move assignment operator.
    AlarmableDeRegCmd& operator=(AlarmableDeRegCmd&& other) = delete;
    /// Destructor.
    ~AlarmableDeRegCmd() = default;

    /// Constructs an AlarmableDeRegCmd object.
    ///
    /// @param _pAlarm Pointer to the Alarmable object to deregister.
    /// @param _myID The ID of the alarm.
    AlarmableDeRegCmd(Alarmable* _pAlarm, const unsigned int _myID);

    /// Executes the deregistration command.
    virtual void Execute() const override;

private:
    const unsigned int myID; ///< The ID of the alarm.
    Alarmable* pAlarm; ///< Pointer to the Alarmable object to deregister.
};

#endif // ALARMABLEDEREGCMD_H
