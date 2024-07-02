#ifndef INPUTABLEDEREGCMD_H
#define INPUTABLEDEREGCMD_H

#include "RegistrationCommand.h"
#include "Keyboard.h"
#include "KeyEventType.h"

class Inputable;

/// @note This class is for internal use only.

/// Registration command for deregistering inputable objects.
class InputableDeRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    InputableDeRegCmd() = delete;
    /// Copy constructor.
    InputableDeRegCmd(const InputableDeRegCmd& other) = delete;
    /// Copy assignment operator.
    InputableDeRegCmd& operator=(const InputableDeRegCmd& other) = delete;
    /// Move constructor.
    InputableDeRegCmd(InputableDeRegCmd&& other) = delete;
    /// Move assignment operator.
    InputableDeRegCmd& operator=(InputableDeRegCmd&& other) = delete;
    /// Destructor.
    ~InputableDeRegCmd() = default;

    /// Constructs an InputableDeRegCmd object.
    ///
    /// @param key The key to deregister.
    /// @param keyEvent The event type.
    /// @param pInput Pointer to the Inputable object to deregister.
    InputableDeRegCmd(JAZUL_KEY key, EventType keyEvent, Inputable* pInput);

    /// Executes the deregistration command.
    virtual void Execute() const override;

private:
    JAZUL_KEY key; ///< The key to deregister.
    EventType keyEvent; ///< The event type.
    Inputable* pInput; ///< Pointer to the Inputable object to deregister.
};

#endif // INPUTABLEDEREGCMD_H
