#include "AlarmableManager.h"
#include "Alarmable.h"
#include "TimeManager.h"
#include "GameObjectAttorney.h"

void AlarmableManager::ClearAlarms()
{
	auto it = this->timeLine.begin();
	while (it != this->timeLine.end()) {
		GameObjectAttorney::Alarm::SetRegStatusDeregistered(it->second.first, it->second.second);
		it++;
	}
}

void AlarmableManager::Register(const float time, Alarmable* pAlarm, const unsigned int alarmNum)
{
	auto alarm = AlarmEvent(pAlarm, alarmNum);
	AlarmableListRef deleteRef = this->timeLine.insert(std::pair<const float, AlarmEvent>(time, alarm));
	GameObjectAttorney::Alarm::SetDeleteRef(pAlarm, deleteRef, alarmNum);
}

void AlarmableManager::Deregister(Alarmable* pAlarm, const unsigned int alarmNum)
{
	this->timeLine.erase(GameObjectAttorney::Alarm::GetDeleteRef(pAlarm, alarmNum));
}

void AlarmableManager::ProcessAlarms()
{
	if (this->timeLine.empty())
		return;

	float currTime = TimeManager::GetTime();

	auto it = this->timeLine.begin();
	while (it != this->timeLine.end() && it->first <= currTime) {
		AlarmEvent alarm = it->second;
		it++;

		GameObjectAttorney::Alarm::TriggerAlarmObject(alarm.first, alarm.second);
		this->timeLine.erase(GameObjectAttorney::Alarm::GetDeleteRef(alarm.first, alarm.second));
		GameObjectAttorney::Alarm::SetRegStatusDeregistered(alarm.first, alarm.second);
	}
}
