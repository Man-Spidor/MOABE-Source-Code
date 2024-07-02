#ifndef INPUTABLE_H
#define INPUTABLE_H

#include "InputRegistrationData.h"
#include <map>

class InputableRegCmd;
class InputableDeRegCmd;

/// Contains All Input Event Functionality 
/// 
/// This is the class responsible for tracking input events for all registered keys.
class Inputable : public Align16
{
	/// GameObjectAttorney class restricts access to private Inputable Methods
	friend class GameObjectAttorney;
public:
	/// Default Constructor
	Inputable();
	/// Copy Constructor
	Inputable(const Inputable& other) = default;
	/// Copy Assignment
	Inputable& operator=(const Inputable& other) = default;
	/// Move Constructor
	Inputable(Inputable&& other) = default;
	/// Move Assignment
	Inputable& operator=(Inputable&& other) = default;
	/// Destructor
	virtual ~Inputable();

protected:
	/// Function Used To Register KeyEvents With A GameObject
	/// 
	/// This is the function responsible for registering Key Events. If you an object to be listen for Key Events, 
	/// you MUST register them using this function.
	/// 
	/// @param key The key you wish to register
	/// @param ke The EventType you wish to register
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_SPACE, EventType::KEY_PRESS);
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see InputableManager() DeregisterFromScene()
	/// @warning You can only RegisterKeyToScene() ONCE. Calling it on an object that is 
	/// registered or is pending registration WILL cause an error. 
	void RegisterKeyToScene(JAZUL_KEY key, EventType ke);

	/// Function Used To Deregister KeyEvents With A GameObject
	/// 
	/// This is the function responsible for deregistering Key Events. If you an object to be stop listening for 
	/// Key Events, you MUST deregister them using this function.
	/// 
	/// @param key The key you wish to deregister
	/// @param ke The EventType you wish to deregister
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneExit() {
	///		Inputable::DeregisterKeyFromScene(JAZUL_KEY::KEY_SPACE, EventType::KEY_PRESS);
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see InputableManager() DeregisterFromScene()
	/// @note The key and event type you wish to deregister must match with a key and event type already
	/// @warning You can only DeregisterKeyFromScene() ONCE. Calling it on an object that is 
	/// deregistered or is pending deregistration WILL cause an error. 
	void DeregisterKeyFromScene(JAZUL_KEY key, EventType ke);

private:
	void SetDeleteRef(JAZUL_KEY key, EventType ev, SingleKeyEvent::KeyListRef listRef);
	SingleKeyEvent::KeyListRef GetDeleteRef(JAZUL_KEY key, EventType ev);

	virtual void KeyPressed(JAZUL_KEY k);
	virtual void KeyReleased(JAZUL_KEY k);

private:
	using KeyID = std::pair<JAZUL_KEY, EventType>;
	using RegDataList = std::map<KeyID, InputRegData*>;
	RegDataList InputList;
};

#endif // INPUTABLE_H
