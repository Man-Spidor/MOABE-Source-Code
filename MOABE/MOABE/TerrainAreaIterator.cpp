#include "TerrainAreaIterator.h"

#include "TerrainArea.h"
#include "TerrainModel.h"

//TerrainAreaIterator::TerrainAreaIterator(const TerrainAreaIterator& other)
//{
//	this->x = other.x;
//	this->x = other.z;
//
//	this->Area = other.Area;
//	this->Cell = other.Cell;	
//}
//
//TerrainAreaIterator& TerrainAreaIterator::operator=(const TerrainAreaIterator& other)
//{
//	this->x = other.x;
//	this->x = other.z;
//
//	this->Area = other.Area;
//	this->Cell = other.Cell;
//
//	return *this;
//}

TerrainAreaIterator::TerrainAreaIterator(const TerrainArea& _Area) :
	x(),
	z(),
	Area(&_Area),
	Cell(nullptr)
{
}

void TerrainAreaIterator::SetPoint(const float _x, const float _z)
{
	this->x = _x;
	this->z = _z;
	this->Cell = &this->Area->GetTerrainCell(this->x, this->z);
}

const bool TerrainAreaIterator::operator==(const TerrainAreaIterator& other)
{
	return fabs(this->x - other.x) < FLT_EPSILON && fabs(this->z - other.z) < FLT_EPSILON;
}

const bool TerrainAreaIterator::operator!=(const TerrainAreaIterator& other)
{
	return !(*this == other);
}

const TerrainCell& TerrainAreaIterator::operator*() const
{
	return *this->Cell;
}

TerrainAreaIterator& TerrainAreaIterator::operator++()
{
	if (this->privReachedEdgeOfCellX()) {
		if (this->privReachedEdgeOfCellZ()) {
			this->x = this->Area->end().x;
			this->z = this->Area->end().z;
		}
		else {
			this->z += this->Area->CellWidth();
			this->x = this->Area->begin().x;
		}
	}
	else {
		this->x += this->Area->CellWidth();
	}
	this->Cell = &this->Area->GetTerrainCell(this->x, this->z);

	return *this;
}

TerrainAreaIterator TerrainAreaIterator::operator++(int)
{
	TerrainAreaIterator tmp = *this;
	if (this->privReachedEdgeOfCellX()) {
		if (this->privReachedEdgeOfCellZ()) {
			this->x = this->Area->end().x;
			this->z = this->Area->end().z;
		}
		else {
			this->z += this->Area->CellWidth();
			this->x = this->Area->begin().x;
		}
	}
	else {
		this->x += this->Area->CellWidth();
	}
	this->Cell = &this->Area->GetTerrainCell(this->x, this->z);

	return tmp;
}

const bool TerrainAreaIterator::privReachedEdgeOfCellX() const
{
	return this->x >= this->Area->end().x + this->Area->CellWidth();
}

const bool TerrainAreaIterator::privReachedEdgeOfCellZ() const
{
	return this->z >= this->Area->end().z + this->Area->CellWidth();
}
