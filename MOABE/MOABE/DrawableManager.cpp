#include "DrawableManager.h"
#include "Drawable.h"
#include "GameObjectAttorney.h"

void DrawableManager::ClearLists()
{
	for (Drawable* pDraw : this->DrawList3D) {
		GameObjectAttorney::Draw::Set3DRegStatusDeregistered(pDraw);
	}

	for (Drawable* pDraw : this->DrawList2D) {
		GameObjectAttorney::Draw::Set2DRegStatusDeregistered(pDraw);
	}
}

void DrawableManager::ProcessElements() const
{
	for (Drawable* pDraw : this->DrawList3D) {
		GameObjectAttorney::Draw::Draw3DObject(pDraw);
	}

	for (Drawable* pDraw : this->DrawList2D) {
		GameObjectAttorney::Draw::Draw2DObject(pDraw);
	}
}

void DrawableManager::Register3D(Drawable* pDraw)
{
	DrawableListRef deleteRef = this->DrawList3D.insert(this->DrawList3D.end(), pDraw);
	GameObjectAttorney::Draw::SetDeleteRef3D(pDraw, deleteRef);
}

void DrawableManager::Deregister3D(Drawable* pDraw)
{
	this->DrawList3D.erase(GameObjectAttorney::Draw::GetDeleteRef3D(pDraw));
}

void DrawableManager::Register2D(Drawable* pDraw)
{
	DrawableListRef deleteRef = this->DrawList2D.insert(this->DrawList2D.end(), pDraw);
	GameObjectAttorney::Draw::SetDeleteRef2D(pDraw, deleteRef);
}

void DrawableManager::Deregister2D(Drawable* pDraw)
{
	this->DrawList2D.erase(GameObjectAttorney::Draw::GetDeleteRef2D(pDraw));
}
