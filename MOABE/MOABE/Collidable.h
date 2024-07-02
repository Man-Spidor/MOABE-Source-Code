#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "RegistrationStatus.h"

class Model;
class Matrix;
class CV_BSphere;
class CollisionVolume;
class CollidableRegCmd;
class CollidableDeRegCmd;

/// Contains All Of A GameObject's Collision Data 
/// 
/// ### Usage Example:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// // Creating an instance of a class derived from Alarmable
/// class MyGameObject : public GameObject {
/// 	// ...
///		
///		MyGameObject() {
///			Collidable::SetCollidableGroup<MyGameObject>();
///			Collidable::SetBSphereModel(this->pModel);
///		}
/// 
///		// ...
/// };
/// 
/// // Registering Collision
/// void MyGameObject::SceneEntry() {
///		// ...
///		Collidable::RegisterToScene(); 
///		// ...
/// }
/// 
/// // Deregistering Collision
/// void MyGameObject::SceneEntry() {
///		// ...
///		Collidable::DeregisterFromScene();
///		// ...
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
/// This is the class responsible for keeping track of a GameObject's collision data.
class Collidable : public Align16
{
	/// GameObjectAttorney class restricts access to private Collidable Methods
	friend class GameObjectAttorney;
private:
	using ColID = unsigned int;

public:
	/// Default Constructor
	Collidable();
	/// Copy Constructor
	Collidable(const Collidable& other) = default;
	/// Copy Assignment
	Collidable& operator=(const Collidable& other) = default;
	/// Move Constructor
	Collidable(Collidable&& other) = default;
	/// Move Assignment
	Collidable& operator=(Collidable&& other) = default;
	/// Destructor
	virtual ~Collidable();

private:
	const ColID GetCollisionID();

	void SetRegStatusRegistered();
	void SetRegStatusDeregistered();

	const CollisionVolume& GetColVolume() const;
	const CollisionVolume& GetPrimitiveVolume() const;

protected:
	/// Function Used To Register GameObjects To The CollidableManager 
	/// 
	/// This is the function responsible for registering GameObjects to be checked for collision 
	/// events. If you an object to have collision, you MUST register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Collidable::RegisterToScene();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see CollidableManager() DeregisterFromScene()
	/// @warning You can only RegisterToScene() ONCE. Calling it on an object that is registered 
	/// or is pending registration WILL cause an error. 
	void RegisterToScene();

	/// Function Used To Register GameObjects To The CollidableManager 
	/// 
	/// This is the function responsible for registering GameObjects to be checked for collision 
	/// events. If you an object to have collision, you MUST register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Collidable::RegisterToScene();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see CollidableManager() DeregisterFromScene()
	/// @warning You can only RegisterToScene() ONCE. Calling it on an object that is registered 
	/// or is pending registration WILL cause an error. 
	void DeregisterFromScene();

	/// Set the ColID or Collidable Group
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SpaceFrigate::SpaceFrigate() {
	///		SetCollidableGroup<SpaceFrigate>();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @tparam C The type of Collidable group
	template < typename C>
	void SetCollidableGroup()
	{
		myID = SceneManager::GetCurrScene().GetCollisionManager().GetID<C>();
	}

	/// Set the collider model as a BSphere
	/// 
	/// @param pModel The model to set as collider
	void SetBSphereModel(Model* pModel);

	/// Set the collider model as an Axis Aligned Bounding Box
	/// 
	/// @param pModel The model to set as collider
	void SetAABBModel(Model* pModel);

	/// Set the collider model as an Oriented Bounding Box
	/// 
	/// @param pModel The model to set as collider
	void SetOBBModel(Model* pModel);

	/// Update collision data with a transformation matrix
	/// 
	/// @param mat The transformation matrix
	void UpdateCollisionData(const Matrix& mat);

	CollisionVolume* pColVol; ///< The Collidable's Collision Volume
	Model* pColModel; ///< Pointer to the collider model

public:
	void DrawCollidable() const;

private:
	CV_BSphere* pBSphere; ///< Collidable's Primitive Volume Used For Rougher but Faster Testing 

private:
	ColID myID;
	CollidableRegCmd* pRegCmd;
	CollidableDeRegCmd* pDeRegCmd;
	RegistrationStatus regStatus;
};

#endif // COLLIDABLE_H
