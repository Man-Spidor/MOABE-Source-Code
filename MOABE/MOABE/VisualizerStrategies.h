#ifndef VISUALIZERSTRATEGIES_H
#define VISUALIZERSTRATEGIES_H

#include "VisualizerDraw.h"
#include "VisualizerDrawAllCollidable.h"
#include "VisualizerDefault.h"
#include "VisualizerMarkers.h"

class VisualizerStrategies
{
public:
	static const VisualizerDefault				VisualizeDefault;
	static const VisualizerDrawDefault			VisualizeDrawDefault;
	static const VisualizerDrawAllCollidable	VisualizeCollidable;
	static const VisualizerMarkers				VisualizeMarkers;
};

#endif