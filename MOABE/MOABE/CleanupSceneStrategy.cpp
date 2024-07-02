#include "CleanupSceneStrategy.h"
#include "SceneAttorney.h"
#include "SceneManagerAttorney.h"

void CleanupSceneStrategy::Update(Scene* const pScene) const
{
	SceneAttorney::SceneManagement::ClearLists(*pScene);
	SceneAttorney::SceneManagement::SceneEnd(*pScene);
	delete pScene;
	SceneManagerAttorney::StartNextScene();
}
