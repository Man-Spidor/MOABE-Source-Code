#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "PerspectiveCamera.h"
#include "OrthographicCamera.h"

/// The CameraManager class manages cameras in the game.
///
/// It provides functionality to initialize, set up, and switch between different cameras,
/// including perspective and orthographic cameras. This class is responsible for managing
/// the main 3D camera and the 2D camera used for rendering sprites and UI elements.
/// 
/// @note This class is for internal use only.
class CameraManager
{
public:
    /// Default constructor.
    CameraManager();

    /// Copy constructor.
    CameraManager(const CameraManager& other) = default;

    /// Copy assignment operator.
    CameraManager& operator=(const CameraManager& other) = default;

    /// Move constructor.
    CameraManager(CameraManager&& other) = default;

    /// Move assignment operator.
    CameraManager& operator=(CameraManager&& other) = default;

    /// Destructor.
    ~CameraManager();

    /// Initializes a default perspective camera.
    void InitializePersp(PerspectiveCamera* pCamera);

    /// Initializes a perspective camera with specified parameters.
    ///
    /// @param FieldOfView_Degs The field of view in degrees.
    /// @param AspectRatio The aspect ratio of the viewport.
    /// @param NearDist The near clipping plane distance.
    /// @param FarDist The far clipping plane distance.
    void InitializePersp(PerspectiveCamera* pCamera, const float FieldOfView_Degs, const float AspectRatio,
                         const float NearDist, const float FarDist);

    /// Initializes an orthographic camera.
    void InitializeOrtho(OrthographicCamera* pCamera);

    /// Initializes an orthographic camera.
    void InitializeOrtho(OrthographicCamera* pCamera, const float minX, const float maxX,
                         const float minY, const float maxY,
                         const float NearDist, const float FarDist);

    /// Retrieves the main 3D camera.
    ///
    /// @return Reference to the main 3D camera.
    Camera& GetMainCamera() const;

    /// Retrieves the 2D camera.
    ///
    /// @return Reference to the 2D camera.
    Camera& Get2DCamera() const;

    /// Sets the current camera to the specified camera.
    ///
    /// @param pCam Pointer to the camera to set as current.
    void SetCurrCamera3D(Camera*& pCam);
    void SetCurrCamera2D(Camera*& pCam);

    /// Sets the position and orientation of the current camera.
    ///
    /// @param upVector Up vector of the camera.
    /// @param pos3DCam Position of the camera.
    /// @param lookAt3DCam Look-at point of the camera.
    void SetCurrCameraPos(Vect upVector, Vect pos3DCam, Vect lookAt3DCam);

    /// Sets the default camera as the current camera.
    void SetDefaultCameraAsCurr();

    /// Updates the current camera.
    void UpdateCurrCamera();

private:
    /// Sets up a perspective camera with specified parameters.
    ///
    /// @param camera Reference to the default camera.
    /// @param inX The x-coordinate of the viewport.
    /// @param inY The y-coordinate of the viewport.
    /// @param width The width of the viewport.
    /// @param height The height of the viewport.
    /// @param FieldOfView_Degs The field of view in degrees.
    /// @param AspectRatio The aspect ratio of the viewport.
    /// @param NearDist The near clipping plane distance.
    /// @param FarDist The far clipping plane distance.
    void privSetUpPerspCamera(PerspectiveCamera& camera,
                                const float FieldOfView_Degs, const float AspectRatio,
                                const float NearDist, const float FarDist);

    /// Sets up an orthographic camera with specified parameters.
    ///
    /// @param camera Reference to the default camera.
    /// @param inX The x-coordinate of the viewport.
    /// @param inY The y-coordinate of the viewport.
    /// @param width The width of the viewport.
    /// @param height The height of the viewport.
    /// @param FieldOfView_Degs The field of view in degrees.
    /// @param AspectRatio The aspect ratio of the viewport.
    /// @param NearDist The near clipping plane distance.
    /// @param FarDist The far clipping plane distance.
    void privSetUpOrthoCamera(OrthographicCamera& camera,
                                const float minX, const float maxX,
                                const float minY, const float maxY,
                                const float NearDist, const float FarDist);

private:
    PerspectiveCamera default3DCamera; ///< Default camera used for initialization.
    OrthographicCamera default2DCamera;
    Camera* pCurr3DCamera; ///< Pointer to the current 3D camera.
    Camera* pCurr2DCamera; ///< Pointer to the current 2D camera.
};

#endif // CAMERAMANAGER_H
