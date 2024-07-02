#ifndef SCENESTRATEGY_H
#define SCENESTRATEGY_H

class Scene;
class RegistrationCommand;

/// Abstract base class for scene strategies.
/// 
/// @note This class is for internal use only
class SceneStrategy
{
public:
	/// Default constructor.
	SceneStrategy() = default;
	/// Copy constructor.
	SceneStrategy(const SceneStrategy& other) = default;
	/// Copy assignment operator.
	SceneStrategy& operator=(const SceneStrategy& other) = default;
	/// Move constructor.
	SceneStrategy(SceneStrategy&& other) = default;
	/// Move assignment operator.
	SceneStrategy& operator=(SceneStrategy&& other) = default;	
	/// Destructor.
	~SceneStrategy() = default;

	/// Updates the scene using this strategy.
	virtual void Update(Scene* const pScene) const = 0;

	/// Draws the scene using this strategy.
	virtual void Draw(Scene* const pScene) const = 0;
};

#endif // SCENESTRATEGY_H
