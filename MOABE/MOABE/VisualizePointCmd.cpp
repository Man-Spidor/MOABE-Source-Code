#include "VisualizePointCmd.h"

#include <GraphicsObject_Wireframe.h>

#include "VisualizerAttorney.h"

const float VisualizePointCmd::POINT_SCALE = 1.0f;
const Matrix VisualizePointCmd::POINT_SCALE_MAT = Matrix(SCALE, POINT_SCALE, POINT_SCALE, POINT_SCALE);

VisualizePointCmd::VisualizePointCmd(GraphicsObject_Wireframe& _PointBox) : 
	Point(),
	Color(),
	PointBox(_PointBox)
{
}

void VisualizePointCmd::SetData(const Vect& _Point, const Vect& _Color)
{
	this->Point = _Point;
	this->Color = _Color;
}

void VisualizePointCmd::Execute() const
{
	Matrix world = POINT_SCALE_MAT * Matrix(TRANS, this->Point);

	this->PointBox.SetWorld(world);
	this->PointBox.SetColor(this->Color);
	this->PointBox.Render();
}

void VisualizePointCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
