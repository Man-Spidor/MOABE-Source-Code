#ifndef TERRAINOBJECT_H
#define TERRAINOBJECT_H

#include "TerrainModel.h"

class Texture;
class TerrainArea;

/// Abstract base class for terrain objects.
/// 
/// This class provides an interface for terrain objects, including methods for rendering, setting world transformations,
/// setting textures and materials, and retrieving terrain areas and models.
class TerrainObject
{
public:
    TerrainObject() = default;
    TerrainObject(const TerrainObject& other) = default;
    TerrainObject& operator=(const TerrainObject& other) = default;
    TerrainObject(TerrainObject&& other) = default;
    TerrainObject& operator=(TerrainObject&& other) = default;
    virtual ~TerrainObject() = default;

    /// Render the terrain object.
    virtual void Render() = 0;

    /// Set the world transformation matrix.
    /// @param World The world matrix.
    virtual void SetWorld(const Matrix World) = 0;

    /// Set the texture for the terrain object.
    /// @param pTexture Pointer to the texture.
    virtual void SetTexture(Texture* pTexture) = 0;

    /// Set the material properties for the terrain object.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    virtual void SetMaterial(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) = 0;

    /// Get the terrain area within specified bounds.
    /// @param Min The minimum bounds.
    /// @param Max The maximum bounds.
    /// @return Pointer to the terrain area.
    virtual const TerrainArea* GetTerrainArea(const Vect& Min, const Vect& Max) const = 0;

    /// Get the terrain model.
    /// @return Pointer to the terrain model.
    virtual const TerrainModel* GetTerrainModel() const = 0;
};

#endif // TERRAINOBJECT_H
