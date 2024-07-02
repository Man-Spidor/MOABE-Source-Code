#include "GameObjectDeRegCmd.h"
#include "GameObjectAttorney.h"

GameObjectDeRegCmd::GameObjectDeRegCmd(GameObject* _pGO) :
	pGO(_pGO)
{
}

void GameObjectDeRegCmd::Execute() const
{
	GameObjectAttorney::GameObj::DisconnectFromScene(this->pGO);
}
