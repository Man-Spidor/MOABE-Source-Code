#ifndef CV_BOXBASE_H
#define CV_BOXBASE_H

#include "CollisionVolume.h"

/// Abstract base class for box-based collision volumes.
/// 
/// @note this class is for internal use only
class CV_BoxBase : public CollisionVolume
{
public:
	/// Default Constructor
	CV_BoxBase();
	/// Copy Constructor
	CV_BoxBase(const CV_BoxBase& other) = default;
	/// Copy Assignment
	CV_BoxBase& operator=(const CV_BoxBase& other) = default;
	/// Move Constructor
	CV_BoxBase(CV_BoxBase&& other) = default;
	/// Move Assignment
	CV_BoxBase& operator=(CV_BoxBase&& other) = default;
	/// Destructor
	~CV_BoxBase() = default;

public:
	/// Initialize collision data from the given model
	/// 
	/// @param Model The model used to initialize the data
	virtual void InitColData(const Model& Model);

	/// Get the squared scale of the collision volume
	/// 
	/// @return The squared scale value
	virtual const float GetScaleSqr() const;

	/// Get the world matrix of the collision volume
	/// 
	/// @return The world matrix
	virtual const Matrix& GetWorld() const;

	/// Get the inverse world matrix of the collision volume
	/// 
	/// @return The inverse world matrix
	virtual const Matrix& GetWorldInv() const;

	/// Set the scale of the collision volume
	/// 
	/// @param scale The scale value
	virtual void SetScale(const float scale);

	/// Set the minimum point of the collision volume
	/// 
	/// @param min The minimum point vector
	virtual void SetMin(const Vect& min);

	/// Set the maximum point of the collision volume
	/// 
	/// @param max The maximum point vector
	virtual void SetMax(const Vect& max);

	/// Get the minimum point of the collision volume
	/// 
	/// @return The minimum point vector
	virtual const Vect& GetMin() const;

	/// Get the maximum point of the collision volume
	/// 
	/// @return The maximum point vector
	virtual const Vect& GetMax() const;

	/// Get the diagonal vector of the collision volume
	/// 
	/// @return The diagonal vector
	virtual const Vect& GetDiag() const;

	/// Get the center point of the collision volume
	/// 
	/// @return The center point vector
	virtual const Vect& GetCenter() const;

protected:
	/// Finds the scaling factor
	/// @warning Assumes uniform scaling
	/// @param world World matrix from which the scale will be extracted
	virtual void CalcScale(const Matrix& world);

protected:
	Matrix worldMat; ///< The world matrix of the collision volume
	Matrix worldMatInv; ///< The inverse world matrix of the collision volume
	Vect max; ///< The maximum point of the collision volume
	Vect min; ///< The minimum point of the collision volume
	Vect center; ///< The center point of the collision volume
	Vect halfDiagonal; ///< The half-diagonal vector of the collision volume
	float scale; ///< The scale factor of the collision volume
};

#endif // CV_BOXBASE_H