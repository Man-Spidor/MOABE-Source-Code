#ifndef COLLISIONTERRAINDISPATCH_H
#define COLLISIONTERRAINDISPATCH_H

#include "CollisionDispatchProxy.h"

template <typename C>
class CollisionTerrainDispatch : public CollisionDispatchProxy
{
public:
	CollisionTerrainDispatch() = default;
	CollisionTerrainDispatch(const CollisionTerrainDispatch& other) = default;
	CollisionTerrainDispatch& operator=(const CollisionTerrainDispatch& other) = default;
	CollisionTerrainDispatch(CollisionTerrainDispatch&& other) = default;
	CollisionTerrainDispatch& operator=(CollisionTerrainDispatch&& other) = default;
	virtual ~CollisionTerrainDispatch() = default;

	virtual void ProcessCallbacks(Collidable* pCol1, Collidable* pCol2) const override {
		UNREFERENCED_PARAMETER(pCol1);
		UNREFERENCED_PARAMETER(pCol2);
		assert("NOT A VALID COLLISION PROCESS" && 0);
	}

	virtual void ProcessCallbacks(Collidable* pCol, const float height, const Vect& normal) const override {
		C* pDerCol = static_cast<C*>(pCol);
		
		pDerCol->CollisionTerrain(height, normal);
	}
};

#endif // COLLISIONDISPATCHPROXY_H
