#include "CV_AABB.h"

#include "CV_BSphere.h"

#include "EngineMath.h"
#include "Visualizer.h"
#include "VolumeAttorney.h"

CV_AABB::CV_AABB() :
	CV_BoxBase()
{
}

void CV_AABB::ComputeData(Model* pModel, const Matrix& matrix)
{
	// this->debug();

	this->worldMat = matrix;
	this->worldMatInv = matrix.getInv();
	this->center = pModel->GetCenter() * matrix;
	this->CalcScale(matrix);
		
	int vectListSize = pModel->GetVertCount();
	const Vect* vectList = pModel->GetVertList();
	this->max = vectList[0] * matrix;
	this->min = vectList[1] * matrix;
	EngineMath::SetMinMax(this->min, this->max);

	for (int i = 2; i < vectListSize; i++) {
		EngineMath::CheckMinMax(vectList[i] * matrix, this->min, this->max);
	}
}

void CV_AABB::ComputeData(const CV_BSphere& pBSphere)
{
	const float radius = pBSphere.GetRadius();
	const Vect radiusOffset = Vect(radius, radius, radius);
	EngineMath::CheckMinMax(pBSphere.GetCenter() + radiusOffset, this->min, this->max);
	EngineMath::CheckMinMax(pBSphere.GetCenter() - radiusOffset, this->min, this->max);
}

const bool CV_AABB::IntersectAccept(const CollisionVolume& other) const
{
	return VolumeAttorney::IntersectVisit(other, *this);
}

const bool CV_AABB::IntersectVisit(const CV_BSphere& other) const
{
	return EngineMath::Intersect(*this, other);
}

const bool CV_AABB::IntersectVisit(const CV_AABB& other) const
{
	return EngineMath::Intersect(*this, other);
}

const bool CV_AABB::IntersectVisit(const CV_OBB& other) const
{
	return EngineMath::Intersect(other, *this);
}

const bool CV_AABB::IntersectVisit(const TerrainCell& Terrain) const
{
	return EngineMath::Intersect(Terrain, *this);
}

void CV_AABB::debug() const
{
	Visualizer::ShowAABB(*this);
}

void CV_AABB::debug(const Vect& color) const
{
	Visualizer::ShowAABB(*this, color);
}
