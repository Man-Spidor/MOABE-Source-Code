#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "FreezeTime.h"

/// Class responsible for managing game time.
class TimeManager
{
	friend class TimeAttorney;
private:
	TimeManager() = default;

	/// Copy constructor is deleted to prevent unintended copying.
	TimeManager(const TimeManager& other) = delete;

	/// Copy assignment operator is deleted to prevent unintended copying.
	TimeManager& operator=(const TimeManager& other) = delete;

	/// Move constructor is deleted to prevent unintended moves.
	TimeManager(TimeManager&& other) = delete;

	/// Move assignment operator is deleted to prevent unintended moves.
	TimeManager& operator=(TimeManager&& other) = delete;

	/// Destructor.
	~TimeManager() = default;

	/// Processes the game time.
	static void ProcessTime();

	/// Initializes the time manager.
	static void Initialize();

	/// Deletes the time manager.
	static void Delete();

public:
	/// Gets the current game time.
	/// 
	/// This function returns the current game time.
	/// 
	/// @return The current game time
	static const float GetTime();

	/// Gets the frame time.
	/// 
	/// This function returns the frame time.
	/// 
	/// @return The frame time
	static const float GetFrameTime();

private:
	/// Gets the singleton instance of the time manager.
	static TimeManager& Instance();

	static TimeManager* instance; ///< Pointer to the singleton instance

	static float prevTime; ///< Previous game time
	static float currTime; ///< Current game time
	static float frameTime; ///< Frame time

	static FreezeTime timeFreeze; ///< Freeze time manager
};

#endif // TIMEMANAGER_H
