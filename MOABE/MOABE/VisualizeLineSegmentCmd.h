#ifndef VISUALIZELINESEGMENTCMD_H
#define VISUALIZELINESEGMENTCMD_H

#include "VisualizeCommand.h"
#include <Vect.h>

class GraphicsObject_Wireframe;

class VisualizeLineSegmentCmd : public VisualizeCommand
{
	static const Vect UP_VECT;
	static const float LINE_SCALE_XY;

public:
	VisualizeLineSegmentCmd() = delete;
	VisualizeLineSegmentCmd(const VisualizeLineSegmentCmd& other) = default;
	VisualizeLineSegmentCmd& operator=(const VisualizeLineSegmentCmd& other) = default;
	VisualizeLineSegmentCmd(VisualizeLineSegmentCmd&& other) = default;
	VisualizeLineSegmentCmd& operator=(VisualizeLineSegmentCmd&& other) = default;
	~VisualizeLineSegmentCmd() = default;

	VisualizeLineSegmentCmd(GraphicsObject_Wireframe& _Line);

	void SetData(const Vect& _StartPoint, const Vect& EndPoint, const Vect& _Color);

	virtual void Execute() const override;
	virtual void Return() override;

private:
	GraphicsObject_Wireframe& Line;
	Vect StartPoint;
	Vect EndPoint;
	Vect Dir;
	Vect Color;
};

#endif // VISUALIZELINESEGMENTCMD_H
