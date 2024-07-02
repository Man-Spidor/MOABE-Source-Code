#include "InputRegistrationData.h"
#include "Inputable.h"
#include "InputableRegCmd.h"
#include "InputableDeRegCmd.h"
#include "SceneManager.h"
#include "SceneAttorney.h"

InputRegData::InputRegData(JAZUL_KEY key, EventType ev, Inputable* _pInput) :
	pInput(_pInput),
	pRegCmd(new InputableRegCmd(key ,ev, this->pInput)),
	pDeRegCmd(new InputableDeRegCmd(key, ev, this->pInput))
{
	assert(pRegCmd);
	assert(pDeRegCmd);
}

InputRegData::~InputRegData()
{
	delete pRegCmd;
	delete pDeRegCmd;
}

void InputRegData::SubmitRegisterCmd()
{
	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
}

void InputRegData::SubmitDeregisterCmd()
{
	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
}
