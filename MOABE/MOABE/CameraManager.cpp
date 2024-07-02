#include "CameraManager.h"
#include "MOABE.h"

CameraManager::~CameraManager()
{
}

CameraManager::CameraManager() :
	default3DCamera(),
	default2DCamera(),
	pCurr3DCamera(nullptr),
	pCurr2DCamera(nullptr)
{
	this->pCurr3DCamera = &this->default3DCamera;
	this->pCurr2DCamera = &this->default2DCamera;

	this->InitializePersp(&this->default3DCamera);
	this->InitializeOrtho(&this->default2DCamera);
}

void CameraManager::InitializePersp(PerspectiveCamera* pCamera)
{	
	// Final Perspective Setup
	const float width =	 float(MOABE::GetWidth());
	const float height = float(MOABE::GetHeight());

	this->privSetUpPerspCamera(	*pCamera,
								3.14159f / 5.0f, 
								width/height, 
								1.0f, 5000.0f);

	this->pCurr3DCamera = &this->default3DCamera;
}


void CameraManager::InitializePersp(PerspectiveCamera* pCamera, const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist)
{
	this->privSetUpPerspCamera(	*pCamera, 
									FieldOfView_Degs, 
									AspectRatio, 
									NearDist, FarDist);

	this->pCurr3DCamera = &this->default3DCamera;
}

void CameraManager::InitializeOrtho(OrthographicCamera* pCamera)
{
	this->privSetUpOrthoCamera(	*pCamera, 
								-0.5f * MOABE::GetWidth(), 0.5f * MOABE::GetWidth(), 
								-0.5f * MOABE::GetHeight(), 0.5f * MOABE::GetHeight(), 
								1.0f, 1000.0f);

	MOABE::SetCamera2D(this->pCurr2DCamera);
}

void CameraManager::InitializeOrtho(OrthographicCamera* pCamera, const float minX, const float maxX, const float minY, const float maxY, const float NearDist, const float FarDist)
{
	this->privSetUpOrthoCamera(	*pCamera, 
								minX, maxX, 
								minY, maxY, 
								NearDist, FarDist);

	MOABE::SetCamera2D(this->pCurr2DCamera);
}

Camera& CameraManager::GetMainCamera() const
{
	return *(this->pCurr3DCamera);
}

Camera& CameraManager::Get2DCamera() const
{
	return *this->pCurr2DCamera;
}

void CameraManager::SetCurrCamera3D(Camera*& pCam)
{
	this->pCurr3DCamera = pCam;
	MOABE::SetCamera3D(pCam);
}

void CameraManager::SetCurrCamera2D(Camera*& pCam)
{
	this->pCurr2DCamera = pCam;
	MOABE::SetCamera2D(pCam);
}

void CameraManager::SetCurrCameraPos(Vect upVector, Vect pos3DCam, Vect lookAt3DCam)
{
	this->pCurr3DCamera->setOrientAndPosition(upVector, lookAt3DCam, pos3DCam);
}

void CameraManager::SetDefaultCameraAsCurr()
{
	this->pCurr3DCamera = &this->default3DCamera;
	MOABE::SetCamera3D(this->pCurr3DCamera);
}

void CameraManager::UpdateCurrCamera()
{
	this->pCurr3DCamera->updateCamera();
}

void CameraManager::privSetUpPerspCamera(PerspectiveCamera& camera, const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist)
{
	// Set viewport and perspective using default values
	camera.setPerspective(FieldOfView_Degs, AspectRatio, NearDist, FarDist);

	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	camera.setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	camera.updateCamera();
}

void CameraManager::privSetUpOrthoCamera(OrthographicCamera& camera, const float minX, const float maxX, const float minY, const float maxY, const float NearDist, const float FarDist)
{
	// Set viewport and perspective using default values
	camera.setOrthographic(minX, maxX, minY, maxY, NearDist, FarDist);

	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(0.0f, 0.0f, 5.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	camera.setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	camera.updateCamera();
}
