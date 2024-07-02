#ifndef COLLIDABLEDEREGCMD_H
#define COLLIDABLEDEREGCMD_H

#include "RegistrationCommand.h"

class Collidable;


/// Registration command for deregistering collidable objects.
/// 
/// @note This class is for internal use only.
class CollidableDeRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    CollidableDeRegCmd() = delete;
    /// Copy constructor.
    CollidableDeRegCmd(const CollidableDeRegCmd& other) = delete;
    /// Copy assignment operator.
    CollidableDeRegCmd& operator=(const CollidableDeRegCmd& other) = delete;
    /// Move constructor.
    CollidableDeRegCmd(CollidableDeRegCmd&& other) = delete;
    /// Move assignment operator.
    CollidableDeRegCmd& operator=(CollidableDeRegCmd&& other) = delete;

    /// Destructor.
    ~CollidableDeRegCmd() = default;

    /// Constructs a CollidableDeRegCmd object.
    ///
    /// @param _pCol Pointer to the Collidable object to deregister.
    CollidableDeRegCmd(Collidable* _pCol);

    /// Executes the deregistration command.
    virtual void Execute() const override;

private:
    Collidable* pCol; ///< Pointer to the Collidable object to deregister.
};

#endif // COLLIDABLEDEREGCMD_H
