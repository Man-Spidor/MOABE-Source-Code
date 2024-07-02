#include "VisualizeOBBCmd.h"

#include "CV_OBB.h"
#include "GraphicsObject_Wireframe.h"

#include "VisualizerAttorney.h"

VisualizeOBBCmd::VisualizeOBBCmd(GraphicsObject_Wireframe& _UnitBox) :
	UnitBox(_UnitBox),
	OBB(nullptr),
	Color()
{
}

void VisualizeOBBCmd::SetData(const CV_OBB* _OBB, const Vect& _Color)
{
	this->OBB = _OBB;
	this->Color = _Color;
}

void VisualizeOBBCmd::Execute() const
{
	const Vect scale = this->OBB->GetMax() - this->OBB->GetMin();
	const Vect trans = 0.5f * (this->OBB->GetMax() + this->OBB->GetMin());

	Matrix world = Matrix(SCALE, scale.X(), scale.Y(), scale.Z()) * Matrix(TRANS, trans.X(), trans.Y(), trans.Z());

	world *= this->OBB->GetWorld();

	this->UnitBox.SetWorld(world);
	this->UnitBox.SetColor(this->Color);
	this->UnitBox.Render();
}

void VisualizeOBBCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
