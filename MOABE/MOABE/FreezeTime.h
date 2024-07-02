#ifndef FREEZETIME_H
#define FREEZETIME_H

#include <Keyboard.h>

/// Utility class for managing time freezing in the game.
class FreezeTime
{
public:
	/// Default constructor.
	FreezeTime();
	/// Copy constructor is deleted to prevent unintended copying.
	FreezeTime(const FreezeTime& other) = delete;
	/// Copy assignment operator is deleted to prevent unintended copying.
	FreezeTime& operator=(const FreezeTime& other) = delete;
	/// Move constructor is deleted to prevent unintended moves.
	FreezeTime(FreezeTime&& other) = delete;
	/// Move assignment operator is deleted to prevent unintended moves.
	FreezeTime& operator=(FreezeTime&& other) = delete;
	/// Destructor.
	~FreezeTime() = default;

	/// Computes the game time considering time freezing.
	/// 
	/// This function calculates the current game time considering time freezing.
	/// 
	/// @param prevTime The previous game time before the update
	/// @return The current game time
	float ComputeGameTime(float prevTime);

private:
	/// Checks if a key is released.
	bool HackedKeyRelease(JAZUL_KEY k);

	/// Tests for freeze keys.
	void TestForFreezeKeys();

private:
	static const JAZUL_KEY FREEZE_KEY = JAZUL_KEY::KEY_LEFT_BRACKET; ///< Key to toggle time freezing
	static const JAZUL_KEY SINGLE_FRAME_KEY = JAZUL_KEY::KEY_RIGHT_BRACKET; ///< Key to advance by single frame

	static const float DEAD_TIME_THRESHOLD; ///< Threshold for dead time
	static const float DEFAULT_FRAME_TIME; ///< Default frame time

	float totalFrozenTime; ///< Total frozen time
	bool freezeActive; ///< Flag indicating if time freezing is active
};

#endif // FREEZETIME_H
