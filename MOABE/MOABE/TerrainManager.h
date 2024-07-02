#ifndef TERRAINMANAGER_H
#define TERRAINMANAGER_H

#include "MOABENullTerrain.h"

class MOABETerrain;
class TerrainModel;

/// Manages terrain objects.
/// 
/// This class provides functionality to render terrain, switch between different terrains, and retrieve terrain objects and models.
class TerrainManager
{
public:
    TerrainManager();
    TerrainManager(const TerrainManager& other) = default;
    TerrainManager& operator=(const TerrainManager& other) = default;
    TerrainManager(TerrainManager&& other) = default;
    TerrainManager& operator=(TerrainManager&& other) = default;
    ~TerrainManager() = default;

    /// Render the current terrain.
    void RenderTerrain();

    /// Switch to a new terrain.
    /// @param pNextTerrain Pointer to the new terrain.
    void SwitchTerrain(MOABETerrain* pNextTerrain);

    /// Get the current terrain object.
    /// @return Reference to the current terrain object.
    TerrainObject& GetTerrainObject() const;

    /// Get the current terrain model.
    /// @return Reference to the current terrain model.
    const TerrainModel& GetCurrTerrain() const;

private:
    MOABENullTerrain NullTerrain; ///< Null terrain object.
    TerrainObject* pCurrTerrain; ///< Pointer to the current terrain object.
};

#endif // TERRAINMANAGER_H
