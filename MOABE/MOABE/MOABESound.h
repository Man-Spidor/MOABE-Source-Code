#ifndef MOABESOUND_H
#define MOABESOUND_H

#include <ik_ISound.h>

/// Represents a sound effect in the MOABE engine.
class MOABESound
{
    friend class SoundManager;
public:
    /// Default Constructor (deleted)
    MOABESound() = delete;
    /// Copy Constructor
    MOABESound(const MOABESound& other);
    /// Copy Assignment Operator
    MOABESound& operator=(const MOABESound& other);
    /// Move Constructor
    MOABESound(MOABESound&& other) = default;
    /// Move Assignment Operator
    MOABESound& operator=(MOABESound&& other) = default;
    /// Destructor
    ~MOABESound();

    /// Constructor that initializes the sound with an ISoundSource.
    /// 
    /// @param _soundSource The sound source
    MOABESound(irrklang::ISoundSource* _soundSource);

    /// Plays the sound.
    /// 
    /// @param loop Whether the sound should loop
    void Play(bool loop = false);

    /// Stops the sound if it is currently playing.
    void Stop();

    /// Sets the volume of the sound.
    /// 
    /// @param volume The volume level (0.0f to 1.0f)
    void SetVolume(float volume);

    /// Checks if the sound is currently playing.
    /// 
    /// @return True if the sound is playing, false otherwise
    bool IsPlaying() const;

private:
    irrklang::ISoundSource* soundSource; ///< The sound source
    irrklang::ISound* currentSound; ///< The current playing sound instance

    void AddRef();
    void Release();
};

#endif // MOABESOUND_H
