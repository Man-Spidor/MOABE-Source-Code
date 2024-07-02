#ifndef SCENEATTORNEY_H
#define SCENEATTORNEY_H

#include "SceneManager.h"

class RegistrationCommand;

class SceneAttorney
{
public:
	class SceneManagement
	{
		friend class SceneManager;
		friend class NormalSceneStrategy;
		friend class CleanupSceneStrategy;
		friend class DebugSceneStrategy;

		static void Initialize(Scene& scene) { scene.Initialize(); };
		static void SceneEnd(Scene& scene) { scene.SceneEnd(); };
		static void ClearLists(Scene& scene) { scene.ClearManagers(); };
		static void Update(Scene& scene) { scene.Update(); };
		static void Draw(Scene& scene) { scene.Draw(); };
		static void InitColMan(Scene& scene) { scene.colMan.InitializeColGroupCollection(); };
		static void ActivateGodCam(Scene& scene) { scene.ActivateGodCam(); };
	};

	class GameObjects
	{
		friend class Updatable;
		friend class Drawable;
		friend class AlarmableRegData;
		friend class InputRegData;
		friend class Collidable;
		friend class GameObject;
		friend class MOABEDirectionalLight;
		friend class MOABEPointLight;
		friend class MOABESpotLight;

		static void SubmitRegistrationCmd(Scene& scene, RegistrationCommand* pRegCmd) { scene.SubmitRegistrationCommand(pRegCmd); };
	};

	class Registration 
	{
		friend class UpdatableRegCmd;
		friend class UpdatableDeRegCmd;
		friend class Drawable3DRegCmd;
		friend class Drawable3DDeRegCmd;
		friend class Drawable2DRegCmd;
		friend class Drawable2DDeRegCmd;
		friend class AlarmableRegCmd;
		friend class AlarmableDeRegCmd;
		friend class InputableRegCmd;
		friend class InputableDeRegCmd;
		friend class CollidableRegCmd;
		friend class CollidableDeRegCmd;

		friend class DirectionalRegCmd;
		friend class DirectionalDeRegCmd;
		friend class PointRegCmd;
		friend class PointDeRegCmd;
		friend class SpotRegCmd;
		friend class SpotDeRegCmd;

		static void Register(Scene& scene, Updatable* pUpdate) { scene.Register(pUpdate); };
		static void Register3D(Scene& scene, Drawable* pDraw) { scene.Register3D(pDraw); };
		static void Register2D(Scene& scene, Drawable* pDraw) { scene.Register2D(pDraw); };
		static void Register(Scene& scene, float time, Alarmable* pAlarm, const unsigned int alarmNum) { scene.Register(time, pAlarm, alarmNum); };
		static void Register(Scene& scene, Collidable* pCol) { scene.Register(pCol); };
		static void RegisterKey(Scene& scene, JAZUL_KEY key, EventType ke, Inputable* pInput) { scene.RegisterKey(key, ke, pInput); };
		
		static void Deregister(Scene& scene, Updatable* pUpdate) { scene.Deregister(pUpdate); };
		static void Deregister3D(Scene& scene, Drawable* pDraw) { scene.Deregister3D(pDraw); };
		static void Deregister2D(Scene& scene, Drawable* pDraw) { scene.Deregister2D(pDraw); };
		static void Deregister(Scene& scene, Alarmable* pAlarm, const unsigned int alarmNum) { scene.Deregister(pAlarm, alarmNum); };
		static void Deregister(Scene& scene, Collidable* pCol) { scene.Deregister(pCol); };
		static void DeregisterKey(Scene& scene, JAZUL_KEY key, EventType ke, Inputable* pInput) { scene.DeregisterKey(key, ke, pInput); };

		static void RegisterLight(Scene& scene, MOABEDirectionalLight* pDirLight) { scene.RegisterLight(pDirLight); };
		static void RegisterLight(Scene& scene, MOABEPointLight* pPointLight) { scene.RegisterLight(pPointLight); };
		static void RegisterLight(Scene& scene, MOABESpotLight* pSpotLight) { scene.RegisterLight(pSpotLight); };

		static void DeregisterLight(Scene& scene, MOABEDirectionalLight* pDirLight) { scene.DeregisterLight(pDirLight); };
		static void DeregisterLight(Scene& scene, MOABEPointLight* pPointLight) { scene.DeregisterLight(pPointLight); };
		static void DeregisterLight(Scene& scene, MOABESpotLight* pSpotLight) { scene.DeregisterLight(pSpotLight); };
	};
};

#endif // SCENEATTORNEY_H
