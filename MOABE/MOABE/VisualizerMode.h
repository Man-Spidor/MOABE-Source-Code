#ifndef VISUALIZEMODE_H
#define VISUALIZEMODE_H

/// @brief Enumerates the different visualization modes.
enum class VisualizeMode
{
    DRAW_NONE,      ///< Ignores all draw requests.
    DRAW_DEFAULT,   ///< Processes every draw command it receives.
    DRAW_MARKERS,   ///< Processes only the marker draw commands.
    DRAW_COLLIDABLES ///< Shows only the base collision volume of each collidable.
};

#endif // VISUALIZEMODE_H
