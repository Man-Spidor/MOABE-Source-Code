#include "CV_OBB.h"

#include "EngineMath.h"
#include "Visualizer.h"
#include "VolumeAttorney.h"

CV_OBB::CV_OBB() :
	CV_BoxBase()
{
}

void CV_OBB::ComputeData(Model* ColModel, const Matrix& matrix)
{
	// this->debug();

	this->worldMat = matrix;
	this->worldMatInv = matrix.getInv();
	this->center = ColModel->GetCenter() * matrix;
	CalcScale(matrix);
}

const bool CV_OBB::IntersectAccept(const CollisionVolume& other) const
{
	return VolumeAttorney::IntersectVisit(other, *this);
}

const bool CV_OBB::IntersectVisit(const CV_BSphere& other) const
{
	return EngineMath::Intersect(*this, other);
}

const bool CV_OBB::IntersectVisit(const CV_OBB& other) const
{
	return EngineMath::Intersect(*this, other);
}

const bool CV_OBB::IntersectVisit(const CV_AABB& other) const
{
	return EngineMath::Intersect(*this, other);
}

const bool CV_OBB::IntersectVisit(const TerrainCell& Terrain) const
{
	return EngineMath::Intersect(Terrain, *this);
}

void CV_OBB::debug() const
{
	Visualizer::ShowOBB(*this);
}

void CV_OBB::debug(const Vect& color) const
{
	Visualizer::ShowOBB(*this, color);
}
