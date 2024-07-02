#include "Drawable2DRegCmd.h"

#include"SceneAttorney.h"
#include "GameObjectAttorney.h"

Drawable2DRegCmd::Drawable2DRegCmd(Drawable* _pDrawble) :
	pDrawable(_pDrawble)
{
}
 
void Drawable2DRegCmd::Execute() const
{
	SceneAttorney::Registration::Register2D(SceneManager::GetCurrScene(), this->pDrawable);
	GameObjectAttorney::Draw::Set2DRegStatusRegistered(this->pDrawable);
}
