#include "InputableDeRegCmd.h"
#include "SceneAttorney.h"

InputableDeRegCmd::InputableDeRegCmd(JAZUL_KEY _key, EventType _keyEvent, Inputable* _pInput) :
	key(_key),
	keyEvent(_keyEvent),
	pInput(_pInput)
{
}


void InputableDeRegCmd::Execute() const
{
	SceneAttorney::Registration::DeregisterKey(SceneManager::GetCurrScene(), this->key, this->keyEvent, this->pInput);
}
