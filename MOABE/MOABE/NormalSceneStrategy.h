#ifndef NORMALSCENESTRATEGY_H
#define NORMALSCENESTRATEGY_H

#include "SceneStrategy.h"

/// Scene strategy for scenes normal behavior.
/// 
/// Proccesses scenes normally
/// 
/// @note This class is for internal use only
class NormalSceneStrategy : public SceneStrategy
{
public:
	/// Default constructor.
	NormalSceneStrategy() = default;
	/// Copy constructor.
	NormalSceneStrategy(const NormalSceneStrategy& other) = delete;
	/// Copy assignment operator.
	NormalSceneStrategy& operator=(const NormalSceneStrategy& other) = delete;
	/// Move constructor.
	NormalSceneStrategy(NormalSceneStrategy&& other) = delete;
	/// Move assignment operator.
	NormalSceneStrategy& operator=(NormalSceneStrategy&& other) = delete;
	/// Destructor.
	~NormalSceneStrategy() = default;

	/// Updates the scene using this strategy.
	virtual void Update(Scene* const pScene) const override;
	/// Draws the scene using this strategy.
	virtual void Draw(Scene* const pScene) const override;
};

#endif // NORMALSCENESTRATEGY_H
