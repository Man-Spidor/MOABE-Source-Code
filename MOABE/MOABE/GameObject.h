#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Updatable.h"
#include "Drawable.h"
#include "Alarmable.h"
#include "Inputable.h"
#include "Collidable.h"

class GameObjectRegCmd;
class GameObjectDeRegCmd;


/// This Is MOABE's GameObject class
/// 
/// MOABE's GameObject class should be the base for all User-Built GameObjects. 
/// @see Updatable Drawable Alarmable Inputable Collidable
/// 
class GameObject : public Updatable, public Drawable, public Alarmable, public Inputable, public Collidable
{
	/// GameObjectAttorney class restricts access to private GameObject Methods
	friend class GameObjectAttorney;
public:
	GameObject();
	GameObject(const GameObject& other) = default;
	GameObject& operator=(const GameObject& other) = default;
	GameObject(GameObject&& other) = default;
	GameObject& operator=(GameObject&& other) = default;
	virtual ~GameObject();

private:
	void ConnectToScene();
	void DisconnectFromScene();
	
	/// Called On An Objects Entry Into The Scene
	/// 
	/// Here in GameObject, SceneEntry has an empty definition. This is because not all GameObjects require
	/// dynamic entry into the scene. SceneEntry is called upon a GameObjects entry into a scene. This is similar to SceneExit().
	/// 
	/// @see SceneExit()
	virtual void SceneEntry() { };

	/// Called On An Objects Exit From The Scene
	/// 
	/// Here in GameObject, SceneExit has an empty definition. This is because not all GameObjects require
	/// dynamic exit from the scene. SceneExit is called upon a GameObjects exit from a scene. This is similar to SceneEntry().
	/// 
	/// @see SceneEntry()
	virtual void SceneExit() { };

public:
	/// Function Used To Enter GameObjects Into Scene Dynamically
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// Bullet* b = BulletFactory::GetBullet();
	/// b->SubmitEntry();
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see SubmitExit()
	/// @warning You can only SubmitEntry ONCE. Calling it on an object that is registered or 
	/// is pending registration WILL cause an error. 
	void SubmitEntry();

	/// Function Used To Exit GameObjects From Scene Dynamically
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void Bullet::Collision(Player*) {
	///		b->SubmitExit();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see SubmitExit()
	/// @warning You can only SubmitExit ONCE. Calling it on an object that is not registered or 
	/// is pending deregistration WILL cause an error. 
	void SubmitExit();

private:
	RegistrationStatus regStatus;
	GameObjectRegCmd* pRegCmd;
	GameObjectDeRegCmd* pDeRegCmd;
};

#endif // GAMEOBJECT_H
