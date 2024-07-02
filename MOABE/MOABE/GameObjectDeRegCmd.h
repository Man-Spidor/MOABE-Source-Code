#ifndef GAMEOBJECTDEREGCMD_H
#define GAMEOBJECTDEREGCMD_H

#include "RegistrationCommand.h"

class GameObject;


/// Registration command for deregistering game objects.
/// 
/// @note This class is for internal use only.
class GameObjectDeRegCmd : public RegistrationCommand
{
public:
    /// Default constructor.
    GameObjectDeRegCmd() = delete;
    /// Copy constructor.
    GameObjectDeRegCmd(const GameObjectDeRegCmd& other) = delete;
    /// Copy assignment operator.
    GameObjectDeRegCmd& operator=(const GameObjectDeRegCmd& other) = delete;
    /// Move constructor.
    GameObjectDeRegCmd(GameObjectDeRegCmd&& other) = delete;
    /// Move assignment operator.
    GameObjectDeRegCmd& operator=(GameObjectDeRegCmd&& other) = delete;
    /// Destructor.
    ~GameObjectDeRegCmd() = default;

    /// Constructs a GameObjectDeRegCmd object.
    ///
    /// @param _pGO Pointer to the GameObject to deregister.
    GameObjectDeRegCmd(GameObject* _pGO);

    /// Executes the deregistration command.
    virtual void Execute() const override;

private:
    GameObject* pGO; ///< Pointer to the GameObject to deregister.
};

#endif // GAMEOBJECTDEREGCMD_H
