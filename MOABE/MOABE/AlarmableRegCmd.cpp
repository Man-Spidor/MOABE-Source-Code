#include "AlarmableRegCmd.h"
#include "Alarmable.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

AlarmableRegCmd::AlarmableRegCmd(Alarmable* _pAlarm, const unsigned int _myID) :
	myID(_myID),
	pAlarm(_pAlarm),
	time(0)
{
}

void AlarmableRegCmd::SetTime(const float _time)
{
	this->time = _time;
}

void AlarmableRegCmd::Execute() const
{
	SceneAttorney::Registration::Register(SceneManager::GetCurrScene(), this->time, this->pAlarm, this->myID);
	GameObjectAttorney::Alarm::SetRegStatusRegistered(this->pAlarm, this->myID);
}
