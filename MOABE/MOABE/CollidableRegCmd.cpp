#include "CollidableRegCmd.h"
#include "GameObjectAttorney.h"
#include "SceneAttorney.h"

CollidableRegCmd::CollidableRegCmd(Collidable* _pCol) :
	pCol(_pCol)
{
}

void CollidableRegCmd::Execute() const
{
	SceneAttorney::Registration::Register(SceneManager::GetCurrScene(), this->pCol);
	GameObjectAttorney::Collision::SetRegStatusRegistered(this->pCol);
}
