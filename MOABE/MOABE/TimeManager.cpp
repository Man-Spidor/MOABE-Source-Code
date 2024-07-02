#include "TimeManager.h"
#include "MOABEAttorney.h"

TimeManager* TimeManager::instance = nullptr;
float TimeManager::prevTime;
float TimeManager::currTime;
float TimeManager::frameTime;

FreezeTime TimeManager::timeFreeze;

void TimeManager::ProcessTime()
{
	prevTime = currTime;
	
	// currTime = MOABEAttorney::GetTimeInSeconds();
	currTime = timeFreeze.ComputeGameTime(prevTime);

	frameTime = currTime - prevTime;
}

void TimeManager::Initialize()
{
	assert(!instance);
	instance = new TimeManager();
}

void TimeManager::Delete()
{
	delete instance;
}

const float TimeManager::GetTime()
{
	return Instance().currTime;
}

const float TimeManager::GetFrameTime()
{
	return Instance().frameTime;
}

TimeManager& TimeManager::Instance()
{
	assert(instance);
	return *instance;
}
