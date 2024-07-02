#ifndef COLLISIONDISPATCH_H
#define COLLISIONDISPATCH_H

#include "CollisionDispatchProxy.h"

template <typename C1, typename C2>
class CollisionDispatch : public CollisionDispatchProxy
{
public:
	CollisionDispatch() = default;
	CollisionDispatch(const CollisionDispatch& other) = default;
	CollisionDispatch& operator=(const CollisionDispatch& other) = default;
	CollisionDispatch(CollisionDispatch&& other) = default;
	CollisionDispatch& operator=(CollisionDispatch&& other) = default;
	virtual ~CollisionDispatch() = default;

	virtual void ProcessCallbacks(Collidable* pCol1, Collidable* pCol2) const override {
		C1* pDerCol1 = static_cast<C1*>(pCol1);
		C2* pDerCol2 = static_cast<C2*>(pCol2);

		pDerCol1->Collision(pDerCol2);
		pDerCol2->Collision(pDerCol1);
	}

	virtual void ProcessCallbacks(Collidable* pCol, const float height, const Vect& normal) const override {
		UNREFERENCED_PARAMETER(pCol);
		UNREFERENCED_PARAMETER(height);
		UNREFERENCED_PARAMETER(normal);
	}
};

#endif // COLLISIONDISPATCHPROXY_H
