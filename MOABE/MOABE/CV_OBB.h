#ifndef CV_OBB_H
#define CV_OBB_H

#include "CV_BoxBase.h"

/// Collision volume representing an oriented bounding box.
/// 
/// @note this class is for internal use only
class CV_OBB : public CV_BoxBase
{
public:
	/// Default Constructor
	CV_OBB();
	/// Copy Constructor
	CV_OBB(const CV_OBB& other) = default;
	/// Copy Assignment
	CV_OBB& operator=(const CV_OBB& other) = default;
	/// Move Constructor
	CV_OBB(CV_OBB&& other) = default;
	/// Move Assignment
	CV_OBB& operator=(CV_OBB&& other) = default;
	/// Destructor
	~CV_OBB() = default;

protected:
	/// Compute data for the collision volume from the given model and transformation matrix
	/// 
	/// @param ColModel Pointer to the model used to compute the data
	/// @param matrix The transformation matrix
	virtual void ComputeData(Model* ColModel, const Matrix& matrix);

	/// Check intersection between this collision volume and another collision volume
	/// 
	/// @param other The other collision volume to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectAccept(const CollisionVolume& other) const;

	/// Check intersection between this collision volume and a bounding sphere
	/// 
	/// @param other The bounding sphere to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_BSphere& other) const override;

	/// Check intersection between this collision volume and an axis-aligned bounding box
	/// 
	/// @param other The axis-aligned bounding box to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_AABB& other) const override;

	/// Check intersection between this collision volume and another oriented bounding box
	/// 
	/// @param other The oriented bounding box to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_OBB& other) const override;

	/// Check intersection between this collision volume and a terrain cell
	/// 
	/// @param Terrain The terrain cell to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const TerrainCell& Terrain) const override;

	/// Called to visualize the collision volume
	virtual void debug() const;

	/// Called to visualize the collision volume with a specific color
	/// 
	/// @param color The color to visualize the collision volume with
	virtual void debug(const Vect& color) const;
};

#endif // CV_OBB_H