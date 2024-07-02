#include "MOABESound.h"
#include "SoundManager.h"

MOABESound::MOABESound(irrklang::ISoundSource* _soundSource) :
    soundSource(_soundSource),
    currentSound(nullptr)
{
    AddRef();
}

MOABESound::MOABESound(const MOABESound& other) :
    soundSource(other.soundSource),
    currentSound(nullptr)
{
    AddRef();
}

MOABESound& MOABESound::operator=(const MOABESound& other)
{
    if (this != &other) {
        Release();
        soundSource = other.soundSource;
        currentSound = nullptr;
        AddRef();
    }
    return *this;
}

MOABESound::~MOABESound()
{
    Stop();
    Release();
}

void MOABESound::Play(bool loop)
{
    Stop();
    SoundManager::Play(this, loop);
}

void MOABESound::Stop()
{
    if (currentSound) {
        currentSound->stop();
        currentSound->drop();
        currentSound = nullptr;
    }
}

void MOABESound::SetVolume(float volume)
{
    if (currentSound) {
        currentSound->setVolume(volume);
    }
}

bool MOABESound::IsPlaying() const
{
    return currentSound && !currentSound->isFinished();
}

void MOABESound::AddRef()
{
    if (soundSource) {
        soundSource->grab();
    }
}

void MOABESound::Release()
{
    if (soundSource) {
        soundSource->drop();
    }
}
