#include "CollidableDeRegCmd.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

CollidableDeRegCmd::CollidableDeRegCmd(Collidable* _pCol) :
	pCol(_pCol)
{
}

void CollidableDeRegCmd::Execute() const
{
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrScene(), this->pCol);
	GameObjectAttorney::Collision::SetRegStatusDeregistered(this->pCol);
}
