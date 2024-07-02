#include "NormalSceneStrategy.h"
#include"SceneAttorney.h"

void NormalSceneStrategy::Update(Scene* const pScene) const
{
	SceneAttorney::SceneManagement::Update(*pScene);
}

void NormalSceneStrategy::Draw(Scene* const pScene) const
{
	SceneAttorney::SceneManagement::Draw(*pScene);
}
