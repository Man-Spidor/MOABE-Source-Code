#ifndef TIMEATTORNEY_H
#define TIMEATTORNEY_H

#include "TimeManager.h"

class TimeAttorney
{
	friend class MOABE;
	static void ProcessTime() { TimeManager::ProcessTime(); };
	static void Initialize() { TimeManager::Initialize(); };
	static void Delete() { TimeManager::Delete(); };
};

#endif // TIMEATTORNEY_H
