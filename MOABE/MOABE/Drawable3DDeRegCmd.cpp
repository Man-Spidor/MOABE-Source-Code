#include "Drawable3DDeregCmd.h"
#include "Drawable.h"
#include "SceneAttorney.h"
#include "GameObjectAttorney.h"

Drawable3DDeRegCmd::Drawable3DDeRegCmd(Drawable* _pDrawable) :
	pDrawable(_pDrawable)
{
}

void Drawable3DDeRegCmd::Execute() const
{
	SceneAttorney::Registration::Deregister3D(SceneManager::GetCurrScene(), this->pDrawable);
	GameObjectAttorney::Draw::Set3DRegStatusDeregistered(this->pDrawable);
}
