#ifndef ALARMABLEMANAGER_H
#define ALARMABLEMANAGER_H

#include <map>

class Alarmable;

/// Manages alarmable objects and their alarms.
///
/// @note This class is for internal use only.
class AlarmableManager : public Align16 
{
public:
    /// Default constructor.
    AlarmableManager() = default;
    /// Copy constructor defaulted.
    AlarmableManager(const AlarmableManager& other) = delete;
    /// Copy assignment operator defaulted.
    AlarmableManager& operator=(const AlarmableManager& other) = delete;
    /// Move constructor defaulted.
    AlarmableManager(AlarmableManager&& other) = delete;
    /// Move assignment operator defaulted.
    AlarmableManager& operator=(AlarmableManager&& other) = delete;
    /// Destructor.
    ~AlarmableManager() = default;

    /// Clears The Registered Alarms and Resets Their Registration Status
    void ClearAlarms();

    /// Registers an alarm for an alarmable object.
    ///
    /// @param time The time for the alarm.
    /// @param pAlarm Pointer to the alarmable object.
    /// @param alarmNum The alarm number.
    void Register(const float time, Alarmable* pAlarm, const unsigned int alarmNum);

    /// Deregisters an alarm for an alarmable object.
    ///
    /// @param pAlarm Pointer to the alarmable object.
    /// @param alarmNum The alarm number.
    void Deregister(Alarmable* pAlarm, const unsigned int alarmNum);

    /// Processes alarms.
    void ProcessAlarms();

private:
    using AlarmEvent = std::pair<Alarmable*, const unsigned int>; ///< Pair of alarmable object and alarm number.
    using TimelineMap = std::multimap<const float, AlarmEvent>; ///< Timeline map for alarms.
    TimelineMap timeLine; ///< Timeline map for alarms.
public:
    ///< Iterator type for the list of AlarmRegData
    /// Used by Drawables to track their place in the TimelineMap for quick deletion.
    /// @see AlarmRegData::myDeleteRef
    using AlarmableListRef = TimelineMap::iterator; 
};


#endif // ALARMABLEMANAGER_H
