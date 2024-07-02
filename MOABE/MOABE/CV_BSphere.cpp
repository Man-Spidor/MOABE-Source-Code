#include "CV_BSphere.h"

#include "VolumeAttorney.h"

#include "Visualizer.h"
#include "EngineMath.h"

CV_BSphere::CV_BSphere() :
	Center(),
	Radius(0.0f)
{
}

void CV_BSphere::SetCenter(const Vect& _Center)
{
	this->Center = _Center;
}

void CV_BSphere::SetRadius(const float& _Radius)
{
	this->Radius = _Radius;
}

void CV_BSphere::ComputeData(Model* ColModel, const Matrix& matrix)
{
	// this->debug();

	this->Center = ColModel->GetCenter();
	this->Radius = ColModel->GetRadius();

	this->Center *= matrix;

	// this assumes uniform scaling
	const float scaleFactor = matrix.get(ROW_0).mag();
	
	this->Radius *= scaleFactor;
}

const bool CV_BSphere::IntersectAccept(const CollisionVolume& other) const
{
	return VolumeAttorney::IntersectVisit(other, *this);
}

const bool CV_BSphere::IntersectVisit(const CV_BSphere& other) const
{
	return EngineMath::Intersect(*this, other);
}

const bool CV_BSphere::IntersectVisit(const CV_OBB& other) const
{
	return EngineMath::Intersect(other, *this);
}

const bool CV_BSphere::IntersectVisit(const CV_AABB& other) const
{
	return EngineMath::Intersect(other, *this);
}

const bool CV_BSphere::IntersectVisit(const TerrainCell& Terrain) const
{
	return EngineMath::Intersect(Terrain, *this);
}

const Vect& CV_BSphere::GetCenter() const
{
	return this->Center;
}

const float CV_BSphere::GetRadius() const
{
	return this->Radius;
}

const float CV_BSphere::GetRadiusSqr() const
{
	return this->Radius * this->Radius;
}

void CV_BSphere::debug() const
{
	Visualizer::ShowBSphere(*this);
}

void CV_BSphere::debug(const Vect& color) const
{
	Visualizer::ShowBSphere(*this, color);
}
