#include "UpdatableRegCmd.h"
#include "Updatable.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

UpdatableRegCmd::UpdatableRegCmd(Updatable* _pUpdatable) :
	pUpdatable(_pUpdatable)
{
}

void UpdatableRegCmd::Execute() const
{
	SceneAttorney::Registration::Register(SceneManager::GetCurrScene(), this->pUpdatable);
	GameObjectAttorney::Update::SetRegStatusRegistered(this->pUpdatable);
}
