#ifndef INPUTREGDATA_H
#define INPUTREGDATA_H

#include "SingleKeyEvent.h"

class Inputable;
class InputableRegCmd;
class InputableDeRegCmd;

/// Class representing input registration data.
/// 
/// @note This class is for internal use only
class InputRegData
{
public:
    /// Default constructor.
    InputRegData() = default;
    /// Copy constructor.
    InputRegData(const InputRegData& other) = default;
    /// Copy assignment operator.
    InputRegData& operator=(const InputRegData& other) = default;
    /// Move constructor.
    InputRegData(InputRegData&& other) = default;
    /// Move assignment operator.
    InputRegData& operator=(InputRegData&& other) = default;
    /// Destructor.
    ~InputRegData();

    /// Constructor with parameters.
    ///
    /// @param key The key to register.
    /// @param ev The event type.
    /// @param pInput Pointer to the Inputable object.
    InputRegData(JAZUL_KEY key, EventType ev, Inputable* pInput);

    /// Submits the register command.
    void SubmitRegisterCmd();

    /// Submits the deregister command.
    void SubmitDeregisterCmd();

    SingleKeyEvent::KeyListRef keyDeleteRef; ///< Reference to the key list.
    Inputable* pInput; ///< Pointer to the Inputable object.
    InputableRegCmd* pRegCmd; ///< Pointer to the registration command.
    InputableDeRegCmd* pDeRegCmd; ///< Pointer to the deregistration command.
};

#endif // INPUTREGDATA_H
