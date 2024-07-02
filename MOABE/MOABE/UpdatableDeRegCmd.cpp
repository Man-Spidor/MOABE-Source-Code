#include "UpdatableDeregCmd.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

UpdatableDeRegCmd::UpdatableDeRegCmd(Updatable* _pUpdatable) :
	pUpdatable(_pUpdatable)
{
}

void UpdatableDeRegCmd::Execute() const
{
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrScene(), this->pUpdatable);
	GameObjectAttorney::Update::SetRegStatusDeregistered(this->pUpdatable);
}
