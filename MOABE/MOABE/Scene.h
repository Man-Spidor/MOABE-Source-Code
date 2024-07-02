#ifndef SCENE_H
#define SCENE_H

#include "RegistrationBroker.h"
#include "CameraManager.h"
#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "AlarmableManager.h"
#include "KeyEventManager.h"
#include "CollisionManager.h"
#include "TerrainManager.h"
#include "LightManager.h"
#include "MOABESkyNull.h"

class Texture;
class Updatable;
class Drawable;
class Alarmable;
class Inputable;
class Collidable;
class MOABESkybox;
class RegistrationCommand;

/// @class Scene
/// @brief Represents a scene in the game.
///
/// This class represents a scene in the game engine. Users can derive their own scene classes from this 
/// to create custom scenes for their games. Scenes encapsulate the logic and elements of a particular 
/// game state or level.
///
/// Users of this class should inherit from it and provide their own implementations for the Initialize()
/// and SceneEnd() methods. These methods are called automatically by the SceneManager when the scene is
/// initialized and when it is ending, respectively.
///
/// ### Example Usage:
/// 
/// Suppose we have a custom scene called "GameplayScene" derived from Scene. We want to initialize the 
/// scene with certain game objects and assets when it's loaded, and perform cleanup when it's ending.
/// 
/// We can define our GameplayScene as follows:
///
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// class GameplayScene : public Scene
/// {
/// public:
///     virtual void Initialize() override
///     {
///         // Initialize game objects, load assets, etc.
///         Scene::EnableSceneLight();
///         Scene::SetLi
/// 
///     }
///     
///     virtual void SceneEnd() override
///     {
///         // Cleanup resources, release memory, etc.
///     }
/// };
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// Now, when the SceneManager switches to our GameplayScene, it will automatically call Initialize() to 
/// set up the scene, and when the scene is about to end, it will call SceneEnd() to perform any necessary
/// cleanup.
class Scene {
    /// @brief SceneAttorney class restricts access to private Scene methods.
    friend class SceneAttorney;
public:
    /// @brief Default constructor.
    Scene();
    
    /// @brief Deleted copy constructor.
    /// @param other The other Scene to copy from.
    Scene(const Scene& other) = delete;
    
    /// @brief Deleted copy assignment operator.
    /// @param other The other Scene to copy from.
    /// @return A reference to this Scene.
    Scene& operator=(const Scene& other) = delete;
    
    /// @brief Deleted move constructor.
    /// @param other The other Scene to move from.
    Scene(Scene&& other) = delete;
    
    /// @brief Deleted move assignment operator.
    /// @param other The other Scene to move from.
    /// @return A reference to this Scene.
    Scene& operator=(Scene&& other) = delete;
    
    /// @brief Destructor.
    virtual ~Scene();

#pragma region Scene Main Functions
private:
    /// @brief Initializes the scene.
    virtual void Initialize() = 0;

    /// @brief Ends the scene.
    virtual void SceneEnd() = 0;

    /// @brief Clears the managers.
    void ClearManagers();

    /// @brief Updates the scene.
    void Update();

    /// @brief Draws the scene.
    void Draw();
#pragma endregion

#pragma region Scene Registration Functions
    /// @brief Submits a registration command.
    /// @param pCmd Pointer to the registration command.
    void SubmitRegistrationCommand(const RegistrationCommand* pCmd);

    /// @brief Registers an updatable object.
    /// @param pUpdate Pointer to the updatable object.
    void Register(Updatable* pUpdate);

    /// @brief Registers a 3D drawable object.
    /// @param pDraw Pointer to the drawable object.
    void Register3D(Drawable* pDraw);

    /// @brief Registers a 2D drawable object.
    /// @param pDraw Pointer to the drawable object.
    void Register2D(Drawable* pDraw);

    /// @brief Registers an alarmable object.
    /// @param time The time for the alarm.
    /// @param pAlarm Pointer to the alarmable object.
    /// @param alarmNum The alarm number.
    void Register(float time, Alarmable* pAlarm, const unsigned int alarmNum);

    /// @brief Registers a collidable object.
    /// @param pCol Pointer to the collidable object.
    void Register(Collidable* pCol);

    /// @brief Deregisters an updatable object.
    /// @param pUpdate Pointer to the updatable object.
    void Deregister(Updatable* pUpdate);

    /// @brief Deregisters a 3D drawable object.
    /// @param pDraw Pointer to the drawable object.
    void Deregister3D(Drawable* pDraw);

