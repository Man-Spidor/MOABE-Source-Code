#include "LightBehaviourCommand.h"

const LightBehaviourCommand::StoppedBehaviour LightBehaviourCommand::BehaviourStrategies::BehaviorStopped;
const LightBehaviourCommand::NormalBehaviour LightBehaviourCommand::BehaviourStrategies::BehaviorNormal;

LightBehaviourCommand::LightBehaviourCommand() :
	currStrategy(&LightBehaviourCommand::BehaviourStrategies::BehaviorStopped)
{
}

void LightBehaviourCommand::StartBehaviour()
{
	this->StartProcessing();
}

void LightBehaviourCommand::StopBehaviour()
{
	this->StopProcessing();
}

void LightBehaviourCommand::StartProcessing()
{
	this->currStrategy = &LightBehaviourCommand::BehaviourStrategies::BehaviorNormal;
}

void LightBehaviourCommand::StopProcessing()
{
	this->currStrategy = &LightBehaviourCommand::BehaviourStrategies::BehaviorStopped;
}

void LightBehaviourCommand::ProcessLight()
{
	this->currStrategy->ProcessLight(*this);
}
