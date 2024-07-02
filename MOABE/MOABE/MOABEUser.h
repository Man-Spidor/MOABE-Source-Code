#ifndef MOABEUSER_H
#define MOABEUSER_H

#include "Engine.h"

/// @brief Abstract base class for user-defined game behaviors.
///
/// This class provides virtual functions that users must implement to define any starting, loading, and ending behavior of their game.
/// These functions include game start, game end, and loading all content.
class MOABEUser
{
public:
    /// @brief Default constructor.
    MOABEUser() = default;

    /// @brief Default copy constructor.
    /// @param other The other MOABEUser to copy from.
    MOABEUser(const MOABEUser& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other MOABEUser to copy from.
    /// @return A reference to this MOABEUser.
    MOABEUser& operator=(const MOABEUser& other) = default;

    /// @brief Default move constructor.
    /// @param other The other MOABEUser to move from.
    MOABEUser(MOABEUser&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other MOABEUser to move from.
    /// @return A reference to this MOABEUser.
    MOABEUser& operator=(MOABEUser&& other) = default;

    /// @brief Destructor.
    ~MOABEUser() = default;

    /// @brief User-defined function called at the start of the game.
    ///
    /// Users should implement this function to define the behavior that occurs when the game starts.
    /// 
    /// @note this function is called BEFORE any Graphical initialization, so do not place Graphics related startups here
    virtual void GameStart() = 0;

    /// @brief User-defined function called at the end of the game.
    ///
    /// Users should implement this function to define the behavior that occurs when the game ends.
    virtual void GameEnd() = 0;

    /// @brief User-defined function called when loading all content.
    ///
    /// Users should implement this function to define the behavior for loading all game content.
    virtual void LoadAllContent() = 0;
};

#endif // MOABEUSER_H
