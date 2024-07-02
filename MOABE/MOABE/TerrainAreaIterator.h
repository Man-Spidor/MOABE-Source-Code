#ifndef TERRAINAREAITERATOR_H
#define TERRAINAREAITERATOR_H

class TerrainArea;

struct TerrainCell;

/// @brief Iterator for traversing cells within a specified terrain area.
/// 
/// @see TerrainObject
/// @see MOABETerrain
/// @see TerrainArea
class TerrainAreaIterator
{
public:
    /// @brief Default constructor is deleted.
    TerrainAreaIterator() = delete;

    /// @brief Default copy constructor.
    /// @param other The other TerrainAreaIterator to copy from.
    TerrainAreaIterator(const TerrainAreaIterator& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other TerrainAreaIterator to copy from.
    /// @return A reference to this TerrainAreaIterator.
    TerrainAreaIterator& operator=(const TerrainAreaIterator& other) = default;

    /// @brief Default move constructor.
    /// @param other The other TerrainAreaIterator to move from.
    TerrainAreaIterator(TerrainAreaIterator&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other TerrainAreaIterator to move from.
    /// @return A reference to this TerrainAreaIterator.
    TerrainAreaIterator& operator=(TerrainAreaIterator&& other) = default;

    /// @brief Destructor.
    ~TerrainAreaIterator() = default;

    /// @brief Constructs a TerrainAreaIterator for a given terrain area.
    /// @param _Area The terrain area.
    TerrainAreaIterator(const TerrainArea& _Area);

    /// @brief Sets the current point in the iterator.
    /// @param _x The x-coordinate.
    /// @param _z The z-coordinate.
    void SetPoint(const float _x, const float _z);

    /// @brief Equality comparison operator.
    /// @param other The other TerrainAreaIterator to compare.
    /// @return True if equal, false otherwise.
    const bool operator==(const TerrainAreaIterator& other);

    /// @brief Inequality comparison operator.
    /// @param other The other TerrainAreaIterator to compare.
    /// @return True if not equal, false otherwise.
    const bool operator!=(const TerrainAreaIterator& other);

    /// @brief Dereference operator to access the current terrain cell.
    /// @return Reference to the current terrain cell.
    const TerrainCell& operator*() const;

    /// @brief Pre-increment operator to advance the iterator.
    /// @return Reference to the advanced iterator.
    TerrainAreaIterator& operator++();

    /// @brief Post-increment operator to advance the iterator.
    /// @return The iterator before the increment.
    TerrainAreaIterator operator++(int);

public:
    float x; ///< The current x-coordinate in the iterator.
    float z; ///< The current z-coordinate in the iterator.

private:
    /// @brief Checks if the iterator has reached the edge of the cell in the x direction.
    /// @return True if the edge is reached, false otherwise.
    const bool privReachedEdgeOfCellX() const;

    /// @brief Checks if the iterator has reached the edge of the cell in the z direction.
    /// @return True if the edge is reached, false otherwise.
    const bool privReachedEdgeOfCellZ() const;

private:
    const TerrainArea* Area; ///< Pointer to the terrain area.
    const TerrainCell* Cell; ///< Pointer to the current terrain cell.
};

#endif // TERRAINAREAITERATOR_H