    /// @brief Deregisters a 2D drawable object.
    /// @param pDraw Pointer to the drawable object.
    void Deregister2D(Drawable* pDraw);

    /// @brief Deregisters an alarmable object.
    /// @param pAlarm Pointer to the alarmable object.
    /// @param alarmNum The alarm number.
    void Deregister(Alarmable* pAlarm, const unsigned int alarmNum);

    /// @brief Deregisters a collidable object.
    /// @param pCol Pointer to the collidable object.
    void Deregister(Collidable* pCol);

    /// @brief Registers a key event.
    /// @param key The key.
    /// @param ke The key event type.
    /// @param pInput Pointer to the inputable object.
    void RegisterKey(JAZUL_KEY key, EventType ke, Inputable* pInput);

    /// @brief Deregisters a key event.
    /// @param key The key.
    /// @param ke The key event type.
    /// @param pInput Pointer to the inputable object.
    void DeregisterKey(JAZUL_KEY key, EventType ke, Inputable* pInput);

    /// @brief Registers a directional light.
    /// @param pDirLight Pointer to the directional light.
    void RegisterLight(MOABEDirectionalLight* pDirLight);

    /// @brief Registers a point light.
    /// @param pPointLight Pointer to the point light.
    void RegisterLight(MOABEPointLight* pPointLight);

    /// @brief Registers a spotlight.
    /// @param pSpotLight Pointer to the spotlight.
    void RegisterLight(MOABESpotLight* pSpotLight);

    /// @brief Deregisters a directional light.
    /// @param pDirLight Pointer to the directional light.
    void DeregisterLight(MOABEDirectionalLight* pDirLight);

    /// @brief Deregisters a point light.
    /// @param pPointLight Pointer to the point light.
    void DeregisterLight(MOABEPointLight* pPointLight);

    /// @brief Deregisters a spotlight.
    /// @param pSpotLight Pointer to the spotlight.
    void DeregisterLight(MOABESpotLight* pSpotLight);
#pragma endregion

#pragma region Utility Functions
public:
    /// @brief Enables scene lighting.
    void EnableSceneLight() const;

    /// @brief Disables scene lighting.
    void DisableSceneLight() const;

    /// @brief Sets the light mode to normal.
    /// 
    /// The default processing mode for lights, this renders every light in the scene up to the maximum limit, then only renders the closest past that.
    void SetLightModeNormal();

    /// @brief Sets the light mode to cull by distance.
    /// 
    /// Cull by distance mode will tell the light manager to ignore any lights past a minimum render distance.
    /// 
    /// @param distance The minimum render distance.
    void SetLightModeCullByDist(const float distance);

    /// @brief Sets the light mode to cull by view.
    /// 
    /// Cull by view mode will tell the light manager to ignore any lights BEHIND the camera and past a minimum render distance.
    /// 
    /// @param distance The minimum render distance.
    void SetLightModeCullByView(const float distance);

    /// @brief Retrieves the main camera.
    /// @return Reference to the main camera.
    Camera& GetMainCamera() const;

    /// @brief Retrieves the 2D camera.
    /// @return Reference to the 2D camera.
    Camera& Get2DCamera() const;

    /// @brief Sets the current 3D camera.
    /// 
    /// The 3D camera is the camera used to render all 3D objects in a scene. This is opposed to the 2D camera which is used to render all 2D objects in a scene, i.e. Sprites, Text, etc...
    /// 
    /// @param pCam Pointer to the camera object.
    /// 
    /// ### Example Usage:
    /// 
    /// Suppose we have a custom camera object called "myCamera" and we want to set it as the current camera
    /// in our scene:
    /// 
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// 
    /// Camera* myCamera = new PerspectiveCamera();
    /// 
    /// // Initialize the camera
    ///  
    /// SceneManager::GetCurrScene().SetCurrCamera3D(myCamera);
    /// 
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void SetCurrCamera3D(Camera*& pCam);

    /// @brief Sets the current 2D camera.
    /// 
    /// The 2D camera is the camera used to render all 4D objects in a scene. This is opposed to the 3D camera which is used to render all 2D objects in a scene, i.e. Models
    /// 
    /// ### Example Usage:
    /// 
    /// Suppose we have a custom camera object called "myCamera" and we want to set it as the current camera
    /// in our scene:
    /// 
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// 
    /// Camera* myCamera = new OrthographicCamera();
    /// 
    /// // Initialize the camera
    ///  
    /// SceneManager::GetCurrScene().SetCurrCamera2D(myCamera);
    /// 
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /// 
    /// @param pCam Pointer to the camera object.
    void SetCurrCamera2D(Camera*& pCam);

