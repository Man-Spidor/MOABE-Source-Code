#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include "SceneStrategies.h"

/// Responsible for all things Scene related
/// 
/// Singleton class that manages scenes in the game engine, allowing for scene switching and updates.
/// 
/// @note There is no need to manage any the memory around any Scene pointers, 
/// the SceneManager is responsible for their memory management.
class SceneManager : public Align16
{	
	/// SceneManagerAttorney class restricts access to private SceneManager Methods
	friend class SceneManagerAttorney;
public:
	/// Default constructor
	SceneManager();
	/// Copy constructor deleted
	SceneManager(const SceneManager& other) = delete;
	/// Copy assignment operator deleted
	SceneManager& operator=(const SceneManager& other) = delete;
	/// Move constructor deleted
	SceneManager(SceneManager&& other) = delete;
	/// Move assignment operator deleted
	SceneManager& operator=(SceneManager&& other) = delete;
	/// Default destructor
	~SceneManager();

private:
	/// Initializes the start scene
	static void InitStartScene();

public:
	/// Sets the start scene
	///
	/// Should only be called ONCE in MOABE::LoadAllContent() or MOABE::GameStart(). Meant to set 
	/// the very first Scene the SceneManager should initialize().
	/// 
	/// @param pScene The scene which should be loaded first.
	static void SetStartScene(Scene* pScene);

	/// Retrieves the current active scene.
	///
	/// This function returns a reference to the currently active scene.
	///
	/// @return Reference to the current active scene.
	static Scene& GetCurrScene();

	/// Switches the current scene to the provided scene.
	///
	/// This function switches the current scene of the game to the provided scene pointer.
	/// 
	/// @note The scene switch occurs at the END of the update call.
	///
	/// @param pScene Pointer to the scene to switch to.
	static void SwitchCurrScene(Scene* pScene);

	/// Switches the game to play mode.
	///
	/// This function switches the game to play mode, deactivating the God Camera and resuming 
	/// normal gameplay.
	static void SwitchPlayMode();

	/// Switches the game to debug mode.
	///
	/// This function switches the game to debug mode, activating the God Camera.
	static void SwitchDebugMode();

	static void SetCurrCamera3D(Camera* pCam);
	static void SetCurrCamera2D(Camera* pCam);

private:
	/// Updates the scene manager
	static void Update();

	/// Draws the scene manager
	static void Draw();

	/// Deletes the scene manager
	static void Delete();

	/// Starts the next scene
	static void StartNextScene();

	/// Retrieves the inputs for the god camera
	static void GetGodCamInputs();

private:
	/// Initializes the current scene
	void privInitScene();

	/// Switches the current scene to the specified scene
	void privSwitchCurrScene(Scene* pScene);

	/// Starts the next scene
	void privStartNextScene();

private:
	static const float camRotAngle; ///< The rotation angle for the camera
	static const float camMoveSpeed; ///< The movement speed for the camera

	static SceneManager& Instance(); ///< Retrieves the instance of the scene manager
	static SceneManager* instance; ///< Pointer to the instance of the scene manager

	Scene* pCurrScene; ///< Pointer to the current scene
	Scene* pNextScene; ///< Pointer to the next scene
	const SceneStrategy* sceneStrategy; ///< Pointer to the scene strategy
};

#endif // SCENEMANAGER_H
