#include "GameObjectRegCmd.h"
#include "GameObjectAttorney.h"

GameObjectRegCmd::GameObjectRegCmd(GameObject* _pGO) :
	pGO(_pGO)
{
}

void GameObjectRegCmd::Execute() const
{
	GameObjectAttorney::GameObj::ConnectToScene(this->pGO);
}
