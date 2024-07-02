#include "AlarmableDeRegCmd.h"
#include "Alarmable.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

AlarmableDeRegCmd::AlarmableDeRegCmd(Alarmable* _pAlarm, const unsigned int _myID) :
	myID(_myID),
	pAlarm(_pAlarm)
{
}

void AlarmableDeRegCmd::Execute() const
{
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrScene(), this->pAlarm, this->myID);
	GameObjectAttorney::Alarm::SetRegStatusDeregistered(this->pAlarm, this->myID);
}
