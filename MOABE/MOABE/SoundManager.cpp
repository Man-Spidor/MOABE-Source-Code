#include "SoundManager.h"
#include "MOABESound.h"
#include <irrKlang.h>

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager() :
    soundEngine(nullptr),
    DefaultPath("../Assets/Sounds/")
{
    soundEngine = irrklang::createIrrKlangDevice();
    if (!soundEngine) {
        Trace::out("-----> Failed to initialize IrrKlang\n");
        assert(false);
    }
}

SoundManager::~SoundManager()
{
    for (auto& pair : soundSources) {
        soundEngine->removeSoundSource(pair.second);
    }
    soundEngine->drop();
}

void SoundManager::SetDefaultPath(const char* const NewPath)
{
    Instance().DefaultPath = NewPath;
}

void SoundManager::Load(const char* const key, const char* const path)
{
    Instance().privLoad(key, path);
}

irrklang::ISoundSource* SoundManager::Get(const char* const key)
{
    auto& instance = Instance();
    auto it = instance.soundSources.find(key);

    if (it == instance.soundSources.end()) {
        Trace::out("-----> Sound Source [%s] Could not be found!!\n", key);
        assert(false);
    }

    return it->second;
}

void SoundManager::Play(MOABESound* pSound, bool loop)
{
    auto& instance = Instance();
    if (pSound->currentSound) {
        pSound->currentSound->stop();
        pSound->currentSound->drop();
    }
    pSound->currentSound = instance.soundEngine->play2D(pSound->soundSource, loop, false, true);
    if (pSound->currentSound) {
        pSound->currentSound->grab();
    }
}

void SoundManager::Unload()
{
    delete instance;
}

void SoundManager::privLoad(const char* const key, const char* const path)
{
    std::string fullPath = DefaultPath + path;
    irrklang::ISoundSource* soundSource = soundEngine->addSoundSourceFromFile(fullPath.c_str());
    if (soundSource) {
        soundSources[key] = soundSource;
    }
    else {
        Trace::out("-----> Sound With Path: [%s] Could Not Be Loaded\n", path);
    }
}

SoundManager& SoundManager::Instance()
{
    if (!instance) {
        instance = new SoundManager();
    }
    return *instance;
}
