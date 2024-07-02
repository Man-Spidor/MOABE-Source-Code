#ifndef TERRAINAREA_H
#define TERRAINAREA_H

#include "TerrainAreaIterator.h"

class TerrainModel;
class Vect;

struct TerrainCell;

/// @brief Represents a specific area within a terrain model.
///
/// This class provides functionality to define, iterate, and access cells within a specified area of a terrain model.
/// 
/// @see TerrainObject
/// @see MOABETerrain
/// @see TerrainAreaIterator
class TerrainArea
{
public:
    /// @brief Default constructor is deleted.
    TerrainArea() = delete;

    /// @brief Default copy constructor.
    /// @param other The other TerrainArea to copy from.
    TerrainArea(const TerrainArea& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other TerrainArea to copy from.
    /// @return A reference to this TerrainArea.
    TerrainArea& operator=(const TerrainArea& other) = default;

    /// @brief Default move constructor.
    /// @param other The other TerrainArea to move from.
    TerrainArea(TerrainArea&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other TerrainArea to move from.
    /// @return A reference to this TerrainArea.
    TerrainArea& operator=(TerrainArea&& other) = default;

    /// @brief Destructor.
    ~TerrainArea() = default;

    /// @brief Constructs a TerrainArea for a given terrain model.
    /// @param _Terrain The terrain model.
    TerrainArea(const TerrainModel& _Terrain);

    /// @brief Sets the area within the terrain model defined by minimum and maximum vectors.
    /// @param Min The minimum vector defining the area.
    /// @param Max The maximum vector defining the area.
    void SetArea(const Vect& Min, const Vect& Max);

    /// @brief Retrieves the terrain model.
    /// @return Reference to the terrain model.
    const TerrainModel& GetTerrain() const;

    /// @brief Retrieves the beginning iterator for the terrain area.
    /// @return Reference to the beginning iterator.
    const TerrainAreaIterator& begin() const;

    /// @brief Retrieves the ending iterator for the terrain area.
    /// @return Reference to the ending iterator.
    const TerrainAreaIterator& end() const;

    /// @brief Retrieves the width of a cell in the terrain area.
    /// @return The width of a cell.
    const float CellWidth() const;

    /// @brief Retrieves the terrain cell at the specified x and z coordinates.
    /// @param x The x-coordinate.
    /// @param z The z-coordinate.
    /// @return Reference to the terrain cell.
    const TerrainCell& GetTerrainCell(const float x, const float z) const;

private:
    const TerrainModel& Terrain; ///< Reference to the terrain model.
    TerrainAreaIterator Front; ///< The beginning iterator for the terrain area.
    TerrainAreaIterator Back; ///< The ending iterator for the terrain area.
    const float cellwidth; ///< The width of a cell in the terrain area.
};

#endif // TERRAINAREA_H