    /// @brief Sets the position and orientation of the current camera.
    /// 
    /// This function allows users to set the position, look-at direction, and up vector of the current camera
    /// in the scene.
    /// 
    /// @param upVector The up vector of the camera.
    /// @param pos3DCam The position of the camera.
    /// @param lookAt3DCam The look-at direction of the camera.
    /// 
    /// ### Example Usage:
    /// 
    /// Suppose we want to set the position and orientation of the current camera in our scene:
    /// 
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// Vect upVector(0, 1, 0);
    /// Vect position(10, 5, -20);
    /// Vect lookAt(0, 0, 0);
    /// SceneManager::GetCurrScene().SetCurrCameraPos(upVector, position, lookAt);
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void SetCurrCameraPos(Vect upVector, Vect pos3DCam, Vect lookAt3DCam);

    /// @brief Sets the default camera as the current camera.
    /// 
    /// Called by the default scene constructor to avoid Cameraless scenes
    void SetDefaultCameraAsCurr();

    /// @brief Updates the current camera.
    void UpdateCurrCamera();

    /// @brief Sets the current terrain model.
    /// 
    /// Sets the current terrain model and enables it to automatically be rendered
    /// 
    /// @param pTerrain Pointer to the new terrain model.
    void SetTerrain(MOABETerrain* pTerrain);

    /// @brief Retrieves the current terrain model.
    /// 
    /// Used for terrain collision processing.
    /// 
    /// @return Reference to the current terrain model.
    const TerrainModel& GetTerrainModel() const;

    /// @brief Retrieves the terrain area based on the minimum and maximum vectors.
    /// @param Min The minimum vector.
    /// @param Max The maximum vector.
    /// @return Reference to the terrain area.
    const TerrainArea& GetTerrainArea(const Vect& Min, const Vect& Max) const;

    /// @brief Sets the world matrix for the terrain.
    /// @param World The world matrix.
    void SetTerrainWorld(const Matrix World);

    /// @brief Sets the texture for the terrain.
    /// @param pTexture Pointer to the texture.
    void SetTerrainTexture(Texture* pTexture);

    /// @brief Sets the material properties for the terrain.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    void SetTerrainMaterial(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular);

    /// @brief Sets the skybox object.
    /// @param pSkybox Pointer to the skybox object.
    void SetSkyBox(MOABESkybox* pSkybox);

private:
    /// Activates the god camera.
    /// 
    /// Called by the SceneManager
    /// 
    /// @see SceneManager
    /// 
    /// GodCam Controls:
    /// 
    /// Up Arrow:       Move Forward
    /// Down Arrow:     Move Backward
    /// Right Arrow:    Look Right
    /// Left Arrow:     Look Left
    /// 
    /// X:              Tilt Down
    /// Z:              Tilt Up
    void ActivateGodCam();
#pragma endregion

#pragma region Templated Collision Functions
protected:
    /// @brief Sets collision between objects of the same type.
    template< typename C1>
    void SetCollisionSelf()
    {
        this->colMan.SetCollisionSelf<C1>();
    }

    /// @brief Sets collision between objects of different types.
    template< typename C1, typename C2>
    void SetCollisionPair()
    {
        this->colMan.SetCollisionPair<C1, C2>();
    }

    /// @brief Sets collision between objects and the terrain.
    template<typename C>
    void SetCollisionTerrain()
    {
        this->colMan.SetCollisionTerrain<C>();
    }

public:
    /// @brief Retrieves the collision manager.
    /// @return Reference to the collision manager.
    CollisionManager& GetCollisionManager();
#pragma endregion

private:
    static MOABESkyNull NullSkyBox; ///< Null skybox object.
    Camera* pGodCam; ///< Pointer to the god camera.
    SkyboxObject* pSkyBox; ///< Pointer to the skybox object.

    RegistrationBroker cmdBroker; ///< Registration broker.
    CameraManager camMan; ///< Camera manager.
    UpdatableManager updateMan; ///< Updatable manager.
    DrawableManager drawMan; ///< Drawable manager.
    AlarmableManager alarmMan; ///< Alarmable manager.
    KeyEventManager keyMan; ///< Key event manager.
    CollisionManager colMan; ///< Collision manager.
    TerrainManager terrainMan; ///< Terrain manager.
    LightManager lightMan; ///< Light manager.
};

#endif // SCENE_H
