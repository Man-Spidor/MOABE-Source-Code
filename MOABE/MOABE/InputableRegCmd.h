#ifndef INPUTABLEREGCMD_H
#define INPUTABLEREGCMD_H

#include "RegistrationCommand.h"
#include "Keyboard.h"
#include "KeyEventType.h"

class Inputable;

/// Registration command for inputable objects.
/// 
/// @note This class is for internal use only.
class InputableRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    InputableRegCmd() = delete;
    /// Copy constructor.
    InputableRegCmd(const InputableRegCmd& other) = delete;
    /// Copy assignment operator.
    InputableRegCmd& operator=(const InputableRegCmd& other) = delete;
    /// Move constructor.
    InputableRegCmd(InputableRegCmd&& other) = delete;
    /// Move assignment operator.
    InputableRegCmd& operator=(InputableRegCmd&& other) = delete;
    /// Destructor.
    ~InputableRegCmd() = default;

    /// Constructs an InputableRegCmd object.
    ///
    /// @param key The key to register.
    /// @param keyEvent The event type.
    /// @param pInput Pointer to the Inputable object to register.
    InputableRegCmd(JAZUL_KEY key, EventType keyEvent, Inputable* pInput);

    /// Executes the registration command.
    virtual void Execute() const override;

private:
    JAZUL_KEY key; ///< The key to register.
    EventType keyEvent; ///< The event type.
    Inputable* pInput; ///< Pointer to the Inputable object to register.
};

#endif // INPUTABLEREGCMD_H
