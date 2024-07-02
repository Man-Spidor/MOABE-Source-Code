#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <map>
#include <ik_ISoundEngine.h>

class MOABESound;

/// The SoundManager class manages the loading and playback of sound objects.
/// 
/// This singleton class provides functionality to load sounds from files and retrieve them using unique keys.
/// It also allows unloading sound objects from memory when they are no longer needed.
class SoundManager
{
private:
    SoundManager();
    SoundManager(const SoundManager& other) = delete;
    SoundManager& operator=(const SoundManager& other) = delete;
    SoundManager(SoundManager&& other) = delete;
    SoundManager& operator=(SoundManager&& other) = delete;
    ~SoundManager();

public:
    /// Allows users to change the default path when loading sounds
    /// 
    /// @param NewPath The new default path
    static void SetDefaultPath(const char* const NewPath);

    /// Loads a sound object from the specified file path and associates it with the given key.
    /// 
    /// @param key The unique identifier for the sound object.
    /// @param path The file path to the sound file.
    static void Load(const char* const key, const char* const path);

    /// Retrieves the sound object associated with the specified key.
    /// 
    /// @param key The unique identifier for the sound object.
    /// @return The sound source associated with the key.
    static irrklang::ISoundSource* Get(const char* const key);

    /// Plays the given sound.
    /// 
    /// @param pSound The sound to be played.
    /// @param loop Whether the sound should loop.
    static void Play(MOABESound* pSound, bool loop);

    /// Unloads all sound objects from memory.
    /// 
    /// This function releases all sound objects loaded into memory by the SoundManager.
    static void Unload();

private:
    /// Private function to load a sound object from the specified file path.
    /// 
    /// @param key The unique identifier for the sound object.
    /// @param path The file path to the sound file.
    void privLoad(const char* const key, const char* const path);

private:
    static SoundManager* instance; ///< Singleton instance of the SoundManager.
    /// Returns a reference to the singleton instance of the SoundManager.
    static SoundManager& Instance();

    irrklang::ISoundEngine* soundEngine; ///< The IrrKlang sound engine.
    using SoundMap = std::map<std::string, irrklang::ISoundSource*>;
    SoundMap soundSources; ///< Map of keys to loaded sound sources.
    
    std::string DefaultPath; ///< Default path for loading sounds.
};

#endif // SOUNDMANAGER_H
