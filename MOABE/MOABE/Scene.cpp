#include "Scene.h"
#include "TerrainArea.h"
#include "TerrainObject.h"

MOABESkyNull Scene::NullSkyBox;

Scene::Scene() :
	pGodCam(new PerspectiveCamera()),
	pSkyBox(&Scene::NullSkyBox),
	cmdBroker(),
	camMan(),
	updateMan(),
	drawMan(),
	alarmMan(),
	keyMan(),
	terrainMan(),
	lightMan()
{
	// Should set the default cam as the main cam by default in case users forget
	this->camMan.SetDefaultCameraAsCurr();
	this->camMan.InitializePersp((PerspectiveCamera*)this->pGodCam);

	Camera& defaultCam = this->camMan.GetMainCamera();
	Vect camDirVect;
	defaultCam.getDir(camDirVect);
	Vect camUpVector;
	defaultCam.getUp(camUpVector);
	Vect camPosVect;
	defaultCam.getPos(camPosVect);

	this->pGodCam->setOrientAndPosition(camUpVector, camDirVect, camPosVect);
	this->pGodCam->updateCamera();
}

Scene::~Scene()
{
	delete this->pGodCam;
}

void Scene::ClearManagers()
{
	this->updateMan.ClearLists();
	this->drawMan.ClearLists();
	this->alarmMan.ClearAlarms();
	this->lightMan.ClearLights();
}

void Scene::Update()
{
	this->alarmMan.ProcessAlarms();
	this->cmdBroker.ProcessCommands();
	this->colMan.ProcessCollisions();
	this->updateMan.ProcessElements();
	this->keyMan.ProcessInputs();
	this->lightMan.ProcessLights();
}

void Scene::Draw()
{
	this->drawMan.ProcessElements();
	this->terrainMan.RenderTerrain();
	this->pSkyBox->Render();
}

void Scene::EnableSceneLight() const
{
	this->lightMan.ActivateBaseLight();
}

void Scene::DisableSceneLight() const
{
	this->lightMan.DisableBaseLight();
}

void Scene::SetLightModeNormal()
{
	this->lightMan.SetModeNormal();
}

void Scene::SetLightModeCullByDist(const float distance)
{
	this->lightMan.SetModeCullByDist(distance);
}

void Scene::SetLightModeCullByView(const float distance)
{
	this->lightMan.SetModeCullByView(distance);
}

Camera& Scene::GetMainCamera() const
{
	return this->camMan.GetMainCamera();
}

Camera& Scene::Get2DCamera() const
{
	return this->camMan.Get2DCamera();
}

void Scene::SetCurrCamera3D(Camera*& pCam)
{
	this->camMan.SetCurrCamera3D(pCam);
}

void Scene::SetCurrCamera2D(Camera*& pCam)
{
	this->camMan.SetCurrCamera2D(pCam);
}

void Scene::SetCurrCameraPos(Vect upVector, Vect pos3DCam, Vect lookAt3DCam)
{
	this->camMan.SetCurrCameraPos(upVector, pos3DCam, lookAt3DCam);
}

void Scene::SetDefaultCameraAsCurr()
{
	this->camMan.SetDefaultCameraAsCurr();
}

void Scene::UpdateCurrCamera()
{
	this->camMan.UpdateCurrCamera();
}

void Scene::SetTerrain(MOABETerrain* pTerrain)
{
	this->terrainMan.SwitchTerrain(pTerrain);
}

const TerrainModel& Scene::GetTerrainModel() const
{
	return this->terrainMan.GetCurrTerrain();
}

const TerrainArea& Scene::GetTerrainArea(const Vect& Min, const Vect& Max) const
{
	return *this->terrainMan.GetTerrainObject().GetTerrainArea(Min, Max);
}

void Scene::SetTerrainWorld(const Matrix World)
{
	this->terrainMan.GetTerrainObject().SetWorld(World);
}

void Scene::SetTerrainTexture(Texture* pTexture)
{
	this->terrainMan.GetTerrainObject().SetTexture(pTexture);
}

void Scene::SetTerrainMaterial(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular)
{
	this->terrainMan.GetTerrainObject().SetMaterial(Ambient, Diffuse, Specular);
}

void Scene::SetSkyBox(MOABESkybox* _pSkybox)
{
	this->pSkyBox = (SkyboxObject*)_pSkybox;
}

void Scene::SubmitRegistrationCommand(const RegistrationCommand* pCmd)
{
	this->cmdBroker.AddCommand(pCmd);
}

void Scene::Register(Updatable* pUpdate)
{
	this->updateMan.Register(pUpdate);
}

void Scene::Register3D(Drawable* pDraw)
{
	this->drawMan.Register3D(pDraw);
}

void Scene::Register2D(Drawable* pDraw)
{
	this->drawMan.Register2D(pDraw);
}

void Scene::Register(float time, Alarmable* pAlarm, const unsigned int alarmNum)
{
	this->alarmMan.Register(time, pAlarm, alarmNum);
}

void Scene::Register(Collidable* pCol)
{
	this->colMan.Register(pCol);
}

void Scene::Deregister(Updatable* pUpdate)
{
	this->updateMan.Deregister(pUpdate);
}

void Scene::Deregister3D(Drawable* pDraw)
{
	this->drawMan.Deregister3D(pDraw);
}

void Scene::Deregister2D(Drawable* pDraw)
{
	this->drawMan.Deregister2D(pDraw);
}

void Scene::Deregister(Alarmable* pAlarm, const unsigned int alarmNum)
{
	this->alarmMan.Deregister(pAlarm, alarmNum);
}

void Scene::Deregister(Collidable* pCol)
{
	this->colMan.Deregister(pCol);
}

void Scene::RegisterKey(JAZUL_KEY key, EventType ke, Inputable* pInput)
{
	this->keyMan.RegisterKey(key, ke, pInput);
}

void Scene::DeregisterKey(JAZUL_KEY key, EventType ke, Inputable* pInput)
{
	this->keyMan.DeregisterKey(key, ke, pInput);
}

void Scene::RegisterLight(MOABEDirectionalLight* pDirLight)
{
	this->lightMan.RegisterLight(pDirLight);
}

void Scene::RegisterLight(MOABEPointLight* pPointLight)
{
	this->lightMan.RegisterLight(pPointLight);
}

void Scene::RegisterLight(MOABESpotLight* pSpotLight)
{
	this->lightMan.RegisterLight(pSpotLight);
}

void Scene::DeregisterLight(MOABEDirectionalLight* pDirLight)
{
	this->lightMan.DeregisterLight(pDirLight);
}

void Scene::DeregisterLight(MOABEPointLight* pPointLight)
{
	this->lightMan.DeregisterLight(pPointLight);
}

void Scene::DeregisterLight(MOABESpotLight* pSpotLight)
{
	this->lightMan.DeregisterLight(pSpotLight);
}


CollisionManager& Scene::GetCollisionManager()
{
	return this->colMan;
}

void Scene::ActivateGodCam()
{
	this->camMan.SetDefaultCameraAsCurr();
}