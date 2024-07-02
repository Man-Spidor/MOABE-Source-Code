#ifndef TERRAINOBJECTMANAGER_H
#define TERRAINOBJECTMANAGER_H

#include <map>

class MOABETerrain;

/// @brief Manages the loading, retrieval, and unloading of terrain objects.
/// 
/// This singleton class provides functionality to load terrain objects from heightmap files,
/// retrieve loaded terrain objects by key, and unload all terrain objects.
class TerrainObjectManager
{
private:
    /// @brief Private constructor to enforce singleton pattern.
    TerrainObjectManager();

    /// @brief Deleted copy constructor.
    /// @param other The other TerrainObjectManager to copy from.
    TerrainObjectManager(const TerrainObjectManager& other) = delete;

    /// @brief Deleted copy assignment operator.
    TerrainObjectManager& operator=(const TerrainObjectManager& other) = delete;

    /// @brief Move constructor.
    TerrainObjectManager(TerrainObjectManager&& other) = delete;

    /// @brief Move assignment operator.
    TerrainObjectManager& operator=(TerrainObjectManager&& other) = delete;

    /// @brief Destructor.
    ~TerrainObjectManager();

public:
    /// @brief Load a terrain object from a heightmap file.
    /// 
    /// This function loads a terrain object using a heightmap file and specified parameters.
    /// The loaded terrain object is associated with the specified key.
    /// 
    /// @param key The key to identify the terrain object.
    /// @param heightmapFile The path to the heightmap file.
    /// @param len The length of the terrain.
    /// @param maxheight The maximum height of the terrain.
    /// @param ytrans The y-axis translation of the terrain.
    /// @param RepeatU The number of times the texture repeats in the U direction.
    /// @param RepeatV The number of times the texture repeats in the V direction.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void LoadTerrains() {
    ///     TerrainObjectManager::Load("terrain1", L"heightmap1.tga", 100.0f, 10.0f, 0.0f, 10, 10);
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static void Load(const char* const key, LPCWSTR heightmapFile, float len, float maxheight, float ytrans, int RepeatU, int RepeatV);

    /// @brief Retrieve a terrain object associated with a key.
    /// 
    /// This function retrieves the terrain object associated with the specified key.
    /// 
    /// @param key The key identifying the terrain object.
    /// @return Pointer to the terrain object, or nullptr if not found.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void Initialize() {
    ///     SceneManager::GetCurrScene().SetTerrain(TerrainObjectManager::Get("terrain1));
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static MOABETerrain* Get(const char* const key);

    /// @brief Unload all loaded terrain objects.
    /// 
    /// This function unloads all terrain objects currently loaded by the TerrainObjectManager.
    static void Unload();

private:
    /// @brief Get the singleton instance of the TerrainObjectManager.
    /// 
    /// @return Reference to the TerrainObjectManager instance.
    static TerrainObjectManager& Instance();

    static TerrainObjectManager* instance; ///< Singleton instance of the TerrainObjectManager.

    using TerrainMap = std::map<const char* const, MOABETerrain*>;
    TerrainMap savedTerrains; ///< Map of saved terrain objects.

    /// Default file path for loading terrains
    std::wstring DefaultPath;
};

#endif // TERRAINOBJECTMANAGER_H
