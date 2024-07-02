#ifndef DEBUGSCENESTRATEGY_H
#define DEBUGSCENESTRATEGY_H

#include "SceneStrategy.h"

/// Scene strategy for debugging.
/// 
/// Activates God Camera
/// 
/// @note This class is for internal use only
class DebugSceneStrategy : public SceneStrategy
{
public:
	/// Default constructor.
	DebugSceneStrategy() = default;
	/// Copy constructor.
	DebugSceneStrategy(const DebugSceneStrategy& other) = delete;
	/// Copy assignment operator.
	DebugSceneStrategy& operator=(const DebugSceneStrategy& other) = delete;
	/// Move constructor.
	DebugSceneStrategy(DebugSceneStrategy&& other) = delete;
	/// Move assignment operator.
	DebugSceneStrategy& operator=(DebugSceneStrategy&& other) = delete;
	/// Destructor.
	virtual ~DebugSceneStrategy() = default;

	/// Updates the scene using this strategy.
	virtual void Update(Scene* const pScene) const override;

	/// Draws the scene using this strategy.
	virtual void Draw(Scene* const pScene) const override;
};

#endif // DEBUGSCENESTRATEGY_H
