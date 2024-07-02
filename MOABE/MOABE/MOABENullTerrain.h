#ifndef MOABENULLTERRAIN_H
#define MOABENULLTERRAIN_H

#include "TerrainObject.h"

/// Represents a null terrain object.
/// 
/// This class provides a null implementation of a terrain object with no functionality.
class MOABENullTerrain : public TerrainObject
{
public:
    MOABENullTerrain() = default;
    MOABENullTerrain(const MOABENullTerrain& other) = default;
    MOABENullTerrain& operator=(const MOABENullTerrain& other) = default;
    MOABENullTerrain(MOABENullTerrain&& other) = default;
    MOABENullTerrain& operator=(MOABENullTerrain&& other) = default;
    ~MOABENullTerrain() = default;

    virtual void Render() override { }

    virtual void SetWorld(const Matrix World) override { UNREFERENCED_PARAMETER(World); }

    virtual void SetTexture(Texture* pTexture) override { UNREFERENCED_PARAMETER(pTexture); }

    virtual void SetMaterial(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) override { UNREFERENCED_PARAMETER(Ambient); UNREFERENCED_PARAMETER(Diffuse); UNREFERENCED_PARAMETER(Specular); }

    virtual const TerrainModel* GetTerrainModel() const { return nullptr; }

    virtual const TerrainArea* GetTerrainArea(const Vect& Min, const Vect& Max) const override { UNREFERENCED_PARAMETER(Min); UNREFERENCED_PARAMETER(Max); return nullptr; }
};

#endif // MOABENULLTERRAIN_H
