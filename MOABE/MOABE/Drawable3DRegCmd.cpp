#include "Drawable3DRegCmd.h"
#include "SceneAttorney.h"
#include "Drawable.h"
#include "GameObjectAttorney.h"

Drawable3DRegCmd::Drawable3DRegCmd(Drawable* _pDrawable) :
	pDrawable(_pDrawable)
{
}

void Drawable3DRegCmd::Execute() const
{
	SceneAttorney::Registration::Register3D(SceneManager::GetCurrScene(), this->pDrawable);
	GameObjectAttorney::Draw::Set3DRegStatusRegistered(this->pDrawable);
}
