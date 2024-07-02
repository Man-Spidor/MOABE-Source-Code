#include "LightAlarm.h"

#include "LightAttorney.h"

LightAlarm::LightAlarm(LightBehaviourCommand& _BehaviourCallBack) :
	BehaviourCallback(_BehaviourCallBack)
{
}

void LightAlarm::StartAlarm(const unsigned int alarmNum, const float timer)
{
	Alarmable::RegisterAlarm(alarmNum, timer);
}

void LightAlarm::CancelAlarm(const unsigned int alarmNum)
{
	Alarmable::DeregisterAlarm(alarmNum);
}

const bool LightAlarm::AlarmActive(const unsigned int alarmNum) const
{
	return Alarmable::AlarmActive(alarmNum);
}

void LightAlarm::Alarm0()
{
	LightAttorney::Behaviour::Callback0(this->BehaviourCallback);
}

void LightAlarm::Alarm1()
{
	LightAttorney::Behaviour::Callback1(this->BehaviourCallback);
}

void LightAlarm::Alarm2()
{
	LightAttorney::Behaviour::Callback2(this->BehaviourCallback);
}
