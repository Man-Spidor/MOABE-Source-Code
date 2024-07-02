#include "DebugSceneStrategy.h"
#include "SceneAttorney.h"
#include "SceneManagerAttorney.h"

void DebugSceneStrategy::Update(Scene* const pScene) const
{
	SceneAttorney::SceneManagement::Update(*pScene);
	SceneAttorney::SceneManagement::ActivateGodCam(*pScene);
	SceneManagerAttorney::GetGodCamInputs();
}

void DebugSceneStrategy::Draw(Scene* const pScene) const
{
	SceneAttorney::SceneManagement::Draw(*pScene);
}
