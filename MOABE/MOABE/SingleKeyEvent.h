#ifndef SINGLEKEYEVENT_H
#define SINGLEKEYEVENT_H

#include <Keyboard.h>
#include "KeyEventType.h"
#include <list>

class Inputable;

/// Represents a single keyboard event and its listeners.
/// 
/// @note This class is for internal use only. 
class SingleKeyEvent : public Align16
{
public:
    /// Default constructor deleted.
    SingleKeyEvent() = delete;
    /// Copy constructor deleted.
    SingleKeyEvent(const SingleKeyEvent& other) = delete;
    /// Copy assignment operator deleted.
    SingleKeyEvent& operator=(const SingleKeyEvent& other) = delete;
    /// Move constructor deleted.
    SingleKeyEvent(SingleKeyEvent&& other) = delete;
    /// Move assignment operator deleted.
    SingleKeyEvent& operator=(SingleKeyEvent&& other) = delete;
    /// Destructor.
    ~SingleKeyEvent();

    /// Constructs a SingleKeyEvent with the provided key.
    ///
    /// @param _myKey The key associated with the event.
    SingleKeyEvent(JAZUL_KEY _myKey);

    /// Processes the keyboard event.
    ///
    /// This function processes the keyboard event, notifying listeners accordingly.
    void ProcessKeyEvent();

    /// Registers a listener for the keyboard event.
    ///
    /// This function registers a listener to be notified when the keyboard event occurs.
    ///
    /// @param pInput Pointer to the inputable object to be notified.
    /// @param keyType The type of event to listen for (pressed or released).
    void RegisterKey(Inputable* pInput, EventType keyType);

    /// Deregisters a listener for the keyboard event.
    ///
    /// This function deregisters a listener from receiving notifications for the keyboard event.
    ///
    /// @param pInput Pointer to the inputable object to be removed from listeners.
    /// @param keyType The type of event to stop listening for (pressed or released).
    void DeregisterKey(Inputable* pInput, EventType keyType);

    /// Checks If Any Keys Have Been Pressed.
    void IsPressed();

    /// Checks If Any Keys Have Been Released.
    void IsReleased();

private:
    using KeyListeners = std::list<Inputable*>; ///< List of listeners for the keyboard event.
    bool isHeld; ///< Flag indicating whether the key is currently held.
    JAZUL_KEY myKey; ///< The key associated with the event.
    KeyListeners KeyPressedListeners; ///< List of listeners for key press events.
    KeyListeners KeyReleasedListeners; ///< List of listeners for key release events.

public:
    ///< Iterator type for the list of inputables
    /// Used by Drawables to track their place in the KeyListeners for quick deletion.
    /// @see Inputable::myDeleteRef
    using KeyListRef = KeyListeners::iterator; 
};


#endif // SINGLEKEYEVENT_H
