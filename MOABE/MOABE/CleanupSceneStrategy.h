#ifndef CLEANUPSCENESTRATEGY_H
#define CLEANUPSCENESTRATEGY_H

#include "SceneStrategy.h"

/// Scene strategy for cleaning up scenes.
/// 
/// This is the strategy used when switching scenes and processes the final cleanup 
/// before switching scenes
/// 
/// @note This class is for internal use only
class CleanupSceneStrategy : public SceneStrategy
{
public:
	/// Default constructor.
	CleanupSceneStrategy() = default;
	/// Copy constructor.
	CleanupSceneStrategy(const CleanupSceneStrategy& other) = delete;
	/// Copy assignment operator.
	CleanupSceneStrategy& operator=(const CleanupSceneStrategy& other) = delete;
	/// Move constructor.
	CleanupSceneStrategy(CleanupSceneStrategy&& other) = delete;
	/// Move assignment operator.
	CleanupSceneStrategy& operator=(CleanupSceneStrategy&& other) = delete;
	/// Destructor.
	~CleanupSceneStrategy() = default;

	/// Updates the scene using this strategy.
	virtual void Update(Scene* const pScene) const override;

	/// Draws the scene using this strategy (does nothing).
	virtual void Draw(Scene* const pScene) const override { UNREFERENCED_PARAMETER(pScene); };
};

#endif // CLEANUPSCENESTRATEGY_H
