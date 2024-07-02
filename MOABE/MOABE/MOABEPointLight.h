#ifndef MOABEPOINTLIGHT_H
#define MOABEPOINTLIGHT_H

#include "MOABELight.h"
#include <PointLight.h>
#include <LightNum.h>

class PointRegCmd;
class PointDeRegCmd;

/// @brief Represents a point light in the MOABE engine.
///
/// This class provides functionality for managing a point light, including registration, 
/// behavior, and light properties.
class MOABEPointLight : public MOABELight
{
public:
    /// @brief Default constructor.
    MOABEPointLight();

    /// @brief Default copy constructor.
    /// @param other The other MOABEPointLight to copy from.
    MOABEPointLight(const MOABEPointLight& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other MOABEPointLight to copy from.
    /// @return A reference to this MOABEPointLight.
    MOABEPointLight& operator=(const MOABEPointLight& other) = default;

    /// @brief Default move constructor.
    /// @param other The other MOABEPointLight to move from.
    MOABEPointLight(MOABEPointLight&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other MOABEPointLight to move from.
    /// @return A reference to this MOABEPointLight.
    MOABEPointLight& operator=(MOABEPointLight&& other) = default;

    /// @brief Destructor.
    ~MOABEPointLight();

    /// @brief Constructs a point light with a behavior.
    /// @param _pBehaviour Pointer to the light behavior command.
    MOABEPointLight(LightBehaviourCommand* _pBehaviour);

    /// @brief Constructs a point light with a specified position and optional attenuation and range.
    /// @param Position The position vector.
    /// @param Attenuation The attenuation vector (default is Vect(0.0f, 0.2f, 0.0f)).
    /// @param Range The range of the light (default is 50.0f).
    MOABEPointLight(const Vect& Position, const Vect& Attenuation = Vect(0.0f, 0.2f, 0.0f), const float Range = 50.0f);

    /// @brief Constructs a point light with specified properties.
    /// @param Position The position vector.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    MOABEPointLight(const Vect& Position, const Vect& Ambient, const Vect& Diffuse, const Vect& Specular);

    /// @brief Retrieves the point light properties.
    /// @return Reference to the point light.
    const PointLight& GetLight() const;

    /// @brief Sets the ambient, diffuse, and specular properties of the light.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    virtual void SetAmbDifSpec(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) override;

    /// @brief Sets the ambient color of the light.
    /// @param Ambient The ambient color.
    virtual void SetAmbient(const Vect& Ambient) override;

    /// @brief Sets the diffuse color of the light.
    /// @param Diffuse The diffuse color.
    virtual void SetDiffuse(const Vect& Diffuse) override;

    /// @brief Sets the specular color of the light.
    /// @param Specular The specular color.
    virtual void SetSpecular(const Vect& Specular) override;

    /// @brief Gets the ambient color of the light.
    /// @return The ambient color vector.
    virtual const Vect& GetAmbient() const override;

    /// @brief Gets the diffuse color of the light.
    /// @return The diffuse color vector.
    virtual const Vect& GetDiffuse() const override;

    /// @brief Gets the specular color of the light.
    /// @return The specular color vector.
    virtual const Vect& GetSpecular() const override;

    /// @brief Dims the light.
    /// @param dimFactor The factor by which to dim the light.
    virtual void DimLight(const float dimFactor) override;

    /// @brief Brightens the light.
    /// @param brightFactor The factor by which to brighten the light.
    virtual void BrightenLight(const float brightFactor) override;

    /// @brief Sets the position of the light.
    /// @param Position The position vector.
    void SetPosition(const Vect& Position);

    /// @brief Sets the range of the light.
    /// @param _Range The range of the light.
    void SetRange(const float _Range);

    /// @brief Gets the position of the light.
    /// @return The position vector.
    const Vect& GetPosition() const;

    /// @brief Sets the parameters of the point light.
    /// @param Position The position vector.
    /// @param Attenuation The attenuation vector.
    /// @param Range The range of the light.
    void SetPointLightParams(const Vect& Position, const Vect& Attenuation, const float Range);

    /// @brief Registers the light.
    virtual void RegisterLight() override;

    /// @brief Deregisters the light.
    virtual void DeregisterLight() override;

    /// @brief Turns on the light.
    virtual void TurnOn() override;

    /// @brief Turns off the light.
    virtual void TurnOff() override;

private:
    PointLight pointLight; ///< The point light properties.

    PointRegCmd* pRegCmd; ///< Pointer to the registration command.
    PointDeRegCmd* pDeRegCmd; ///< Pointer to the deregistration command.

    float Range; ///< The range of the light.
};

#endif // MOABEPOINTLIGHT_H
