#include "AlarmList.h"
#include "AlarmableRegCmd.h"
#include "AlarmableDeRegCmd.h"
#include "SceneManager.h"

AlarmList::AlarmList(Alarmable* _pAlarm) :
	RegData(),
	pAlarm(_pAlarm)
{
	for (int i = 0; i < ALARM_NUMBER; i++) {
		RegData[i].SetAlarmable(this->pAlarm, static_cast<ALARM_ID>(i));
	}
}

void AlarmList::RegisterAlarm(ALARM_ID alarmNum, float time)
{
	this->RegData[static_cast<unsigned int>(alarmNum)].SendRegCmd(time);
}

void AlarmList::DeregisterAlarm(ALARM_ID alarmNum)
{
	this->RegData[static_cast<unsigned int>(alarmNum)].SendDeRegCmd();
}

void AlarmList::SetStatusRegistered(ALARM_ID alarmNum)
{
	this->RegData[static_cast<unsigned int>(alarmNum)].SetStatusRegistered();
}

void AlarmList::SetStatusDeregistered(ALARM_ID alarmNum)
{
	this->RegData[static_cast<unsigned int>(alarmNum)].SetStatusDeregistered();
}

const bool AlarmList::AlarmActive(const unsigned int alarmNum) const
{
	return this->RegData[alarmNum].isActive();
}

void AlarmList::SetDeleteRef(AlarmableManager::AlarmableListRef deleteRef, ALARM_ID alarmNum)
{
	this->RegData[static_cast<unsigned int>(alarmNum)].SetDeleteRef(deleteRef);
}

AlarmableManager::AlarmableListRef& AlarmList::GetDeleteRef(ALARM_ID alarmNum)
{
	return this->RegData[static_cast<unsigned int>(alarmNum)].GetDeleteRef();
}

