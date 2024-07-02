#ifndef COLLISIONDISPATCHPROXY_H
#define COLLISIONDISPATCHPROXY_H

#include "Collidable.h"

class Vect;

/// Base class for Collision Dispatches
/// 
/// This class is meant to obscure the use of templates.
/// @note This class is for internal use only.
class CollisionDispatchProxy
{
public:
	/// Default Constructor
	CollisionDispatchProxy() = default;
	/// Copy Constructor
	CollisionDispatchProxy(const CollisionDispatchProxy& other) = delete;
	/// Copy Assignment
	CollisionDispatchProxy& operator=(const CollisionDispatchProxy& other) = delete;
	/// Move Constructor
	CollisionDispatchProxy(CollisionDispatchProxy&& other) = delete;
	/// Move Assignment
	CollisionDispatchProxy& operator=(CollisionDispatchProxy&& other) = delete;
	/// Destructor
	virtual ~CollisionDispatchProxy() = default;

	/// Process the collision callbacks between two collidable objects
	/// 
	/// This function should be overridden in derived classes to specify the specific
	/// collision handling behavior.
	/// 
	/// @param pCol1 Pointer to the first collidable object
	/// @param pCol2 Pointer to the second collidable object
	virtual void ProcessCallbacks(Collidable* pCol1, Collidable* pCol2) const = 0;

	/// Process the collision callbacks between a collidable and terrain
	/// 
	/// This function should be overridden in derived classes to specify the specific
	/// collision handling behavior.
	/// 
	/// @param pCol1 Pointer to the collidable object
	virtual void ProcessCallbacks(Collidable* pCol, const float height, const Vect& normal) const = 0;
};

#endif // COLLISIONDISPATCHPROXY_H
