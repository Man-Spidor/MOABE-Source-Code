#include "Alarmable.h"
#include "AlarmableRegCmd.h"
#include "AlarmableDeRegCmd.h"
#include "SceneManager.h"
#include "MOABE.h"

Alarmable::Alarmable() :
	alarmList(this)
{
}

void Alarmable::TriggerAlarm(const unsigned int alarmNum)
{
	switch (static_cast<ALARM_ID>(alarmNum)) {
	case ALARM_ID::ALARM_0:
		this->Alarm0();
		break;

	case ALARM_ID::ALARM_1:
		this->Alarm1();
		break;

	case ALARM_ID::ALARM_2:
		this->Alarm2();
		break;

	default:
		Trace::out("Error! Alarm not found");
	}
}

void Alarmable::Alarm0()
{
	Trace::out("AHHHHHHHHHHHHH \nFrom the default Alarm0\n");
}

void Alarmable::Alarm1()
{
	Trace::out("AHHHHHHHHHHHHH \nFrom the default Alarm1\n");
}

void Alarmable::Alarm2()
{
	Trace::out("AHHHHHHHHHHHHH \nFrom the default Alarm2\n");
}

void Alarmable::RegisterAlarm(const unsigned int alarmNum, float time)
{
	assert("Alarm Num out of range." && alarmNum < AlarmList::ALARM_NUMBER);

	this->alarmList.RegisterAlarm(static_cast<ALARM_ID>(alarmNum), time);
}

void Alarmable::DeregisterAlarm(const unsigned int alarmNum)
{
	assert("Alarm Num out of range." && alarmNum < AlarmList::ALARM_NUMBER);

	this->alarmList.DeregisterAlarm(static_cast<ALARM_ID>(alarmNum));
}

const bool Alarmable::AlarmActive(const unsigned int alarmNum) const
{
	return this->alarmList.AlarmActive(alarmNum);
}

void Alarmable::SetRegStatusRegistered(const unsigned int alarmNum)
{
	assert("Alarm Num out of range." && alarmNum < AlarmList::ALARM_NUMBER);

	this->alarmList.SetStatusRegistered(static_cast<ALARM_ID>(alarmNum));
}

void Alarmable::SetRegStatusDeregistered(const unsigned int alarmNum)
{
	assert("Alarm Num out of range." && alarmNum < AlarmList::ALARM_NUMBER);

	this->alarmList.SetStatusDeregistered(static_cast<ALARM_ID>(alarmNum));
}

void Alarmable::SetDeleteRef(AlarmableManager::AlarmableListRef deleteRef, const unsigned int alarmNum)
{
	assert("Alarm Num out of range." && alarmNum < AlarmList::ALARM_NUMBER);

	this->alarmList.SetDeleteRef(deleteRef, static_cast<ALARM_ID>(alarmNum));
}

AlarmableManager::AlarmableListRef& Alarmable::GetDeleteRef(const unsigned int alarmNum)
{
	assert("Alarm Num out of range." && alarmNum < AlarmList::ALARM_NUMBER);

	return this->alarmList.GetDeleteRef(static_cast<ALARM_ID>(alarmNum));
}
