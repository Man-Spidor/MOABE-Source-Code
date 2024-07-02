#include "FreezeTime.h"
#include "TimeManager.h"
#include "MOABEAttorney.h"

const float FreezeTime::DEAD_TIME_THRESHOLD = 0.1f;
const float FreezeTime::DEFAULT_FRAME_TIME = 1.0f / 60.0f;

FreezeTime::FreezeTime() :
    totalFrozenTime(0.0f),
    freezeActive(false)
{
    assert(DEFAULT_FRAME_TIME < DEAD_TIME_THRESHOLD);

    freezeActive = false;
    totalFrozenTime = 0;
}

float FreezeTime::ComputeGameTime(float prevTime)
{
    TestForFreezeKeys(); // time may pass f freeze mode activated

    // Adjust real time to actual game time
    float currGameTime = MOABEAttorney::GetTimeInSeconds() - totalFrozenTime;

    // test if any extra frozen time occurred since prev_gametime
    float frameTime = currGameTime - prevTime;
    if (frameTime > DEAD_TIME_THRESHOLD)
    {
        float extraFrozenTime = frameTime - DEFAULT_FRAME_TIME;

        totalFrozenTime += extraFrozenTime; // new frozen time total
        currGameTime -= extraFrozenTime;   // adjust curr_gametime 

        Trace::out("Current Game Time[%f]\n", currGameTime);
    }

    return currGameTime; // New current game time

}

bool FreezeTime::HackedKeyRelease(JAZUL_KEY k)
{
    bool keyPressedAndReleased = false;

    if (Keyboard::GetKeyState(k)) // Is the key pressed?
    {
        while (Keyboard::GetKeyState(k))
        {
            MSG msg;
            GetMessage(&msg, NULL, 0, 0);
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        keyPressedAndReleased = true; // k pressed and released.
    }
    return keyPressedAndReleased; // and k _must_ be released 
}

void FreezeTime::TestForFreezeKeys()
{
    if (HackedKeyRelease(FREEZE_KEY) || freezeActive)
    {
        Trace::out("FREEZE FRAME at time %f (last frame: %f)\n", TimeManager::GetTime(), TimeManager::GetFrameTime());

        freezeActive = true;  // Freeze mode active
        bool singleFrameRequest = false; // No single frame request

        while (freezeActive && !singleFrameRequest)
        {
            if (HackedKeyRelease(FREEZE_KEY))
            {
                freezeActive = false; // Cancel both freeze modes
                singleFrameRequest = false;
            }
            else if (HackedKeyRelease(SINGLE_FRAME_KEY))
            {
                singleFrameRequest = true; // Process a single frame
            }

            MSG msg;
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }
}
