#include "VisualizeLineSegmentCmd.h"

#include <VisualizerAttorney.h>

#include <GraphicsObject_Wireframe.h>

const Vect VisualizeLineSegmentCmd::UP_VECT = Vect(0.0f, 1.0f, 0.0f);
const float VisualizeLineSegmentCmd::LINE_SCALE_XY = 0.5f;

VisualizeLineSegmentCmd::VisualizeLineSegmentCmd(GraphicsObject_Wireframe& _Line) :
	Line(_Line),
	StartPoint(),
	EndPoint(),
	Dir(),
	Color()
{
}

void VisualizeLineSegmentCmd::SetData(const Vect& _StartPoint, const Vect& _EndPoint, const Vect& _Color)
{
	this->StartPoint = _StartPoint;
	this->EndPoint = _EndPoint;
	this->Color = _Color;
}

void VisualizeLineSegmentCmd::Execute() const
{
	//
	//	Scaling:
	//		xy : some small value
	//		z : scale = length(this->StartPoint - this->EndPoint)
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

void VisualizeLineSegmentCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
