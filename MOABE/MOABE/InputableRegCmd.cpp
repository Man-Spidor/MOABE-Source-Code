#include "InputableRegCmd.h"
#include "SceneAttorney.h"

InputableRegCmd::InputableRegCmd(JAZUL_KEY _key, EventType _keyEvent, Inputable* _pInput) :
	key(_key),
	keyEvent(_keyEvent),
	pInput(_pInput)
{
}

void InputableRegCmd::Execute() const
{
	SceneAttorney::Registration::RegisterKey(SceneManager::GetCurrScene(), this->key, this->keyEvent, this->pInput);
}
