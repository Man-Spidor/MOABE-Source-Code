#include "VisualizeBSphereCmd.h"

#include "VisualizerAttorney.h"

VisualizeBSphereCmd::VisualizeBSphereCmd(GraphicsObject_Wireframe& _UnitBSphere) :
	UnitBSphere(_UnitBSphere),
	BSphere(nullptr),
	Color()
{
}

void VisualizeBSphereCmd::SetData(const CV_BSphere* _BSphere, const Vect& _Color)
{
	this->BSphere = _BSphere;
	this->Color = _Color;
}

void VisualizeBSphereCmd::Execute() const
{
	const Vect& center = this->BSphere->GetCenter();
	const Vect& radius = this->BSphere->GetRadius() * Vect(1, 1, 1);

	// Adjust the Bounding Sphere's position and scale to fit the Ship's center and scale
	Matrix world = Matrix(IDENTITY) * Matrix(SCALE, radius) * Matrix(TRANS, center);

	this->UnitBSphere.SetWorld(world);
	this->UnitBSphere.SetColor(this->Color);
	this->UnitBSphere.Render();
}

void VisualizeBSphereCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
