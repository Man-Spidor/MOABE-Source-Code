#ifndef KEYEVENTMANAGER_H
#define KEYEVENTMANAGER_H

#include <map>
#include <Keyboard.h>

#include "KeyEventType.h"

class Inputable;
class SingleKeyEvent;

/// Manages keyboard events and their corresponding listeners.
///
/// @note This class is for internal use only. 
class KeyEventManager : public Align16
{
public:
    /// Default constructor.
    KeyEventManager() = default;
    /// Copy constructor deleted.
    KeyEventManager(const KeyEventManager& other) = delete;
    /// Copy assignment operator deleted.
    KeyEventManager& operator=(const KeyEventManager& other) = delete;
    /// Move constructor deleted.
    KeyEventManager(KeyEventManager&& other) = delete;
    /// Move assignment operator deleted.
    KeyEventManager& operator=(KeyEventManager&& other) = delete;
    /// Destructor.
    ~KeyEventManager();

    /// Processes keyboard inputs.
    ///
    /// This function processes keyboard inputs, triggering events accordingly.
    /// Called once per frame.
    void ProcessInputs();

    /// Registers a listener for a specific keyboard event.
    ///
    /// This function registers a listener to be notified when a specific keyboard event occurs.
    ///
    /// @param key The key to listen for.
    /// @param ev The type of event to listen for.
    /// @param pInput Pointer to the inputable object to be notified.
    void RegisterKey(JAZUL_KEY key, EventType ev, Inputable* pInput);

    /// Deregisters a listener for a specific keyboard event.
    ///
    /// This function deregisters a listener from receiving notifications for a specific keyboard event.
    ///
    /// @param key The key to stop listening for.
    /// @param ev The type of event to stop listening for.
    /// @param pInput Pointer to the inputable object to be removed from listeners.
    void DeregisterKey(JAZUL_KEY key, EventType ev, Inputable* pInput);

private:
    using KeyList = std::multimap<JAZUL_KEY, SingleKeyEvent*>; ///< Multimap to store key events and their listeners.
    KeyList keyList; ///< List of keyboard events and their listeners.
};

#endif // KEYEVENTMANAGER_H
