#include "TerrainArea.h"

#include "Vect.h"
#include "TerrainModel.h"

TerrainArea::TerrainArea(const TerrainModel& _Terrain) :
	Terrain(_Terrain),
	Front(*this),
	Back(*this),
	cellwidth(Terrain.GetCellWidth())
{
}

void TerrainArea::SetArea(const Vect& Min, const Vect& Max)
{
	this->Front.SetPoint(Min.X(), Min.Z());
	this->Back.SetPoint(Max.X(), Max.Z());
}

const TerrainModel& TerrainArea::GetTerrain() const
{
	return this->Terrain;
}

const TerrainAreaIterator& TerrainArea::begin() const
{
	return this->Front;
}

const TerrainAreaIterator& TerrainArea::end() const
{
	return this->Back;
}

const float TerrainArea::CellWidth() const
{
	return this->cellwidth;
}

const TerrainCell& TerrainArea::GetTerrainCell(const float x, const float z) const
{
	int side = this->Terrain.GetSideLen();
	side -= 1;

	int i = int(round(x / this->cellwidth));
	i += side / 2;

	int j = int(round(z / this->cellwidth));
	j += side / 2;

	if (i >= side)
		i = side - 1;
	else if (i < 0)
		i = 0;

	if (j >= side)
		j = side - 1;
	else if (j < 0)
		j = 0;

	return this->Terrain.GetCellList()[(j * side) + i];
}
