#ifndef MOABELIGHT_H
#define MOABELIGHT_H

#include "RegistrationStatus.h"
#include <Vect.h>
#include <LightNum.h>

class LightBehaviourCommand;

/// @brief Abstract base class for lights in the MOABE engine.
///
/// This class provides the basic functionality for all types of lights, including registration, 
/// behavior, and color settings.
/// 
/// @see MOABEDirectionalLight
/// @see MOABEPointLight
/// @see MOABESpotLight
/// @see LightManager
/// 
/// @see LightBehaviour
class MOABELight
{
    friend class LightAttorney;

public:
    /// @brief Default constructor.
    MOABELight();

    /// @brief Default copy constructor.
    /// @param other The other MOABELight to copy from.
    MOABELight(const MOABELight& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other MOABELight to copy from.
    /// @return A reference to this MOABELight.
    MOABELight& operator=(const MOABELight& other) = default;

    /// @brief Default move constructor.
    /// @param other The other MOABELight to move from.
    MOABELight(MOABELight&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other MOABELight to move from.
    /// @return A reference to this MOABELight.
    MOABELight& operator=(MOABELight&& other) = default;

    /// @brief Destructor.
    virtual ~MOABELight();

    /// @brief Registers the light.
    virtual void RegisterLight() = 0;

    /// @brief Deregisters the light.
    virtual void DeregisterLight() = 0;

    /// @brief Turns on the light.
    virtual void TurnOn() = 0;

    /// @brief Turns off the light.
    virtual void TurnOff() = 0;

    /// @brief Sets the light behavior to static.
    void SetBehaviourStatic();

    /// @brief Sets the light behavior.
    /// @param _pBehaviour Pointer to the light behavior command.
    void SetBehaviour(LightBehaviourCommand* _pBehaviour);

    /// @brief Sets the color of the light.
    /// 
    /// Sets the Ambient to Color
    /// Sets the Diffuse to 0.5f * Color
    /// Sets the Specular to 0.1f * Color
    /// 
    /// @param Color The color vector.
    void SetColor(const Vect& Color);

    /// @brief Sets the ambient, diffuse, and specular properties of the light.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    virtual void SetAmbDifSpec(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular) = 0;

    /// @brief Sets the ambient color of the light.
    /// @param Ambient The ambient color.
    virtual void SetAmbient(const Vect& Ambient) = 0;

    /// @brief Sets the diffuse color of the light.
    /// @param Diffuse The diffuse color.
    virtual void SetDiffuse(const Vect& Diffuse) = 0;

    /// @brief Sets the specular color of the light.
    /// @param Specular The specular color.
    virtual void SetSpecular(const Vect& Specular) = 0;

    /// @brief Gets the current behavior of the light.
    /// @return Reference to the light behavior command.
    LightBehaviourCommand& GetBehaviour() const;

    /// @brief Gets the ambient color of the light.
    /// @return The ambient color vector.
    virtual const Vect& GetAmbient() const = 0;

    /// @brief Gets the diffuse color of the light.
    /// @return The diffuse color vector.
    virtual const Vect& GetDiffuse() const = 0;

    /// @brief Gets the specular color of the light.
    /// @return The specular color vector.
    virtual const Vect& GetSpecular() const = 0;

    /// @brief Dims the light.
    /// @param dimFactor The factor by which to dim the light.
    virtual void DimLight(const float dimFactor) = 0;

    /// @brief Brightens the light.
    /// @param brightFactor The factor by which to brighten the light.
    virtual void BrightenLight(const float brightFactor) = 0;

private:
    /// @brief Updates the light properties.
    void UpdateLight() const;

    /// @brief Sets the registration status to registered.
    void SetRegStatusRegistered();

    /// @brief Sets the registration status to deregistered.
    void SetRegStatusDeregistered();

private:
    LIGHTNUM lightID; ///< The light number.

protected:
    RegistrationStatus regStatus; ///< The registration status.
    LightBehaviourCommand* pBehaviour; ///< Pointer to the light behavior command.
};

#endif // MOABELIGHT_H
