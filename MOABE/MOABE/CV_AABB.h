#ifndef CV_AABB_H
#define CV_AABB_H

#include "CV_BoxBase.h"

/// Collision volume representing an axis-aligned bounding box.
/// 
/// @note this class is for internal use only
class CV_AABB : public CV_BoxBase
{
public:
	/// Default Constructor
	CV_AABB();
	/// Copy Constructor
	CV_AABB(const CV_AABB& other) = default;
	/// Copy Assignment
	CV_AABB& operator=(const CV_AABB& other) = default;
	/// Move Constructor
	CV_AABB(CV_AABB&& other) = default;
	/// Move Assignment
	CV_AABB& operator=(CV_AABB&& other) = default;
	/// Destructor
	~CV_AABB() = default;

protected:
	/// Compute data for the AABB from the given model and transformation matrix
	/// 
	/// @param ColModel Pointer to the model used to compute the data
	/// @param matrix The transformation matrix
	virtual void ComputeData(Model* ColModel, const Matrix& matrix);

public:
	/// Compute data for the AABB from the given bounding sphere
	/// 
	/// @param pBSphere Pointer to the bounding sphere used to compute the data
	void ComputeData(const CV_BSphere& pBSphere);

protected:
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

	/// Check intersection between this collision volume and another axis-aligned bounding box
	/// 
	/// @param other The axis-aligned bounding box to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_AABB& other) const override;

	/// Check intersection between this collision volume and an oriented bounding box
	/// 
	/// @param other The oriented bounding box to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const CV_OBB& other) const override;

	/// Check intersection between this collision volume and a terrain cell
	/// 
	/// @param terrain The terrain cell to check against
	/// @return true if intersection occurs, false otherwise
	virtual const bool IntersectVisit(const TerrainCell& terrain) const override;

	/// Called to visualize the collision volume
	virtual void debug() const;

	/// Called to visualize the collision volume with a specific color
	/// 
	/// @param color The color to visualize the collision volume with
	virtual void debug(const Vect& color) const;
};

#endif // CV_AABB_H