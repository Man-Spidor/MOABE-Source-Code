#ifndef COLLIDABLEREGCMD_H
#define COLLIDABLEREGCMD_H

#include "RegistrationCommand.h"

class Collidable;

/// Registration command for registering collidable objects.
/// 
/// @note This class is for internal use only.
class CollidableRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    CollidableRegCmd() = delete;
    /// Copy constructor.
    CollidableRegCmd(const CollidableRegCmd& other) = delete;
    /// Copy assignment operator.
    CollidableRegCmd& operator=(const CollidableRegCmd& other) = delete;
    /// Move constructor.
    CollidableRegCmd(CollidableRegCmd&& other) = delete;
    /// Move assignment operator.
    CollidableRegCmd& operator=(CollidableRegCmd&& other) = delete;
    /// Destructor.
    ~CollidableRegCmd() = default;

    /// Constructs a CollidableRegCmd object.
    ///
    /// @param _pCol Pointer to the Collidable object to register.
    CollidableRegCmd(Collidable* _pCol);

    /// Executes the registration command.
    virtual void Execute() const override;

private:
    Collidable* pCol; ///< Pointer to the Collidable object to register.
};

#endif // COLLIDABLEREGCMD_H
