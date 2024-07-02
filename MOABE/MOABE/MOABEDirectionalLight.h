#ifndef MOABEDIRECTIONALLIGHT_H
#define MOABEDIRECTIONALLIGHT_H

#include "MOABELight.h"
#include <DirectionalLight.h>
#include <LightNum.h>

class DirectionalRegCmd;
class DirectionalDeRegCmd;

/// @brief Represents a directional light in the MOABE engine.
///
/// This class provides functionality for managing a directional light, including registration, 
/// behavior, and light properties.
/// 
/// @see MOABELight
/// @see LightManager
class MOABEDirectionalLight : public MOABELight
{
    static const Vect OFF_VECT;

public:
    /// @brief Default constructor.
    MOABEDirectionalLight();

    /// @brief Default copy constructor.
    /// @param other The other MOABEDirectionalLight to copy from.
    MOABEDirectionalLight(const MOABEDirectionalLight& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other MOABEDirectionalLight to copy from.
    /// @return A reference to this MOABEDirectionalLight.
    MOABEDirectionalLight& operator=(const MOABEDirectionalLight& other) = default;

    /// @brief Default move constructor.
    /// @param other The other MOABEDirectionalLight to move from.
    MOABEDirectionalLight(MOABEDirectionalLight&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other MOABEDirectionalLight to move from.
    /// @return A reference to this MOABEDirectionalLight.
    MOABEDirectionalLight& operator=(MOABEDirectionalLight&& other) = default;

    /// @brief Destructor.
    ~MOABEDirectionalLight();

    /// @brief Constructs a directional light with a behavior.
    /// @param _pBehaviour Pointer to the light behavior command.
    MOABEDirectionalLight(LightBehaviourCommand* _pBehaviour);

    /// @brief Constructs a directional light with a specified direction.
    /// @param Direction The direction vector.
    MOABEDirectionalLight(const Vect& Direction);

    /// @brief Constructs a directional light with specified properties.
    /// @param Direction The direction vector.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    MOABEDirectionalLight(const Vect& Direction, const Vect& Ambient, const Vect& Diffuse, const Vect& Specular);

    /// @brief Retrieves the directional light properties.
    /// @return Reference to the directional light.
    const DirectionalLight& GetLight() const;

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
    /// 
    /// Multiplies the Ambient Diffuse and Specular by the dimFactor
    /// 
    /// @param dimFactor The factor by which to dim the light.
    virtual void DimLight(const float dimFactor) override;

    /// @brief Brightens the light.
    /// 
    /// Multiplies the Ambient Diffuse and Specular by the brightFactor
    /// 
    /// @param brightFactor The factor by which to brighten the light.
    virtual void BrightenLight(const float brightFactor) override;

    /// @brief Sets the parameters of the directional light.
    /// @param Direction The direction vector.
    void SetDirectionalLightParams(const Vect& Direction);

    /// @brief Registers the light.
    virtual void RegisterLight() override;

    /// @brief Deregisters the light.
    virtual void DeregisterLight() override;

    /// @brief Turns on the light.
    /// 
    /// Sets the direction back to the specified direction
    virtual void TurnOn() override;

    /// @brief Turns off the light.
    /// 
    /// Sets the direction to face away from the ground, effectively turning it off
    virtual void TurnOff() override;

    /// @brief Tilts the light up or down.
    /// @param ang The angle to tilt.
    void TiltUpDown(float ang);

    /// @brief Turns the light left or right.
    /// @param ang The angle to turn.
    void TurnLeftRight(float ang);

private:
    DirectionalLight dirLight; ///< The directional light properties.
    Vect Direction; ///< The direction vector.

    DirectionalRegCmd* pRegCmd; ///< Pointer to the registration command.
    DirectionalDeRegCmd* pDeRegCmd; ///< Pointer to the deregistration command.
};

#endif // MOABEDIRECTIONALLIGHT_H
