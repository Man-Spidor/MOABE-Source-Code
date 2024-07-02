#ifndef SCENESTRATEGIES_H
#define SCENESTRATEGIES_H

#include "NormalSceneStrategy.h"
#include "CleanupSceneStrategy.h"
#include "DebugSceneStrategy.h"

/// Class containing predefined scene strategies.
/// 
/// @note This class is for internal use only
class SceneStrategies
{
public:
	/// Predefined normal scene strategy.
	static const NormalSceneStrategy NormalStrategy;
	/// Predefined cleanup scene strategy.
	static const CleanupSceneStrategy CleanupStrategy;
	/// Predefined debug scene strategy.
	static const DebugSceneStrategy DebugStrategy;
};

#endif // SCENESTRATEGIES_H
