#include "MOABE.h"

#include "AssetManagers.h"

#include "TimeAttorney.h"
#include "SceneManagerAttorney.h"
#include "VisualizerAttorney.h"

#include "SamplerManager.h"
#include "FontManager.h"
#include "SoundManager.h"
#include "TerrainObjectManager.h"
#include "SkyboxObjectManager.h"

MOABE* MOABE::instance = nullptr;

void MOABE::Run(HINSTANCE hInstance)
{
	assert(Instance().pUserCode && "User Functions Not Defined!");
	Instance().run(hInstance);

	delete instance;
}

//-----------------------------------------------------------------------------
// MOABE::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------

void MOABE::Initialize()
{
	Instance().pUserCode->GameStart();
	TimeAttorney::Initialize();
}

void MOABE::SetUserFunctions(MOABEUser* _pUserCode)
{
	Instance().pUserCode = _pUserCode;
}

//-----------------------------------------------------------------------------
// MOABE::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void MOABE::LoadContent()
{
	Instance().pUserCode->LoadAllContent();
	SceneManagerAttorney::InitStartScene();
}

//-----------------------------------------------------------------------------
// MOABE::Update()
//      Called once per frame, update data, transformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void MOABE::Update()
{
	TimeAttorney::ProcessTime();
	SceneManagerAttorney::Update();
}

//-----------------------------------------------------------------------------
// MOABE::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void MOABE::Draw()
{
	SceneManagerAttorney::Draw();
	VisualizerAttorney::Loop::Draw();
}

//-----------------------------------------------------------------------------
// MOABE::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void MOABE::UnLoadContent()
{
	Instance().pUserCode->GameEnd();
	
	SceneManagerAttorney::Delete();

	ModelManager::Unload();
	TextureManager::Unload();
	ImageManager::Unload();
	SamplerManager::UnLoad();
	FontManager::Unload();
	SoundManager::Unload();
	TerrainObjectManager::Unload();
	SkyboxObjectManager::Unload();

	TimeAttorney::Delete();
	VisualizerAttorney::Loop::Delete();
}

//-----------------------------------------------------------------------------
//		RANDOM UTILITY FUNCTIONS
//-----------------------------------------------------------------------------

MOABE& MOABE::Instance()
{
	if (!instance) {
		instance = new MOABE();
	}
	return *instance;
}

void MOABE::SetWindowName(const char* const WindowName)
{
	Instance().Engine::SetWindowName(WindowName);
}

void MOABE::SetColor(const float R, const float G, const float B, const float A)
{
	Instance().SetBackgroundColor(R, G, B, A);
}

void MOABE::SetWidthHeight(const int width, const int height)
{
	Instance().Engine::SetWidthHeight(width, height);
}

const int MOABE::GetWidth()
{
	return Instance().Engine::GetWidth();
}

const int MOABE::GetHeight()
{
	return Instance().Engine::GetHeight();
}

void MOABE::EnableAsync()
{
	Instance().graphicsEngine.EnableASync();
}

void MOABE::DisableAsync()
{
	Instance().graphicsEngine.DisableASync();
}

void MOABE::SetCamera3D(Camera* pCam)
{
	Instance().graphicsEngine.SetCurrCam(pCam);
}

void MOABE::SetCamera2D(Camera* pCam)
{
	Instance().graphicsEngine.SetCurrCam2D(pCam);
}

const float MOABE::GetTimeInSeconds()
{
	return Instance().Engine::GetTimeInSeconds();
}
