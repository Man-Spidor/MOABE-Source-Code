#include "LightBlinkingCmd.h"

#include "MOABELight.h"

LightBlinkingCmd::LightBlinkingCmd(MOABELight& _Light) :
	Alarm(*this),
	Light(_Light),
	onTime(0.0f),
	offTime(0.0f)
{
}

void LightBlinkingCmd::StartBehaviour()
{
	LightBehaviourCommand::StartProcessing();
	this->Alarm.StartAlarm(0, onTime);
}

void LightBlinkingCmd::StopBehaviour()
{
	LightBehaviourCommand::StopProcessing();
}

void LightBlinkingCmd::SetOnOffTime(const float on_time, const float off_time)
{
	this->onTime = on_time;
	this->offTime = off_time;
}

void LightBlinkingCmd::Callback0()
{
	this->Light.TurnOff();

	if(this->currStrategy == &LightBehaviourCommand::BehaviourStrategies::BehaviorNormal)
		this->Alarm.StartAlarm(1, this->offTime);
}

void LightBlinkingCmd::Callback1()
{
	this->Light.TurnOn();

	if(this->currStrategy == &LightBehaviourCommand::BehaviourStrategies::BehaviorNormal)
		this->Alarm.StartAlarm(0, this->onTime);
}
