#ifndef GAMEOBJECTATTORNEY_H
#define GAMEOBJECTATTORNEY_H

#include "GameObject.h"

/// Provides access to private methods of GameObject for specific managers
class GameObjectAttorney
{
public:
	/// Provides access to private methods of GameObject related to updating
	class Update
	{
		friend class UpdatableManager;
		friend class UpdatableRegCmd;
		friend class UpdatableDeRegCmd;
		static void UpdateObject(Updatable* pUpdate) { pUpdate->Update(); };

		static void SetRegStatusRegistered(Updatable* pUpdate) { pUpdate->SetRegStatusRegistered(); };
		static void SetRegStatusDeregistered(Updatable* pUpdate) { pUpdate->SetRegStatusDeregistered(); };

		static void SetDeleteRef(Updatable* pUpdate, UpdatableManager::UpdatableListRef deleteRef) { pUpdate->SetDeleteRef(deleteRef); };
		static UpdatableManager::UpdatableListRef& GetDeleteRef(Updatable* pUpdate) { return pUpdate->GetDeleteRef(); };
	};

	/// Provides access to private methods of GameObject related to drawing
	class Draw
	{
		friend class DrawableManager;
		friend class Drawable3DRegCmd;
		friend class Drawable3DDeRegCmd;
		friend class Drawable2DRegCmd;
		friend class Drawable2DDeRegCmd;
		static void Draw3DObject(Drawable* pDraw) { pDraw->Draw3D(); };
		static void Draw2DObject(Drawable* pDraw) { pDraw->Draw2D(); };

		static void Set3DRegStatusRegistered(Drawable* pDraw) { pDraw->Set3DRegStatusRegistered(); };
		static void Set3DRegStatusDeregistered(Drawable* pDraw) { pDraw->Set3DRegStatusDeregistered(); };
		
		static void Set2DRegStatusRegistered(Drawable* pDraw) { pDraw->Set2DRegStatusRegistered(); };
		static void Set2DRegStatusDeregistered(Drawable* pDraw) { pDraw->Set2DRegStatusDeregistered(); };

		static void SetDeleteRef3D(Drawable* pDraw, DrawableManager::DrawableListRef deleteRef) { pDraw->SetDeleteRef3D(deleteRef); };
		static DrawableManager::DrawableListRef& GetDeleteRef3D(Drawable* pDraw) { return pDraw->GetDeleteRef3D(); };
		static void SetDeleteRef2D(Drawable* pDraw, DrawableManager::DrawableListRef deleteRef) { pDraw->SetDeleteRef2D(deleteRef); };
		static DrawableManager::DrawableListRef& GetDeleteRef2D(Drawable* pDraw) { return pDraw->GetDeleteRef2D(); };
	};

	/// Provides access to private methods of GameObject related to alarms
	class Alarm
	{
		friend class AlarmableManager;
		friend class AlarmableRegCmd;
		friend class AlarmableDeRegCmd;
		static void TriggerAlarmObject(Alarmable* pAlarm,const unsigned int alarmNum) { pAlarm->TriggerAlarm(alarmNum); };

		static void SetRegStatusRegistered(Alarmable* pAlarm,const unsigned int alarmNum) { pAlarm->SetRegStatusRegistered(alarmNum); };
		static void SetRegStatusDeregistered(Alarmable* pAlarm,const unsigned int alarmNum) { pAlarm->SetRegStatusDeregistered(alarmNum); };

		static void SetDeleteRef(Alarmable* pAlarm, AlarmableManager::AlarmableListRef deleteRef,const unsigned int alarmNum) { pAlarm->SetDeleteRef(deleteRef, alarmNum); };
		static AlarmableManager::AlarmableListRef& GetDeleteRef(Alarmable* pAlarm,const unsigned int alarmNum) { return pAlarm->GetDeleteRef(alarmNum); };

	};

	/// Provides access to private methods of GameObject related to input
	class Input
	{
		friend class InputableRegCmd;
		friend class InputableDeRegCmd;
		friend class KeyEventManager;
		friend class SingleKeyEvent;
		static void KeyPressed(JAZUL_KEY key, Inputable* pInput) { pInput->KeyPressed(key); };
		static void KeyReleased(JAZUL_KEY key, Inputable* pInput) { pInput->KeyReleased(key); };

		static void RegisterKeyToScene(JAZUL_KEY key, EventType ke, Inputable* pInput) { pInput->RegisterKeyToScene(key, ke); };
		static void DeregisterKeyFromScene(JAZUL_KEY key, EventType ke, Inputable* pInput) { pInput->DeregisterKeyFromScene(key, ke); };
		
		static void SetDeleteRef(JAZUL_KEY key, EventType ev, SingleKeyEvent::KeyListRef listRef, Inputable* pInput) { pInput->SetDeleteRef(key, ev, listRef); };
		static SingleKeyEvent::KeyListRef GetDeleteRef(JAZUL_KEY key, EventType ev, Inputable* pInput) { return pInput->GetDeleteRef(key, ev); };
	};

	/// Provides access to private methods of GameObject related to collision
	class Collision
	{
		friend class CollisionManager;
		friend class CollidableRegCmd;
		friend class CollidableDeRegCmd;
		friend class CollidableGroup;
		friend class Visualizer;

		friend class CollisionTestSelfCmd;
		friend class CollisionTestPairCmd;
		friend class CollisionTestTerrainCmd;
		
		friend class VisualizerDrawAllCollidable;
		friend class VisualizerDrawSelectCollidable;

		static const Collidable::ColID GetCollisionID(Collidable* pCol) { return pCol->GetCollisionID(); };
		static void SetRegStatusRegistered(Collidable* pCol) { pCol->SetRegStatusRegistered(); };
		static void SetRegStatusDeregistered(Collidable* pCol) { pCol->SetRegStatusDeregistered(); };
		static const CollisionVolume& GetColVol(const Collidable* pCol) { return pCol->GetColVolume(); };
		static const CollisionVolume& GetColPrimitiveVolume(Collidable* pCol) { return pCol->GetPrimitiveVolume(); };
	};

	/// Provides access to private methods of GameObject related to general management
	class GameObj 
	{
		friend class GameObjectRegCmd;
		friend class GameObjectDeRegCmd;
		static void ConnectToScene(GameObject* pGO) { pGO->ConnectToScene(); };
		static void DisconnectFromScene(GameObject* pGO) { pGO->DisconnectFromScene(); };
	};
};

#endif // GAMEOBJECTATTORNEY_H