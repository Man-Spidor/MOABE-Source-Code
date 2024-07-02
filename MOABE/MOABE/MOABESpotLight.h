#ifndef MOABESPOTLIGHT_H
#define MOABESPOTLIGHT_H

#include "MOABELight.h"
#include <SpotLight.h>
#include <LightNum.h>

class SpotRegCmd;
class SpotDeRegCmd;

/// @brief Represents a spotlight in the MOABE engine.
///
/// This class provides functionality for managing a spotlight, including registration, 
/// behavior, and light properties.
class MOABESpotLight : public MOABELight
{
public:
    /// @brief Default constructor.
    MOABESpotLight();

    /// @brief Default copy constructor.
    /// @param other The other MOABESpotLight to copy from.
    MOABESpotLight(const MOABESpotLight& other) = default;

    /// @brief Default copy assignment operator.
    /// @param other The other MOABESpotLight to copy from.
    /// @return A reference to this MOABESpotLight.
    MOABESpotLight& operator=(const MOABESpotLight& other) = default;

    /// @brief Default move constructor.
    /// @param other The other MOABESpotLight to move from.
    MOABESpotLight(MOABESpotLight&& other) = default;

    /// @brief Default move assignment operator.
    /// @param other The other MOABESpotLight to move from.
    /// @return A reference to this MOABESpotLight.
    MOABESpotLight& operator=(MOABESpotLight&& other) = default;

    /// @brief Destructor.
    ~MOABESpotLight();

    /// @brief Constructs a spotlight with a behavior.
    /// @param _pBehaviour Pointer to the light behavior command.
    MOABESpotLight(LightBehaviourCommand* _pBehaviour);

    /// @brief Constructs a spotlight with a specified color.
    /// @param Color The color vector.
    MOABESpotLight(const Vect& Color);

    /// @brief Constructs a spotlight with specified properties.
    /// @param Position The position vector.
    /// @param Direction The direction vector.
    /// @param Attenuation The attenuation vector (default is Vect(0.0f, 0.2f, 0.0f)).
    /// @param SpotExponent The spotlight exponent (default is 12.0f).
    /// @param Range The range of the light (default is 50.0f).
    MOABESpotLight(const Vect& Position, const Vect& Direction, const Vect& Attenuation = Vect(0.0f, 0.2f, 0.0f), const float SpotExponent = 12.0f, const float Range = 50.0f);

    /// @brief Constructs a spotlight with specified properties.
    /// @param Position The position vector.
    /// @param Direction The direction vector.
    /// @param Ambient The ambient color.
    /// @param Diffuse The diffuse color.
    /// @param Specular The specular color.
    MOABESpotLight(const Vect& Position, const Vect& Direction, const Vect& Ambient, const Vect& Diffuse, const Vect& Specular);

    /// @brief Retrieves the spotlight properties.
    /// @return Reference to the spotlight.
    const SpotLight& GetLight() const;

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

    /// @brief Sets the range of the light.
    /// @param _Range The range of the light.
    void SetRange(const float _Range);

    /// @brief Sets the position of the light.
    /// @param Position The position vector.
    void SetPosition(const Vect& Position);

    /// @brief Sets the direction of the light.
    /// @param Direction The direction vector.
    void SetDirection(const Vect& Direction);

    /// @brief Sets the look-at target position for the light.
    /// @param TargetPos The target position vector.
    void SetLookAtTarget(const Vect& TargetPos);

    /// @brief Gets the position of the light.
    /// @return The position vector.
    const Vect& GetPosition() const;

    /// @brief Gets the direction of the light.
    /// @return The direction vector.
    const Vect& GetDirection() const;

    /// @brief Sets the parameters of the spotlight.
    /// @param Position The position vector.
    /// @param Attenuation The attenuation vector.
    /// @param Direction The direction vector.
    /// @param SpotExp The spotlight exponent.
    /// @param Range The range of the light.
    void SetSpotLightParams(const Vect& Position, const Vect& Attenuation, const Vect& Direction, const float SpotExp, const float Range);

    /// @brief Registers the light.
    virtual void RegisterLight() override;

    /// @brief Deregisters the light.
    virtual void DeregisterLight() override;

    /// @brief Turns on the light.
    virtual void TurnOn() override;

    /// @brief Turns off the light.
    virtual void TurnOff() override;

    /// @brief Translates the light left or right.
    /// @param delta The distance to translate.
    void TranslateLeftRight(float delta);

    /// @brief Translates the light up or down.
    /// @param delta The distance to translate.
    void TranslateUpDown(float delta);

    /// @brief Translates the light forward or backward.
    /// @param delta The distance to translate.
    void TranslateFwdBack(float delta);

    /// @brief Tilts the light up or down.
    /// @param ang The angle to tilt.
    void TiltUpDown(float ang);

    /// @brief Turns the light left or right.
    /// @param ang The angle to turn.
    void TurnLeftRight(float ang);

private:
    SpotLight spotLight; ///< The spotlight properties.

    SpotRegCmd* pRegCmd; ///< Pointer to the registration command.
    SpotDeRegCmd* pDeRegCmd; ///< Pointer to the deregistration command.

    float Range; ///< The range of the light.
};

#endif // MOABESPOTLIGHT_H
