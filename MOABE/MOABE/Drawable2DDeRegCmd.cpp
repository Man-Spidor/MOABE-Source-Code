#include "Drawable2DDeRegCmd.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

Drawable2DDeRegCmd::Drawable2DDeRegCmd(Drawable* _pDrawble) :
	pDrawable(_pDrawble)
{
}

void Drawable2DDeRegCmd::Execute() const
{
	SceneAttorney::Registration::Deregister3D(SceneManager::GetCurrScene(), this->pDrawable);
	GameObjectAttorney::Draw::Set3DRegStatusDeregistered(this->pDrawable);
}
