#ifndef VISUALIZELINECMD_H
#define VISUALIZELINECMD_H

#include "VisualizeCommand.h"
#include <Vect.h>

class GraphicsObject_Wireframe;

class VisualizeLineCmd : public VisualizeCommand
{
	static const Vect UP_VECT;
	static const float LINE_SCALE_XY;
	static const float LINE_SCALE_Z;

public:
	VisualizeLineCmd() = delete;
	VisualizeLineCmd(const VisualizeLineCmd& other) = default;
	VisualizeLineCmd& operator=(const VisualizeLineCmd& other) = default;
	VisualizeLineCmd(VisualizeLineCmd&& other) = default;
	VisualizeLineCmd& operator=(VisualizeLineCmd&& other) = default;
	~VisualizeLineCmd() = default;

	VisualizeLineCmd(GraphicsObject_Wireframe& _Line);

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

#endif // VISUALIZELINECMD_H
