#ifndef UPDATABLE_H
#define UPDATABLE_H

#include "RegistrationStatus.h"
#include "UpdatableManager.h"

class RegistrationCommand;

/// Contains All Update Functionality 
/// 
/// This is the class responsible for Updating any GameObject.
class Updatable : public Align16
{
	/// GameObjectAttorney class restricts access to private Updatable Methods
	friend class GameObjectAttorney;
public:
	/// Default Constructor
	Updatable();
	/// Copy Constructor
	Updatable(const Updatable& other) = default;
	/// Copy Assignment
	Updatable& operator=(const Updatable& other) = default;
	/// Move Constructor
	Updatable(Updatable&& other) = default;
	/// Move Assignment
	Updatable& operator=(Updatable&& other) = default;
	/// Destructor
	virtual ~Updatable();

private:
	virtual void Update() { };

	void SetRegStatusRegistered();
	void SetRegStatusDeregistered();

	void SetDeleteRef(UpdatableManager::UpdatableListRef deleteRef);
	UpdatableManager::UpdatableListRef& GetDeleteRef();

protected:
	/// Function Used To Register GameObjects To The UpdatableManager To Be Updated
	/// 
	/// This is the function responsible for registering GameObjects to be updated. If you an object to be updated every frame, you MUST
	/// register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Updatable::RegisterToScene();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see UpdatableManager() DeregisterFromScene()
	/// @warning You can only SubmitEntry ONCE. Calling it on an object that is registered or 
	/// is pending registration WILL cause an error. 
	void RegisterToScene();

	/// Function Used To Register GameObjects To The UpdatableManager To Be Updated
	/// 
	/// This is the function responsible for deregistering GameObjects from being updated. If you no longer want an object to be 
	/// updated every frame, you MUST deregister it using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneExit() {
	///		Updatable::DeregisterFromScene();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see UpdatableManager() RegisterToScene()
	/// @warning You can only SubmitEntry ONCE. Calling it on an object that is registered or 
	/// is pending registration WILL cause an error. 
	void DeregisterFromScene();

private:
	RegistrationStatus regStatus;
	UpdatableManager::UpdatableListRef myDeleteRef;
	RegistrationCommand* pRegCmd;
	RegistrationCommand* pDeRegCmd;
};

#endif // UPDATABLE_H
