#ifndef SKYBOXOBJECTMANAGER_H
#define SKYBOXOBJECTMANAGER_H

#include <map>

class MOABESkybox;

/// @brief Manages the loading, retrieval, and unloading of terrain objects.
/// 
/// This singleton class provides functionality to load terrain objects from heightmap files,
/// retrieve loaded terrain objects by key, and unload all terrain objects.
class SkyboxObjectManager
{
private:
    /// @brief Private constructor to enforce singleton pattern.
    SkyboxObjectManager();

    /// @brief Deleted copy constructor.
    /// @param other The other SkyboxObjectManager to copy from.
    SkyboxObjectManager(const SkyboxObjectManager& other) = delete;

    /// @brief Deleted copy assignment operator.
    SkyboxObjectManager& operator=(const SkyboxObjectManager& other) = delete;

    /// @brief Move constructor.
    SkyboxObjectManager(SkyboxObjectManager&& other) = delete;

    /// @brief Move assignment operator.
    SkyboxObjectManager& operator=(SkyboxObjectManager&& other) = delete;

    /// @brief Destructor.
    ~SkyboxObjectManager();

public:
    /// Load a skybox object using a given sky texture key and scale
    /// 
    /// This function loads a terrain object using a heightmap file and specified parameters.
    /// The loaded terrain object is associated with the specified key.
    /// 
    /// @param key The key to identify the skybox object.
    /// @param scale The scale you would like the skybox to be.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void LoadSkybox() {
    ///     SkyboxObjectManager::Load("CitySkybox", 1000.0f);
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static void Load(const char* const key, const float scale);

    /// Retrieve a terrain object associated with a key.
    /// 
    /// This function retrieves the terrain object associated with the specified key.
    /// 
    /// @param key The key identifying the skybox object.
    /// @return Pointer to the skybox object, or nullptr if not found.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void Initialize() {
    ///     SceneManager::GetCurrScene().SetSkybox(SkyboxObjectManager::Get("CitySkybox));
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static MOABESkybox* Get(const char* const key);

    /// @brief Unload all loaded skybox objects.
    /// 
    /// This function unloads all terrain objects currently loaded by the SkyboxObjectManager.
    static void Unload();

private:
    /// @brief Get the singleton instance of the SkyboxObjectManager.
    /// 
    /// @return Reference to the SkyboxObjectManager instance.
    static SkyboxObjectManager& Instance();

    static SkyboxObjectManager* instance; ///< Singleton instance of the SkyboxObjectManager.

    using SkyboxMap = std::map<const char* const, MOABESkybox*>;
    SkyboxMap savedSkyboxes; ///< Map of saved terrain objects.

    /// Default file path for loading terrains
    std::wstring DefaultPath;
};

#endif // SKYBOXOBJECTMANAGER_H

