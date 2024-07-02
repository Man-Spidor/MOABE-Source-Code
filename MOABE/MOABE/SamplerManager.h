#ifndef SAMPLERMANAGER_H
#define SAMPLERMANAGER_H

#include <map>
#include <Sampler.h>

/// @class SamplerManager
/// Manages the loading, retrieval, and unloading of samplers.
/// 
/// This singleton class provides functionality to load samplers with specific settings
/// or from a D3D11 sampler description. Loaded samplers can be retrieved by their unique keys,
/// and all loaded samplers can be unloaded when necessary.
/// 
/// Example usage of the SamplerManager class:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// void MOABE::LoadAllContent() {
///     // Load samplers with various settings
///     SamplerManager::Load("LinearSampler", D3D11_FILTER_MIN_MAG_MIP_LINEAR, 0, D3D11_TEXTURE_ADDRESS_WRAP);
///     SamplerManager::Load("AnisotropicSampler", anisotropicDesc);
///     
///     // ...
///     
///     TextureManager::Load("LeavesTex", SamplerManager::Get("LinearSampler", "leaves_tex.tga");
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class SamplerManager
{
public:
    /// Default constructor.
    SamplerManager();
    SamplerManager(const SamplerManager& other) = default;
    SamplerManager& operator=(const SamplerManager& other) = default;
    SamplerManager(SamplerManager&& other) = default;
    SamplerManager& operator=(SamplerManager&& other) = default;
    ~SamplerManager();

    /// Unload all loaded samplers.
    static void UnLoad();

    /// Load a sampler with the specified D3D11 sampler description.
    /// 
    /// @param Key The unique key to identify the sampler.
    /// @param samplerDesc The D3D11 sampler description.
    static void Load(const char* Key, const D3D11_SAMPLER_DESC& samplerDesc);

    /// Load a sampler with specified filter, anisotropic level, and address mode.
    /// 
    /// @param Key The unique key to identify the sampler.
    /// @param filter The filter mode for the sampler.
    /// @param isotropic_level The anisotropic level.
    /// @param address_mode The address mode.
    static void Load(const char* Key, D3D11_FILTER filter, UINT isotropic_level, D3D11_TEXTURE_ADDRESS_MODE address_mode);

    /// Retrieve a sampler associated with the given key.
    /// 
    /// @param Key The key associated with the desired sampler.
    /// @return A pointer to the Sampler associated with the key.
    static Sampler* Get(const char* Key);

    /// Retrieve the default sampler.
    /// 
    /// @return A pointer to the default Sampler.
    static Sampler* GetDefault();

private:
    /// Load a sampler with the specified D3D11 sampler description (private implementation).
    /// 
    /// @param Key The unique key to identify the sampler.
    /// @param samplerDesc The D3D11 sampler description.
    void privLoad(const char* Key, const D3D11_SAMPLER_DESC& samplerDesc);

    /// Load a sampler with specified filter, anisotropic level, and address mode (private implementation).
    /// 
    /// @param Key The unique key to identify the sampler.
    /// @param filter The filter mode for the sampler.
    /// @param isotropic_level The anisotropic level.
    /// @param address_mode The address mode.
    void privLoad(const char* Key, D3D11_FILTER filter, UINT isototropic_level, D3D11_TEXTURE_ADDRESS_MODE address_mode);

    /// Retrieve the singleton instance of the SamplerManager.
    /// 
    /// @return A reference to the singleton instance.
    static SamplerManager& Instance();

private:
    static SamplerManager* instance; ///< Singleton instance of the SamplerManager.
    using SamplerMap = std::map<const char* const, Sampler*>;
    SamplerMap savedSamplers; ///< Map of keys to loaded samplers.

    Sampler* defaultSampler; ///< Pointer to the default sampler.
};

#endif // SAMPLERMANAGER_H
