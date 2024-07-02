#include "SceneManager.h"
#include "SceneAttorney.h"
#include "SceneStrategies.h"
#include <TimeManager.h>

SceneManager* SceneManager::instance = nullptr;

const float SceneManager::camRotAngle = 0.5f;
const float SceneManager::camMoveSpeed = 100.0f;

SceneManager::SceneManager() :
	pCurrScene(nullptr),
	pNextScene(nullptr),
	sceneStrategy(nullptr)
{
}

SceneManager::~SceneManager()
{
	delete this->pCurrScene;
	delete this->pNextScene;
}

void SceneManager::InitStartScene()
{
	Instance().privInitScene();
}

void SceneManager::SetStartScene(Scene* pScene)
{
	Instance().pCurrScene = pScene;
}

Scene& SceneManager::GetCurrScene()
{
	return *Instance().pCurrScene;
}

void SceneManager::SwitchCurrScene(Scene* pScene)
{
	Instance().privSwitchCurrScene(pScene);
}

void SceneManager::SwitchPlayMode()
{
	Instance().sceneStrategy = &SceneStrategies::NormalStrategy;
}

void SceneManager::SwitchDebugMode()
{
	Instance().sceneStrategy = &SceneStrategies::DebugStrategy;
}

void SceneManager::SetCurrCamera3D(Camera* pCam)
{
	assert(Instance().pCurrScene);
	Instance().pCurrScene->SetCurrCamera3D(pCam);
}

void SceneManager::SetCurrCamera2D(Camera* pCam)
{
	assert(Instance().pCurrScene);
	Instance().pCurrScene->SetCurrCamera2D(pCam);
}

void SceneManager::Update()
{
	assert(Instance().pCurrScene);
	Instance().sceneStrategy->Update(Instance().pCurrScene);
}

void SceneManager::Draw()
{
	assert(Instance().pCurrScene);
	Instance().sceneStrategy->Draw(Instance().pCurrScene);
}

void SceneManager::Delete()
{
	assert(Instance().pCurrScene);
	SceneAttorney::SceneManagement::SceneEnd(*Instance().pCurrScene);
	delete instance;
}

void SceneManager::StartNextScene()
{
	Instance().privStartNextScene();
}

void SceneManager::GetGodCamInputs()
{
	Camera* camera = &Instance().pCurrScene->GetMainCamera();

	static float speedOffset = 0.0f;
	static float rotOffset = 0.0f;

	if (Keyboard::GetKeyState(JAZUL_KEY::KEY_COMMA)) {
		speedOffset -= 100.0f;
		rotOffset -= 0.5f;
	}
	else if (Keyboard::GetKeyState(JAZUL_KEY::KEY_PERIOD)) {
		speedOffset += 100.0f;
		rotOffset += 0.5f;
	}
	
	// turn camera left and right
	if (Keyboard::GetKeyState(JAZUL_KEY::KEY_ARROW_LEFT)) {
		camera->TurnLeftRight((camRotAngle + rotOffset) * TimeManager::GetFrameTime());
		camera->updateCamera();
	}
	else if (Keyboard::GetKeyState(JAZUL_KEY::KEY_ARROW_RIGHT)) {
		camera->TurnLeftRight(-(camRotAngle + rotOffset) * TimeManager::GetFrameTime());
		camera->updateCamera();
	}

	// tilt camera up and down
	if (Keyboard::GetKeyState(JAZUL_KEY::KEY_X)) {
		camera->TiltUpDown((camRotAngle + rotOffset) * TimeManager::GetFrameTime());
		camera->updateCamera();
	}
	else if (Keyboard::GetKeyState(JAZUL_KEY::KEY_Z)) {
		camera->TiltUpDown(-(camRotAngle + rotOffset) * TimeManager::GetFrameTime());
		camera->updateCamera();
	}


	if (Keyboard::GetKeyState(JAZUL_KEY::KEY_ARROW_DOWN)) {
		camera->TranslateFwdBack(-(camMoveSpeed + speedOffset) * TimeManager::GetFrameTime());
		camera->updateCamera();
	}
	else if (Keyboard::GetKeyState(JAZUL_KEY::KEY_ARROW_UP)) {
		camera->TranslateFwdBack((camMoveSpeed + speedOffset) * TimeManager::GetFrameTime());
		camera->updateCamera();
	}

	Instance().pCurrScene->SetCurrCamera3D(camera);
}

void SceneManager::privInitScene()
{
	this->sceneStrategy = &SceneStrategies::NormalStrategy;
	SceneAttorney::SceneManagement::InitColMan(*this->pCurrScene);
	SceneAttorney::SceneManagement::Initialize(*this->pCurrScene);
}

void SceneManager::privSwitchCurrScene(Scene* pScene)
{
	// Make sure no more update calls are made on the current scene pat the current one
	this->sceneStrategy = &SceneStrategies::CleanupStrategy;
	this->pNextScene = pScene;
}

void SceneManager::privStartNextScene()
{
	assert(pNextScene);
	this->pCurrScene = pNextScene;
	this->pNextScene = nullptr;

	this->sceneStrategy = &SceneStrategies::NormalStrategy;
	SceneAttorney::SceneManagement::Initialize(*this->pCurrScene);
}

SceneManager& SceneManager::Instance()
{
	if (!instance) {
		instance = new SceneManager();
	}
	return *instance;
}
