#include "SingleKeyEvent.h"
#include "GameObjectAttorney.h"

SingleKeyEvent::~SingleKeyEvent()
{
}

SingleKeyEvent::SingleKeyEvent(JAZUL_KEY _myKey) :
    isHeld(false),
    myKey(_myKey)
{
    // if the key is pressed at the time of creation, we know it being held
    if (Keyboard::GetKeyState(this->myKey))
        this->isHeld = true;
}

void SingleKeyEvent::ProcessKeyEvent()
{
    // is the key pressed?
    if (Keyboard::GetKeyState(this->myKey)) {
        // was it pressed last frame?
        if (!this->isHeld) {
            // Key was just pressed
            this->IsPressed();
            this->isHeld = true;
        }
    }
    // was it pressed last frame?
    else if (this->isHeld) {
        // key was just released
        this->IsReleased();
        this->isHeld = false;
    }
}

void SingleKeyEvent::RegisterKey(Inputable* pInput, EventType keyEvent)
{
    if (keyEvent == EventType::KEY_PRESS) {
        GameObjectAttorney::Input::SetDeleteRef(this->myKey, keyEvent, this->KeyPressedListeners.insert(this->KeyPressedListeners.end(), pInput), pInput);
    }
    else if (keyEvent == EventType::KEY_RELEASE) {
        GameObjectAttorney::Input::SetDeleteRef(this->myKey, keyEvent, this->KeyReleasedListeners.insert(this->KeyReleasedListeners.end(), pInput), pInput);
    }
    else {
        Trace::out("Error, not a valid keyboard event.");
        assert(false);
    }
}

void SingleKeyEvent::DeregisterKey(Inputable* pInput, EventType keyEvent)
{
    UNREFERENCED_PARAMETER(pInput);

    if (keyEvent == EventType::KEY_PRESS) {
        this->KeyPressedListeners.erase(GameObjectAttorney::Input::GetDeleteRef(this->myKey, keyEvent, pInput));
    }
    else if (keyEvent == EventType::KEY_RELEASE) {
        this->KeyPressedListeners.erase(GameObjectAttorney::Input::GetDeleteRef(this->myKey, keyEvent, pInput));
    }
    else {
        Trace::out("Error, not a valid keyboard event.");
        assert(false);
    }
}

void SingleKeyEvent::IsPressed()
{    
    for (auto pInput : this->KeyPressedListeners) {
        GameObjectAttorney::Input::KeyPressed(this->myKey, pInput);
    }
}

void SingleKeyEvent::IsReleased()
{
    for (auto pInput : this->KeyReleasedListeners) {
        GameObjectAttorney::Input::KeyReleased(this->myKey, pInput);
    }
}
