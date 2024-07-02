#include "VisualizeLineRayCmd.h"

#include <GraphicsObject_Wireframe.h>

#include "VisualizerAttorney.h"

const Vect VisualizeLineRayCmd::UP_VECT = Vect(0.0f, 1.0f, 0.0f);
const float VisualizeLineRayCmd::LINE_SCALE_XY = 0.5f;
const float VisualizeLineRayCmd::LINE_SCALE_Z = 50000.0f;

VisualizeLineRayCmd::VisualizeLineRayCmd(GraphicsObject_Wireframe& _Line) :
	Line(_Line),
	StartPoint(),
	Dir(),
	Color()
{
}

void VisualizeLineRayCmd::SetData(const Vect& _StartPoint, const Vect& TargetPos, const Vect& _Color)
{
	this->StartPoint = _StartPoint;
	this->Dir = TargetPos - this->StartPoint;
	this->EndPoint = this->StartPoint + (LINE_SCALE_Z * this->Dir);
	this->Color = _Color;
}

void VisualizeLineRayCmd::Execute() const
{
	//
	//	Scaling:
	//		xy : some small value
	//		z : some MASSIVE value
	//			
	//	Rotation :
	//			Use Rot_Orient matrices with fwd = this->EndPoint - this->StartPoint and Up = y axis
	//			
	//	Translation:
	//			(this->StartPoint + this->EndPoint) / 2.0f
	//
	Matrix world =	Matrix(SCALE, LINE_SCALE_XY, LINE_SCALE_XY, (this->EndPoint - this->StartPoint).mag()) *
					Matrix(ROT_ORIENT, this->EndPoint - this->StartPoint, UP_VECT) *
					Matrix(TRANS, 0.5f * (this->StartPoint + this->EndPoint));

	this->Line.SetWorld(world);
	this->Line.SetColor(this->Color);
	this->Line.Render();

	world = Matrix(SCALE, LINE_SCALE_XY, LINE_SCALE_XY, LINE_SCALE_XY) * Matrix(TRANS, this->StartPoint);
}

void VisualizeLineRayCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
