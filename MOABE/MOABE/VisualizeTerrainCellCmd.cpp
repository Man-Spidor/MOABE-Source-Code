#include "VisualizeTerrainCellCmd.h"

#include "TerrainModel.h"
#include "GraphicsObject_Wireframe.h"

#include "VisualizerAttorney.h"

VisualizeTerrainCellCmd::VisualizeTerrainCellCmd(GraphicsObject_Wireframe& _UnitBox) :
	UnitBox(_UnitBox),
	pCell(nullptr),
	Color()
{
}

void VisualizeTerrainCellCmd::SetData(const TerrainCell* _pCell, const Vect& _Color)
{
	this->pCell = _pCell;
	this->Color = _Color;
}

void VisualizeTerrainCellCmd::Execute() const
{
	const Vect scale = this->pCell->Max - this->pCell->Min;
	const Vect trans = 0.5f * (this->pCell->Max + this->pCell->Min);

	Matrix world = Matrix(SCALE, scale.X(), scale.Y(), scale.Z()) * Matrix(TRANS, trans.X(), trans.Y(), trans.Z());

	this->UnitBox.SetWorld(world);
	this->UnitBox.SetColor(Color);
	this->UnitBox.Render();
}

void VisualizeTerrainCellCmd::Return()
{
	VisualizerAttorney::VisStrats::ReturnDrawCmd(this);
}
