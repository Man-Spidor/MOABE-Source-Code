#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "RegistrationStatus.h"
#include "DrawableManager.h"

class Drawable3DRegCmd;
class Drawable3DDeRegCmd;

class Drawable2DRegCmd;
class Drawable2DDeRegCmd;

/// Contains All Draw Functionality 
/// 
/// This is the class responsible for drawing any GameObject.
class Drawable : public Align16
{
	/// GameObjectAttorney class restricts access to private Drawable Methods
	friend class GameObjectAttorney;
public:
	/// Default Constructor
	Drawable();
	/// Copy Constructor
	Drawable(const Drawable& other) = default;
	/// Copy Assignment
	Drawable& operator=(const Drawable& other) = default;
	/// Move Constructor
	Drawable(Drawable&& other) = default;
	/// Move Assignment
	Drawable& operator=(Drawable&& other) = default;
	/// Destructor
	virtual ~Drawable();

private:
	virtual void Draw3D() { };
	virtual void Draw2D() { };

	void Set3DRegStatusRegistered();
	void Set3DRegStatusDeregistered();
	void Set2DRegStatusRegistered();
	void Set2DRegStatusDeregistered();

	void SetDeleteRef3D(DrawableManager::DrawableListRef deleteRef);
	DrawableManager::DrawableListRef& GetDeleteRef3D();
	void SetDeleteRef2D(DrawableManager::DrawableListRef deleteRef);
	DrawableManager::DrawableListRef& GetDeleteRef2D();

protected:
	/// Function Used To Register GameObjects To The DrawableManager To Be Drawn
	/// 
	/// This is the function responsible for registering GameObjects to be drawn. If you an object to be Drawd every frame, you MUST
	/// register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Drawable::RegisterToScene3D();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see DrawableManager() DeregisterFromScene()
	/// @warning You can only RegisterToScene() ONCE. Calling it on an object that is 
	/// registered or is pending registration WILL cause an error. 
	void RegisterToScene3D();

	/// Function Used To Register GameObjects To The DrawableManager To Be Drawd
	/// 
	/// This is the function responsible for registering GameObjects to be Drawd. If you an object to be Drawd every frame, you MUST
	/// register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Drawable::RegisterToScene3D();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see DrawableManager() RegisterFromScene()
	/// @warning You can only DeregisterFromScene() ONCE. Calling it on an object that is 
	/// deregistered or is pending deregistration WILL cause an error. 
	void DeregisterFromScene3D();

	/// Function Used To Register GameObjects To The DrawableManager To Be Drawn
	/// 
	/// This is the function responsible for registering GameObjects to be drawn. If you an object to be Drawd every frame, you MUST
	/// register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Drawable::RegisterToScene2D();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see DrawableManager() DeregisterFromScene()
	/// @warning You can only RegisterToScene() ONCE. Calling it on an object that is 
	/// registered or is pending registration WILL cause an error. 
	void RegisterToScene2D();

	/// Function Used To Register GameObjects To The DrawableManager To Be Drawd
	/// 
	/// This is the function responsible for registering GameObjects to be Drawd. If you an object to be Drawd every frame, you MUST
	/// register then using this function.
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// void SceneEntry() {
	///		Drawable::RegisterToScene2D();
	/// }
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// 
	/// @see DrawableManager() RegisterFromScene()
	/// @warning You can only DeregisterFromScene() ONCE. Calling it on an object that is 
	/// deregistered or is pending deregistration WILL cause an error. 
	void DeregisterFromScene2D();

private:
	RegistrationStatus regStatus3D;
	RegistrationStatus regStatus2D;
	DrawableManager::DrawableListRef deleteRef3D;
	DrawableManager::DrawableListRef deleteRef2D;

	Drawable3DRegCmd* pRegCmd3D;
	Drawable3DDeRegCmd* pDeRegCmd3D;

	Drawable2DRegCmd* pRegCmd2D;
	Drawable2DDeRegCmd* pDeRegCmd2D;
};

#endif // DRAWABLE_H
