#ifndef MOABE_H
#define MOABE_H

#include "MOABEUser.h"

//***********************\\
// WELCOME TO THE MOABE *\\
// 						*\\
//		  MOTHER		*\\
//			OF			*\\
//			ALL			*\\
//		  BROKEN		*\\
//		  ENGINES		*\\
// 						*\\
//***********************\\

/// The MOABE (Mother of All Broken Engines) class, inheriting from the Engine class.
/// 
/// 
///			    WELCOME TO THE MOABE 
///			 			
///					    THE		
/// 	
///					  MOTHER.		
///						OF.			
///						ALL.			
///					  BROKEN.		
///					  ENGINES.		
///			 						
///			
/// 
/// There are 3 functions in this class that must be defined by the USER, those are:
///		
///		GameStart();		Called when MOABE is first being intialized
///							Meant to contain all non-graphics related initialization
/// 
/// Example GameStart definition
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// void MOABE::GameStart()
/// {
/// 	// Game Window Device setup
/// 	MOABE::SetWindowName("Matrices and Movement");
/// 	MOABE::SetColor(0.4f, 0.4f, 0.8f, 1.0f);
/// 
/// 	RECT rc;
/// 	GetWindowRect(GetDesktopWindow(), &rc);
/// 	MOABE::SetWidthHeight((rc.right - rc.left) / 2, (rc.bottom - rc.top) / 2);
/// }
/// 
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
///		GameEnd();			Called at the VERY BEGINING of the game shutdown process
///							This is where you would want to delete any singletons you may have
/// 
/// 
/// Example GameEnd definition
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// void MOABE::GameEnd()
/// {
///		PlayerManager::Delete();
///		BulletFactory::Delete();
/// }
/// 
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
///		LoadAllContent();	Called at the after GameStart().
///							Allows you to load all content needed for your engine,
///							such as objects, graphics, etc.
/// 
/// Example LoadAllContent definition
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// 
/// void MOABE::LoadAllContent()
/// {
///		// Plane Materials
///		ModelManager::Load("Plane", 400, 2, 2);
///		
///		TextureManager::Load("Grid", "grid.tga");
///		
///		ShaderManager::Load("Flat", "textureFlatRender");
/// }
/// 
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// 
class MOABE : public Engine
{
	friend class MOABEAttorney;
private:
	/// Default constructor.
	MOABE() = default;
	/// Copy constructor is deleted to prevent unintended copying.
	MOABE(const MOABE& other) = delete;
	/// Copy assignment operator is deleted to prevent unintended copying.
	MOABE& operator=(const MOABE& other) = delete;
	/// Move constructor is deleted to prevent unintended moves.
	MOABE(MOABE&& other) = delete;
	/// Move assignment operator is deleted to prevent unintended moves.
	MOABE& operator=(MOABE&& other) = delete;
	/// Destructor.
	~MOABE() = default;


private:
	/// Runs the game loop.
	static void Run(HINSTANCE hInstance);

public:
	/// Set User Functions Using this Function
	static void SetUserFunctions(MOABEUser* _pUserCode);

	/// Sets the window name.
	static void SetWindowName(const char* const WindowName);

	/// Sets the background color.
	static void SetColor(const float R, const float G, const float B, const float A);

	/// Sets the width and height of the window.
	static void SetWidthHeight(const int width, const int height);

	/// Gets the width of the window.
	static const int GetWidth();

	/// Gets the height of the window.
	static const int GetHeight();

	static void EnableAsync();
	static void DisableAsync();

	/// Sets the current 3D camera
	static void SetCamera3D(Camera* pCam);

	/// Sets the current 2D camera
	static void SetCamera2D(Camera* pCam);

private:
	/// Gets the time in seconds.
	static const float GetTimeInSeconds();

	/// Initializes the engine.
	virtual void Initialize() override;

	/// Loads the game content.
	virtual void LoadContent() override;

	/// Updates the game state.
	virtual void Update() override;

	/// Draws the game objects.
	virtual void Draw() override;

	/// Unloads the game content.
	virtual void UnLoadContent() override;

private:
	/// Gets the singleton instance of the MOABE engine.
	static MOABE& Instance();

	/// Pointer to the singleton instance of the MOABE engine.
	static MOABE* instance;

	/// Pointer to class containing user defined functions
	MOABEUser* pUserCode = nullptr;
};

#endif // MOABE_H