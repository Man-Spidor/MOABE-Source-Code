#include "VisualizeAABBCmd.h"

#include "CV_AABB.h"
#include "GraphicsObject_Wireframe.h"

#include "VisualizerAttorney.h"

VisualizeAABBCmd::VisualizeAABBCmd(GraphicsObject_Wireframe& _UnitBox) :
	UnitBox(_UnitBox),
	AABB(nullptr),
	Color()
{
}

void VisualizeAABBCmd::SetData(const CV_AABB* _AABB, const Vect& _Color)
{
	this->AABB = _AABB;
	this->Color = _Color;
}

void VisualizeAABBCmd::Execute() const
{
	const Vect scale = this->AABB->GetMax() - this->AABB->GetMin();
	const Vect trans = 0.5f * (this->AABB->GetMax() + this->AABB->GetMin());

	Matrix world = Matrix(SCALE, scale.X(), scale.Y(), scale.Z()) * Matrix(TRANS, trans.X(), trans.Y(), trans.Z());
	
	this->UnitBox.SetWorld(world);
	this->UnitBox.SetColor(this->Color);
	this->UnitBox.Render();
}

void VisualizeAABBCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
