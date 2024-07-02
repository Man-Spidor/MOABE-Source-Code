#include "ModelManager.h"

#include "FlatPlane.h"
#include <Model.h>

ModelManager* ModelManager::instance = nullptr;

ModelManager::ModelManager() :
	DefaultPath("../Assets/Models/"),
	savedModels()
{
	this->privLoad("UnitSquare", Model::UnitSquareXY);
	this->privLoad("UnitBox", Model::UnitBox);
	this->privLoad("BSphere", Model::UnitSphere);
}

void ModelManager::SetDefaultPath(const char* const NewPath)
{
	Instance().DefaultPath = NewPath;
}

void ModelManager::Load(const char * const key, const char * const path)
{
	Instance().privLoad(key, path);
}

void ModelManager::Load(const char* const key, Model::PreMadeModels pmm)
{
	Instance().privLoad(key, pmm);
}

void ModelManager::Load(const char* const key, float planeSize, float u, float v)
{
	Instance().privLoad(key, planeSize, u, v);
}

Model* ModelManager::Get(const char * const key) 
{
	auto search = Instance().savedModels.begin();

	while(search != Instance().savedModels.end()) {
		if (strcmp(key, search->first) == 0) {
			return search->second;
		}
		search++;
	}
	
	if (search == Instance().savedModels.end()) {
		Trace::out("\n------->  [ModelManager] Key: '%s' Not Found  <-------\n\n", key);
		assert(false);
	}

	return nullptr;
}

void ModelManager::Unload()
{
	for (auto MapPair : Instance().savedModels) {
		delete MapPair.second;
	}
	delete instance;
}

void ModelManager::privLoad(const char* const key, const char* const path)
{
	size_t combinedPathSize = strlen(this->DefaultPath.c_str()) + strlen(path) + 1;

	char* combinedPath = new char[combinedPathSize];

	// Copy defaultPath to combinedPath
	strcpy_s(combinedPath, combinedPathSize, this->DefaultPath.c_str());

	// Concatenate path to combinedPath
	strcat_s(combinedPath, combinedPathSize, path);

	assert(combinedPath);

	Model* newModel = new Model(combinedPath);
	this->savedModels[key] = newModel;

	// Remember to free the allocated memory when done
	delete[] combinedPath;
}

void ModelManager::privLoad(const char* const key, Model::PreMadeModels pmm)
{
	this->savedModels[key] = new Model(pmm);
}

void ModelManager::privLoad(const char* const key, float planeSize, float u, float v)
{
	this->savedModels[key] = new FlatPlane(planeSize, u, v);
}

ModelManager& ModelManager::Instance()
{
	if (!instance)
		instance = new ModelManager();
	return *instance;
}

