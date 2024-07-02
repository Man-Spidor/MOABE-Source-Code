#ifndef GAMEOBJECTREGCMD_H
#define GAMEOBJECTREGCMD_H

#include "RegistrationCommand.h"

class GameObject;


/// Registration command for registering game objects.
/// 
/// @note This class is for internal use only.
class GameObjectRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    GameObjectRegCmd() = delete;
    /// Copy constructor.
    GameObjectRegCmd(const GameObjectRegCmd& other) = delete;
    /// Copy assignment operator.
    GameObjectRegCmd& operator=(const GameObjectRegCmd& other) = delete;
    /// Move constructor.
    GameObjectRegCmd(GameObjectRegCmd&& other) = delete;
    /// Move assignment operator.
    GameObjectRegCmd& operator=(GameObjectRegCmd&& other) = delete;
    /// Destructor.
    ~GameObjectRegCmd() = default;

    /// Constructs a GameObjectRegCmd object.
    ///
    /// @param _pGO Pointer to the GameObject to register.
    GameObjectRegCmd(GameObject* _pGO);

    /// Executes the registration command.
    virtual void Execute() const override;

private:
    GameObject* pGO; ///< Pointer to the GameObject to register.
};

#endif // GAMEOBJECTREGCMD_H
