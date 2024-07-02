#include "Inputable.h"

#include "InputableRegCmd.h"
#include "InputableDeRegCmd.h"
#include "InputRegistrationData.h"

#include "SceneManager.h"

Inputable::Inputable() :
	InputList()
{
}

Inputable::~Inputable()
{
	for (auto it = this->InputList.begin(); it != this->InputList.end(); it++) {
		delete it->second;
	}
}

void Inputable::RegisterKeyToScene(JAZUL_KEY key, EventType ke)
{
	KeyID keyID = KeyID(key, ke);
	auto it = this->InputList.find(keyID);
	// make sure key is not already registered
	if (it != this->InputList.end()) {
		it->second->SubmitRegisterCmd();
	}
	else {
		InputRegData* regData = new InputRegData(key, ke, this);
		this->InputList.insert(std::pair<KeyID, InputRegData*>(keyID, regData));
		regData->SubmitRegisterCmd();
	}
}

void Inputable::DeregisterKeyFromScene(JAZUL_KEY key, EventType ke)
{
	KeyID keyID = KeyID(key, ke);

	auto it = this->InputList.find(keyID);
	// make sure key is not already registered
	if (it == this->InputList.end()) {
		Trace::out("Input [%s]: Not Found.\n", key);
		assert(false);
	}

	InputRegData* regData = it->second;
	regData->SubmitDeregisterCmd();
}

void Inputable::SetDeleteRef(JAZUL_KEY key, EventType ev, SingleKeyEvent::KeyListRef listRef)
{
	auto regData = this->InputList[KeyID(key, ev)];

	regData->keyDeleteRef = listRef;
}

SingleKeyEvent::KeyListRef Inputable::GetDeleteRef(JAZUL_KEY key, EventType ev)
{
	auto regData = this->InputList.find(KeyID(key, ev));

	assert(regData != this->InputList.end());

	return regData->second->keyDeleteRef;
}

void Inputable::KeyPressed(JAZUL_KEY k)
{
	UNREFERENCED_PARAMETER(k);
}

void Inputable::KeyReleased(JAZUL_KEY k)
{
	UNREFERENCED_PARAMETER(k);
}
