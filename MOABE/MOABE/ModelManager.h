#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <Model.h>

/// The ModelManager class manages loading, retrieval, and unloading of models.
/// 
/// This singleton class provides functionality to load models from files, pre-made models, 
/// or plane models. Loaded models can be retrieved by their unique keys, and all 
/// loaded models can be unloaded when necessary.
/// 
/// Example usage of the ModelManager class:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// void MOABE::LoadAllContent() { 
///     ModelManager::Load("model1", "path/to/model1.azul");
///     ModelManager::Load("plane", 10, 10, 1); // Load a plane model
///     ModelManager::Load("cube", Model::CUBE);
///     
/// }
/// 
/// // ...
/// 
/// SomeGameObject() {
///     this->pModel = ModelManager::Get("model1");
/// }
/// 
/// // ...
/// 
/// MOABE::UnloadContent() {
///     ModelManager::Unload();
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// @warning This engine uses jAzul as its graphics engine, as such all models 
/// must be in the .azul format
class ModelManager
{
private:
    ModelManager();
    ModelManager(const ModelManager& other) = delete;
    ModelManager& operator=(const ModelManager& other) = delete;
    ModelManager(ModelManager&& other) = delete;
    ModelManager& operator=(ModelManager&& other) = delete;
    ~ModelManager() = default;

public:
    /// Allows users to change the default path when loading models
    /// 
    /// @param NewPath The new default path
    static void SetDefaultPath(const char* const NewPath);

    /// Load a model from a file.
    ///  
    /// @param key The unique key to identify the model.
    /// @param path The file path of the model.
    /// @note Path Directory Automatically defaults to Assets/Models/xyz.azul
    static void Load(const char* const key, const char* const path);

    /// Loads a pre-made model and associates it with the given key.
    ///
    /// List of Premade Models:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// 
    /// enum PreMadeModels {
    ///     UnitSquareXY,   
    ///     UnitBox_WF,
    ///     UnitSphere,
    ///     UnitEgg,
    ///     TGO
    /// };
    ///
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /// 
    /// @param key The unique identifier for the loaded model.
    /// @param pmm The type of pre-made model to load.
    static void Load(const char* const key, Model::PreMadeModels pmm);

    /// Loads a plane model with the specified dimensions and associates it with the given key.
    ///
    /// @param key The unique identifier for the loaded model.
    /// @param planeSize The size of the plane.
    /// @param u The number of divisions along the U axis.
    /// @param v The number of divisions along the V axis.
    static void Load(const char* const key, float planeSize, float u, float v);

    /// Retrieves a pointer to the model associated with the given key.
    ///
    /// @param key The unique identifier for the desired model.
    /// @return A pointer to the requested model, or nullptr if not found.
    static Model* Get(const char* const key);

    /// Unloads all loaded models.
    static void Unload();

private:
    /// Helper function to load a model from a file path.
    void privLoad(const char* const key, const char* const path);

    /// Helper function to load a pre-made model.
    void privLoad(const char* const key, Model::PreMadeModels pmm);

    /// Helper function to load a plane model.
    void privLoad(const char* const key, float planeSize, float u, float v);

    /// Returns a reference to the singleton instance of the ModelManager.
    static ModelManager& Instance();

    /// Pointer to the singleton instance of the ModelManager.
    static ModelManager* instance;

    /// Default file path for loading models.
    std::string DefaultPath;

    /// Map to store the loaded models with their respective keys.
    using ModelMap = std::map<const char* const, Model*>;
    ModelMap savedModels;
};

#endif // MODELMANAGER_H
