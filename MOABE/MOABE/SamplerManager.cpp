#include "SamplerManager.h"

SamplerManager* SamplerManager::instance = nullptr;

SamplerManager::SamplerManager() :
	savedSamplers(),
	defaultSampler(new Sampler())
{
	assert(this->defaultSampler);
}

SamplerManager::~SamplerManager()
{
	while (!this->savedSamplers.empty()) {
		this->savedSamplers.erase(this->savedSamplers.begin());
	}
	delete this->defaultSampler;
}

void SamplerManager::UnLoad()
{
	delete instance;
}

void SamplerManager::Load(const char* Key, const D3D11_SAMPLER_DESC& samplerDesc)
{
	Instance().privLoad(Key, samplerDesc);
}

void SamplerManager::Load(const char* Key, D3D11_FILTER filter, UINT isotropic_level, D3D11_TEXTURE_ADDRESS_MODE address_mode)
{
	Instance().privLoad(Key, filter, isotropic_level, address_mode);
}

Sampler* SamplerManager::Get(const char* Key)
{
	auto search = Instance().savedSamplers.begin();

	while (search != Instance().savedSamplers.end()) {
		if (strcmp(Key, search->first) == 0) {
			return search->second;
		}
		search++;
	}

	if (search == Instance().savedSamplers.end()) {
		Trace::out("\n------->  [SamplerManager] Key: '%s' Not Found  <-------\n\n", Key);
		assert(false);
	}

	return nullptr;
}

Sampler* SamplerManager::GetDefault()
{
	return Instance().defaultSampler;
}

SamplerManager& SamplerManager::Instance()
{
	if(!instance)
		instance = new SamplerManager();
	return *instance;
}

void SamplerManager::privLoad(const char* Key, const D3D11_SAMPLER_DESC& samplerDesc)
{
	Sampler* pSampler = new Sampler(samplerDesc);
	this->savedSamplers[Key] = pSampler;
}

void SamplerManager::privLoad(const char* Key, D3D11_FILTER filter, UINT isotropic_level, D3D11_TEXTURE_ADDRESS_MODE address_mode)
{
	Sampler* pSampler = new Sampler(filter, isotropic_level, address_mode);
	this->savedSamplers[Key] = pSampler;
}
