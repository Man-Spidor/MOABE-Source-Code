#include "KeyEventManager.h"
#include "GameObjectAttorney.h"
#include "Inputable.h"

KeyEventManager::~KeyEventManager()
{
	for (auto it = this->keyList.begin(); it != this->keyList.end(); it++) {
		delete it->second;
	}
}

void KeyEventManager::ProcessInputs()
{
	for (auto it = this->keyList.begin(); it != this->keyList.end(); it++) {
		it->second->ProcessKeyEvent();
	}
}

void KeyEventManager::RegisterKey(JAZUL_KEY key, EventType ev, Inputable* pInput)
{
	SingleKeyEvent* pSke;
	auto iter = this->keyList.find(key);

	if (iter == this->keyList.end()) {
		pSke = new SingleKeyEvent(key);
		this->keyList.insert(std::pair<JAZUL_KEY, SingleKeyEvent*>(key, pSke));
	}
	else
		pSke = iter->second;

	pSke->RegisterKey(pInput, ev);
}

void KeyEventManager::DeregisterKey(JAZUL_KEY key, EventType ev, Inputable* pInput)
{
	this->keyList.find(key)->second->DeregisterKey(pInput, ev);
}
