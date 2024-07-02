#include "CV_BoxBase.h"

CV_BoxBase::CV_BoxBase() :
	worldMat(),
	worldMatInv(),
	max(),
	min(),
	center(),
	halfDiagonal(),
	scale(1.0f)
{
}

void CV_BoxBase::InitColData(const Model& Model)
{
	this->min = Model.GetModelMin();
	this->max = Model.GetModelMax();

	this->center = Model.GetCenter();
	this->halfDiagonal = this->max - this->center;
}

const float CV_BoxBase::GetScaleSqr() const
{
	return this->scale;
}

const Matrix& CV_BoxBase::GetWorld() const
{
	return this->worldMat;
}

const Matrix& CV_BoxBase::GetWorldInv() const
{
	return this->worldMatInv;
}

void CV_BoxBase::SetScale(const float _scale)
{
	this->scale = _scale;
}

void CV_BoxBase::SetMin(const Vect& _min)
{
	this->min = _min;
}

void CV_BoxBase::SetMax(const Vect& _max)
{
	this->max = _max;
}

const Vect& CV_BoxBase::GetMin() const
{
	return this->min;
}

const Vect& CV_BoxBase::GetMax() const
{
	return this->max;
}

const Vect& CV_BoxBase::GetDiag() const
{
	return this->halfDiagonal;
}

const Vect& CV_BoxBase::GetCenter() const
{
	return this->center;
}

void CV_BoxBase::CalcScale(const Matrix& world)
{
	this->scale = world.get(ROW_0).magSqr();
}
