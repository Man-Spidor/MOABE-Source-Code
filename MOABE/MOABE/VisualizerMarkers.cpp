#include "VisualizerMarkers.h"

#include "VisualizerAttorney.h"

void VisualizerMarkers::Draw() const
{
	VisualizerAttorney::VisStrats::VisualizeAll();
}

void VisualizerMarkers::ShowMarkerPoint(const Vect& point, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushPointCmd(point, color);
}

void VisualizerMarkers::ShowMarkerLineSegment(const Vect& startPoint, const Vect& endPoint, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushLineSegmentCmd(startPoint, endPoint, color);
}

void VisualizerMarkers::ShowMarkerLineRay(const Vect& startPoint, const Vect& targetPos, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushLineRayCmd(startPoint, targetPos, color);
}

void VisualizerMarkers::ShowMarkerLine(const Vect& startPoint, const Vect& targetPos, const Vect& color) const
{
	VisualizerAttorney::VisStrats::PushLineCmd(startPoint, targetPos, color);
}
