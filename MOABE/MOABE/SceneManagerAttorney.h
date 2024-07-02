#ifndef SCENEMANAGERATTORNEY_H
#define SCENEMANAGERATTORNEY_H

#include "SceneManager.h"

class SceneManagerAttorney
{
	friend class MOABE;
	friend class CleanupSceneStrategy;
	friend class DebugSceneStrategy;

	static void StartNextScene() { SceneManager::StartNextScene(); };
	static void InitStartScene() { SceneManager::InitStartScene(); };
	static void Update() { SceneManager::Update(); };
	static void Draw() { SceneManager::Draw(); };
	static void Delete() { SceneManager::Delete(); };
	static void GetGodCamInputs() { SceneManager::GetGodCamInputs(); };
};

#endif // SCENEMANAGERATTORNEY_H