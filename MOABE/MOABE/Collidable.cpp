#include "Collidable.h"

#include "CollidableGroup.h"
#include "CollidableRegCmd.h"
#include "CollidableDeRegCmd.h"

#include "VolumeAttorney.h"
#include "CV_BSphere.h"
#include "CV_AABB.h"
#include "CV_OBB.h"

#include "SceneAttorney.h"
#include <Visualizer.h>

Collidable::Collidable() : 
	pColVol(nullptr),
	pColModel(nullptr),
	pBSphere(nullptr),
	myID(CollisionManager::COLID_UNDEFINED),
	pRegCmd(new CollidableRegCmd(this)),
	pDeRegCmd(new CollidableDeRegCmd(this)),
	regStatus(RegistrationStatus::CURRENTLY_DEREGISTERED)
{
}

Collidable::~Collidable()
{
	delete this->pColVol;
	delete this->pBSphere;
	delete this->pRegCmd;
	delete this->pDeRegCmd;
}

const CollisionManager::ColID Collidable::GetCollisionID()
{
	return this->myID;
}

void Collidable::SetRegStatusRegistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_REGISTERED;
}

void Collidable::SetRegStatusDeregistered()
{
	this->regStatus = RegistrationStatus::CURRENTLY_DEREGISTERED;
}

void Collidable::UpdateCollisionData(const Matrix& matrix)
{
	VolumeAttorney::ComputeData(this->pBSphere, this->pColModel, matrix);
	VolumeAttorney::ComputeData(this->pColVol, this->pColModel, matrix);
}

void Collidable::DrawCollidable() const
{
	Visualizer::ShowVolume(*this->pColVol);
}

void Collidable::SetBSphereModel(Model* pModel)
{
	assert(!this->pColVol);
	this->pColVol = new CV_BSphere();	
	this->pBSphere = new CV_BSphere();
	this->pColModel = pModel;

	((CV_BSphere*)this->pColVol)->SetCenter(pModel->GetCenter());
	((CV_BSphere*)this->pColVol)->SetRadius(pModel->GetRadius());

	this->pBSphere->SetCenter(pModel->GetCenter());
	this->pBSphere->SetRadius(pModel->GetRadius());
}

void Collidable::SetAABBModel(Model* pModel)
{
	assert(!this->pColVol);
	this->pColVol = new CV_AABB();
	this->pBSphere = new CV_BSphere();
	this->pColModel = pModel;

	((CV_AABB*)this->pColVol)->InitColData(*this->pColModel);
	this->pBSphere->SetCenter(pModel->GetCenter());
	this->pBSphere->SetRadius(pModel->GetRadius());
}

void Collidable::SetOBBModel(Model* pModel)
{
	assert(!this->pColVol);
	this->pColVol = new CV_OBB();
	this->pBSphere = new CV_BSphere();
	this->pColModel = pModel;

	((CV_OBB*)this->pColVol)->InitColData(*this->pColModel);
	this->pBSphere->SetCenter(pModel->GetCenter());
	this->pBSphere->SetRadius(pModel->GetRadius());
}

const CollisionVolume& Collidable::GetColVolume() const
{
	return *this->pColVol;
}

const CollisionVolume& Collidable::GetPrimitiveVolume() const
{
	return *this->pBSphere;
}

void Collidable::RegisterToScene()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_DEREGISTERED);
	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pRegCmd);
	this->regStatus = RegistrationStatus::PENDING_REGISTRATION;
}

void Collidable::DeregisterFromScene()
{
	assert(this->regStatus == RegistrationStatus::CURRENTLY_REGISTERED);
	SceneAttorney::GameObjects::SubmitRegistrationCmd(SceneManager::GetCurrScene(), this->pDeRegCmd);
	this->regStatus = RegistrationStatus::PENDING_DEREGISTRATION;
}
