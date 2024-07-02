#ifndef MOABESPRITE_H
#define MOABESPRITE_H

struct jAzulRect;

class Image;
class Camera;
class GraphicsObject_Sprite;

/// Represents a sprite in the MOABE engine.
/// 
/// Wrapper class for jAzul's GraphicsObject_Sprite class.
/// 
/// ### Usage Example:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// // Creating an instance of a class derived from Alarmable
/// class MyGameObject : public GameObject {
/// 	// ...
/// };
/// 
/// // Registering an alarm
/// void MyGameObject::SceneEntry() {
///		// ...
///		Alarmable::RegisterAlarm(0, 5.0f); // Registering alarm 0 to trigger after 5 seconds
///		// ... 
///		
///		// Deregistering an alarm
///		Alarmable::DeregisterAlarm(0);
/// }
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class MOABESprite : public Align16
{
public:
	/// Default Constructor (deleted)
	MOABESprite() = delete;
	/// Copy Constructor
	MOABESprite(const MOABESprite& other) = default;
	/// Copy Assignment Operator
	MOABESprite& operator=(const MOABESprite& other) = default;
	/// Move Constructor
	MOABESprite(MOABESprite&& other) = default;
	/// Move Assignment Operator
	MOABESprite& operator=(MOABESprite&& other) = default;
	/// Destructor
	~MOABESprite();

	/// Constructor that initializes the sprite with an image.
	/// 
	/// Constructor takes predefined Image object to create the sprite. Make sure youre image's rect 
	/// matches the area of the sprite on the texture.
	/// 
	/// @param pImage Pointer to the image used to create the sprite
	MOABESprite(Image* pImage);

	/// Constructor that initializes the sprite with a sprite name.
	/// 
	/// Uses the entirety of the texture to construct the jAzulRect, and Image.
	/// 
	/// @note Only use this constructor if the sprite encompasses the entirety of the texture
	/// 
	/// @param SpriteName Name of the sprite
	MOABESprite(const char* const SpriteName);

	/// Get the current rotation angle of the sprite.
	/// 
	/// @return The current rotation angle in radians
	const float GetAngle() const;

	/// Set the rotation angle of the sprite.
	/// 
	/// @param _angle The new rotation angle in radians
	void SetAngle(const float _angle);

	/// Get the width of the sprite.
	/// 
	/// @return The width of the sprite
	const float GetWidth() const;

	/// Get the height of the sprite.
	/// 
	/// @return The height of the sprite
	const float GetHeight() const;

	/// Set the center point of the sprite.
	/// 
	/// @param _CenterX The x-coordinate of the center point
	/// @param _CenterY The y-coordinate of the center point
	void SetCenter(const float _CenterX, const float _CenterY);

	/// Set the scale factor of the sprite.
	/// 
	/// @param _ScaleX The scale factor in the x-direction
	/// @param _ScaleY The scale factor in the y-direction
	void SetScaleFactor(const float _ScaleX, const float _ScaleY);

	/// Set the scale of the sprite in pixels.
	/// 
	/// @param width The width in pixels
	/// @param height The height in pixels
	void SetScalePixel(const float width, const float height);

	/// Set the position of the sprite.
	/// 
	/// @param x The x-coordinate of the position
	/// @param y The y-coordinate of the position
	void SetPosition(const float x, const float y);

	/// Render the sprite.
	void Render() const;

private:
	jAzulRect* pRect; ///< Pointer to the rectangle defining the sprite's dimensions
	Image* pImage; ///< Pointer to the image used for the sprite
	GraphicsObject_Sprite* goSprite; ///< Pointer to the graphics object for the sprite

	float angle; ///< The rotation angle of the sprite
	float posX; ///< The x-coordinate of the sprite's position
	float posY; ///< The y-coordinate of the sprite's position
	float CenterX; ///< The x-coordinate of the sprite's center point
	float CenterY; ///< The y-coordinate of the sprite's center point
	float ScaleX; ///< The scale factor in the x-direction
	float ScaleY; ///< The scale factor in the y-direction
};

#endif // MOABESPRITE_H
