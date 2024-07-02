#include "AlarmRegistrationData.h"
#include "AlarmableRegCmd.h"
#include "AlarmableDeRegCmd.h"
#include "SceneManager.h"
#include "SceneAttorney.h"
#include "TimeManager.h"

AlarmableRegData::AlarmableRegData() :
	myID(ALARM_ID::ALARM_0),
	pAlarm(nullptr),
	regStatus(RegistrationStatus::CURRENTLY_DEREGISTERED),
	pRegCmd(nullptr),
	pDeRegCmd(nullptr),
	myDeleteRef()
{
}

AlarmableRegData::~AlarmableRegData()
{
	delete pRegCmd;
	delete pDeRegCmd;
}

void AlarmableRegData::SetAlarmable(Alarmable* _pAlarm, ALARM_ID _myID)
{
	this->pAlarm = _pAlarm;
	this->myID = _myID;
}

void AlarmableRegData::SetStatusRegistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_REGISTERED;
}

void AlarmableRegData::SetStatusDeregistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_DEREGISTERED;
}

const bool AlarmableRegData::isActive() const
{
	return this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED || (this->regStatus ==  RegistrationStatus::PENDING_REGISTRATION);
}

void AlarmableRegData::SendRegCmd(float time)
{
	if (this->regStatus == RegistrationStatus::CURRENTLY_DEREGISTERED) {
		if (this->pRegCmd == nullptr)
			this->pRegCmd = new AlarmableRegCmd(this->pAlarm, static_cast<unsigned int>(this->myID));

		this->pRegCmd->SetTime(this->privGetAbsTime(time));
		SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
		this->regStatus = RegistrationStatus::PENDING_REGISTRATION;
	}
}

void AlarmableRegData::SendDeRegCmd()
{
	if (this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED) {
		if (this->pDeRegCmd == nullptr)
			this->pDeRegCmd = new AlarmableDeRegCmd(this->pAlarm, static_cast<unsigned int>(this->myID));

		SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
		this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
	}
}

void AlarmableRegData::SetDeleteRef(AlarmableManager::AlarmableListRef deleteRef)
{
	this->myDeleteRef = deleteRef;
}

AlarmableManager::AlarmableListRef& AlarmableRegData::GetDeleteRef()
{
	return this->myDeleteRef;
}

const float AlarmableRegData::privGetAbsTime(float relTime)
{
	return TimeManager::GetTime() + relTime;
}