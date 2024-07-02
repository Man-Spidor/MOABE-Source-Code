#ifndef VISULIZELINERAYCMD_H
#define VISULIZELINERAYCMD_H

#include "VisualizeCommand.h"
#include <Vect.h>

class GraphicsObject_Wireframe;

class VisualizeLineRayCmd : public VisualizeCommand
{
	static const Vect UP_VECT;
	static const float LINE_SCALE_XY;
	static const float LINE_SCALE_Z;

public:
	VisualizeLineRayCmd() = delete;
	VisualizeLineRayCmd(const VisualizeLineRayCmd& other) = default;
	VisualizeLineRayCmd& operator=(const VisualizeLineRayCmd& other) = default;
	VisualizeLineRayCmd(VisualizeLineRayCmd&& other) = default;
	VisualizeLineRayCmd& operator=(VisualizeLineRayCmd&& other) = default;
	~VisualizeLineRayCmd() = default;

	VisualizeLineRayCmd(GraphicsObject_Wireframe& _Line);

	void SetData(const Vect& _StartPoint, const Vect& TargetPos, const Vect& _Color);

	virtual void Execute() const override;
	virtual void Return() override;

private:
	GraphicsObject_Wireframe& Line;
	Vect StartPoint;
	Vect EndPoint;
	Vect Dir;
	Vect Color;
};

#endif // VISULIZELINERAYCMD_H
