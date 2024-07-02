#ifndef MOABETERRAIN_H
#define MOABETERRAIN_H

#include "TerrainObject.h"

class Collidable;
class GraphicsObject_Wireframe;
class GraphicsObject_TextureLight;

/// Represents a terrain object with heightmap-based geometry.
/// 
/// This class provides functionality to load, render, and manage a terrain object using heightmap data.
class MOABETerrain : public TerrainObject
{
public:
    MOABETerrain() = delete;
    MOABETerrain(const MOABETerrain& other) = default;
    MOABETerrain& operator=(const MOABETerrain& other) = default;
    MOABETerrain(MOABETerrain&& other) = default;
    MOABETerrain& operator=(MOABETerrain&& other) = default;
    ~MOABETerrain();

    /// Constructor to initialize the terrain object with heightmap data.
    /// @param heightmapFile The heightmap file.
    /// @param len The length of the terrain.
    /// @param maxheight The maximum height of the terrain.
    /// @param ytrans The Y-axis translation.
    /// @param RepeatU The U-axis texture repetition.
    /// @param RepeatV The V-axis texture repetition.
    MOABETerrain(LPCWSTR heightmapFile, float len, float maxheight, float ytrans, int RepeatU, int RepeatV);

    /// Get the model of the terrain.
    /// @return Pointer to the terrain model.
    Model* GetModel() const;


    /// This function renders the terrain model as a textured graphics object
    /// 
    /// Called every frame by the TerrainManager as a part of the scene's draw loop
    /// 
    /// @see TerrainManager
    /// @see Scene
    virtual void Render() override;

    /// This function sets the world matrix of the terrain
    /// 
    /// @param World the new world matrix
    virtual void SetWorld(const Matrix World) override;

    /// This function sets the texture of the terrain
    /// 
    /// @param pTexture the new texture 
    virtual void SetTexture(Texture* pTexture) override;

    /// This function sets the lighting material of the terrain
    /// 
    /// @param pTexture the new lighting material of the terrain
    virtual void SetMaterial(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) override;

    /// This function returns the Terrain model
    /// 
    /// @returns pointer to the TerrainModel
    virtual const TerrainModel* GetTerrainModel() const override;

    /// This function returns a TerrainArea between a specified Min and Max point
    /// 
    /// @see TerrainArea
    /// @see TerrainAreaIterator
    /// 
    /// @param Min The min point on the terrain
    /// @param Max The max point on the terrain
    /// @returns pointer to the TerrainArea
    virtual const TerrainArea* GetTerrainArea(const Vect& Min, const Vect& Max) const override;

private:
    const TerrainCell& privGetTerrainCell(const float x, const float z);

private:
    TerrainArea* pTerrainArea; ///< Pointer to the terrain area.
    TerrainModel* pTerrainModel; ///< Pointer to the terrain model.
    GraphicsObject_TextureLight* pTerrainGO; ///< Pointer to the graphics object for texture lighting.
    GraphicsObject_Wireframe* pTerrainGOWF; ///< Pointer to the graphics object for wireframe.
    const float length; ///< Length of the terrain.
    float cellwidth; ///< Width of each terrain cell.
};

#endif // MOABETERRAIN_H
