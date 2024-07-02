#ifndef COLLISIONVOLUME_H
#define COLLISIONVOLUME_H

#include <Model.h>
#include <Matrix.h>

class CV_OBB;
class CV_AABB;
class CV_BSphere;

struct TerrainCell;

/// Abstract base class for collision volumes.
/// 
/// @note this class is for internal use only
class CollisionVolume : public Align16
{
	friend class VolumeAttorney;

public:
	/// Default Constructor
	CollisionVolume() = default;
	/// Copy Constructor
	CollisionVolume(const CollisionVolume& other) = default;
	/// Copy Assignment
	CollisionVolume& operator=(const CollisionVolume& other) = default;
	/// Move Constructor
	CollisionVolume(CollisionVolume&& other) = default;
	/// Move Assignment
	CollisionVolume& operator=(CollisionVolume&& other) = default;
	/// Destructor
	virtual ~CollisionVolume() = default;

protected:
	/// Compute data for the collision volume from the given model and transformation matrix
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param ColModel Pointer to the model used to compute the data
	/// @param matrix The transformation matrix
	virtual void ComputeData(Model* ColModel, const Matrix& matrix) = 0;

	/// Check intersection between this collision volume and another collision volume
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param other The other collision volume to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectAccept(const CollisionVolume& other) const = 0;

	/// Check intersection between this collision volume and a bounding sphere
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param other The bounding sphere to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_BSphere& other) const = 0;

	/// Check intersection between this collision volume and an axis-aligned bounding box
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param other The axis-aligned bounding box to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_AABB& other) const = 0;

	/// Check intersection between this collision volume and an oriented bounding box
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param other The oriented bounding box to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_OBB& other) const = 0;

	/// Check intersection between this collision volume and a terrain cell
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param Terrain The terrain cell to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const TerrainCell& Terrain) const = 0;

	/// Called to visualize the collision volume
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	virtual void debug() const = 0;

	/// Called to visualize the collision volume with a specific color
	/// 
	/// This is a pure virtual function to be overridden by derived classes.
	/// 
	/// @param color The color to visualize the collision volume with
	virtual void debug(const Vect& color) const = 0;
};

#endif // COLLISIONVOLUME_H
