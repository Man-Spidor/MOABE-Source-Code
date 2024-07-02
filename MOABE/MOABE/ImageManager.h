#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <map>

struct jAzulRect;

class Image;
class Texture;

/// @class ImageManager
/// @brief Manages the loading, retrieval, and unloading of images.
/// 
/// This singleton class provides functionality to load images from textures and rectangles,
/// retrieve loaded images by key, and unload all images.
class ImageManager
{
private:
    /// @brief Private constructor to enforce singleton pattern.
    ImageManager();

    /// @brief Deleted copy constructor.
    /// @param other The other ImageManager to copy from.
    ImageManager(const ImageManager& other) = delete;

    /// @brief Deleted copy assignment operator.
    /// @param other The other ImageManager to copy from.
    /// @return A reference to this ImageManager.
    ImageManager& operator=(const ImageManager& other) = delete;

    /// @brief Deleted move constructor.
    /// @param other The other ImageManager to move from.
    ImageManager(ImageManager&& other) = delete;

    /// @brief Deleted move assignment operator.
    /// @param other The other ImageManager to move from.
    /// @return A reference to this ImageManager.
    ImageManager& operator=(ImageManager&& other) = delete;

    /// @brief Destructor.
    ~ImageManager();

public:
    /// @brief Load an image from a texture key and rectangle.
    /// 
    /// This function loads an image using a texture key and a rectangle defining the image area.
    /// The loaded image is associated with the specified key.
    /// 
    /// @param key The key to identify the image.
    /// @param textureKey The key to the texture.
    /// @param pjAzulRect Pointer to the rectangle defining the image area.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void LoadImages() {
    ///     jAzulRect rect(0, 0, 100, 100);
    ///     ImageManager::Load("exampleImage", "exampleTexture", &rect);
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static void Load(const char* const key, const char* const textureKey, jAzulRect* pjAzulRect);

    /// @brief Load an image from a texture and rectangle.
    /// 
    /// This function loads an image using a texture pointer and a rectangle defining the image area.
    /// The loaded image is associated with the specified key.
    /// 
    /// @param key The key to identify the image.
    /// @param pText Pointer to the texture.
    /// @param pjAzulRect Pointer to the rectangle defining the image area.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void LoadImages() {
    ///     Texture* texture = new Texture(L"exampleTexture.png");
    ///     jAzulRect rect(0, 0, 100, 100);
    ///     ImageManager::Load("exampleImage", texture, &rect);
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static void Load(const char* const key, Texture* pText, jAzulRect* pjAzulRect);

    /// @brief Retrieve an image associated with a key.
    /// 
    /// This function retrieves the image associated with the specified key.
    /// 
    /// @param key The key identifying the image.
    /// @return Pointer to the image, or nullptr if not found.
    /// 
    /// ### Example:
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
    /// void SomeFunc() {
    ///     Image* img = ImageManager::Get("exampleImage");
    ///     if (img != nullptr) {
    ///         // Use the image
    ///     }
    /// }
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static Image* Get(const char* const key);

    /// @brief Unload all loaded images.
    /// 
    /// This function unloads all images currently loaded by the ImageManager.
    static void Unload();

private:
    /// @brief Load an image from a texture key and rectangle (private implementation).
    /// 
    /// @param key The key to identify the image.
    /// @param path The path to the texture.
    /// @param pjAzulRect Pointer to the rectangle defining the image area.
    void privLoad(const char* const key, const char* const path, jAzulRect* pjAzulRect);

    /// @brief Load an image from a texture and rectangle (private implementation).
    /// 
    /// @param key The key to identify the image.
    /// @param pText Pointer to the texture.
    /// @param pjAzulRect Pointer to the rectangle defining the image area.
    void privLoad(const char* const key, Texture* pText, jAzulRect* pjAzulRect);

    /// @brief Get the singleton instance of the ImageManager.
    /// 
    /// @return Reference to the ImageManager instance.
    static ImageManager& Instance();

    static ImageManager* instance; ///< Singleton instance of the ImageManager.

    using ImageMap = std::map<const char* const, Image*>;
    ImageMap savedImages; ///< Map of saved images.
};

#endif // IMAGEMANAGER_H
