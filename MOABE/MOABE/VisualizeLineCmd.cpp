#include "VisualizeLineCmd.h"

#include <GraphicsObject_Wireframe.h>

#include "VisualizerAttorney.h"

const Vect VisualizeLineCmd::UP_VECT = Vect(0.0f, 1.0f, 0.0f);
const float VisualizeLineCmd::LINE_SCALE_XY = 0.5f;
const float VisualizeLineCmd::LINE_SCALE_Z = 50000.0f;

VisualizeLineCmd::VisualizeLineCmd(GraphicsObject_Wireframe& _Line) :
	Line(_Line),
	StartPoint(),
	Dir(),
	Color()
{
}

void VisualizeLineCmd::SetData(const Vect& _StartPoint, const Vect& _EndPoint, const Vect& _Color)
{
	this->StartPoint = _StartPoint - (LINE_SCALE_Z * this->Dir);
	this->EndPoint = _StartPoint + (LINE_SCALE_Z * this->Dir);
	this->Dir = _EndPoint - _StartPoint;
	this->Color = _Color;
}

void VisualizeLineCmd::Execute() const
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

void VisualizeLineCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
