#ifndef JAZUL_H
#define JAZUL_H

#include <Vect.h>
#include <d3d11.h>
#include "Camera.h"

///  Manages the DirectX rendering context and camera.
/// 
/// The jAzul class is the Graphics Engine behind all of the jAzul Graphics API. It manages everything graphics/DirectX related
/// 
/// This class provides functionality to initialize DirectX, manage rendering frames, and handle camera settings.
/// Most of the functionality of this class however, is hidden away behind the Engine class. 
/// 
/// @see Engine
class jAzul
{
public:
    jAzul(); ///< Default constructor.
    jAzul(const jAzul& other) = default; ///< Copy constructor.
    jAzul& operator=(const jAzul& other) = default; ///< Copy assignment operator.
    jAzul(jAzul&& other) = default; ///< Move constructor.
    jAzul& operator=(jAzul&& other) = default; ///< Move assignment operator.
    ~jAzul(); ///< Destructor.

    /// Initialize the DirectX rendering context.
    /// @param hwnd Handle to the window.
    /// @param width Width of the rendering context.
    /// @param height Height of the rendering context.
    /// @return True if initialization is successful, false otherwise.
    bool Initialize(HWND hwnd, int width, int height);

    /// Render a frame.
    void RenderFrame();

    /// Set the current camera.
    /// @param cam Pointer to the camera.
    void SetCurrCam(Camera* cam);

    /// Set the current 2D camera.
    /// @param cam Pointer to the 2D camera.
    void SetCurrCam2D(Camera* cam);

    /// Set the width of the rendering context.
    /// @param width The width.
    void SetWidth(const int width);

    /// Set the height of the rendering context.
    /// @param height The height.
    void SetHeight(const int height);

    /// Get the width of the rendering context.
    /// @return The width.
    const int GetWidth() const;

    /// Get the height of the rendering context.
    /// @return The height.
    const int GetHeight() const;

    /// Set the background color of the rendering context.
    /// @param R Red component.
    /// @param G Green component.
    /// @param B Blue component.
    /// @param A Alpha component.
    void SetBackgroundColor(const float R, const float G, const float B, const float A);

    /// Set the background color of the rendering context.
    /// @param color The color vector.
    void SetBackgroundColor(const Vect& color);

    /// Enable asynchronous rendering.
    void EnableASync();

    /// Disable asynchronous rendering.
    void DisableASync();

private:
    /// Enable depth testing.
    void EnableDepthTest();

    /// Disable depth testing.
    void DisableDepthTest();

    /// Enable solid rasterization.
    void EnableSolid();

    /// Enable wireframe rasterization.
    void EnableWireFrame();

    /// Initialize DirectX.
    /// @param hwnd Handle to the window.
    /// @param width Width of the rendering context.
    /// @param height Height of the rendering context.
    /// @return True if initialization is successful, false otherwise.
    bool InitializeDirectX(HWND hwnd, int width, int height);

    /// Report live DirectX objects.
    void ReportLiveDXObjects();

private:
    Vect BackgroundColor; ///< Background color.

    // DX application elements
    ID3D11Device* md3dDevice; ///< Pointer to the DirectX device.
    ID3D11DeviceContext* md3dImmediateContext; ///< Pointer to the DirectX device context.
    IDXGISwapChain* mSwapChain; ///< Pointer to the swap chain.
    ID3D11RenderTargetView* mRenderTargetView; ///< Pointer to the render target view.
    ID3D11DepthStencilView* mpDepthStencilView; ///< Pointer to the depth stencil view.

    ID3D11RasterizerState* mSolidRasterizerState; ///< Solid rasterizer state.
    ID3D11RasterizerState* mWireFrameRasterizerState; ///< Wireframe rasterizer state.

    Camera* currCam; ///< Pointer to the current camera.
    Camera* currCam2D; ///< Pointer to the current 2D camera.

    int width; ///< Width of the rendering context.
    int height; ///< Height of the rendering context.

    int SyncInterval; ///< Synchronization interval.
};

#endif // JAZUL_H
