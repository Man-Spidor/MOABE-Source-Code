#ifndef VISUALIZEPOINTCMD_H
#define VISUALIZEPOINTCMD_H

#include "VisualizeCommand.h"
#include <Matrix.h>

class GraphicsObject_Wireframe;

class VisualizePointCmd : public VisualizeCommand
{
public:
	VisualizePointCmd() = delete;
	VisualizePointCmd(const VisualizePointCmd& other) = default;
	VisualizePointCmd& operator=(const VisualizePointCmd& other) = default;
	VisualizePointCmd(VisualizePointCmd&& other) = default;
	VisualizePointCmd& operator=(VisualizePointCmd&& other) = default;
	~VisualizePointCmd() = default;

	VisualizePointCmd(GraphicsObject_Wireframe& _PointBox);

	void SetData(const Vect& _Point, const Vect& _Color);

	virtual void Execute() const;
	virtual void Return();

private:
	static const Matrix POINT_SCALE_MAT;
	static const float POINT_SCALE;
	Vect Point;
	Vect Color;
	GraphicsObject_Wireframe& PointBox;
};

#endif // VISUALIZEPOINTCMD_H
