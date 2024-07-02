#ifndef CV_BSPHERE_H
#define CV_BSPHERE_H

#include "CollisionVolume.h"

/// Collision volume representing a bounding sphere.
/// 
/// @note this class is for internal use only
class CV_BSphere : public CollisionVolume
{
public:
    /// Default Constructor
    CV_BSphere();
    /// Copy Constructor
    CV_BSphere(const CV_BSphere& other) = default;
    /// Copy Assignment
    CV_BSphere& operator=(const CV_BSphere& other) = default;
    /// Move Constructor
    CV_BSphere(CV_BSphere&& other) = default;
    /// Move Assignment
    CV_BSphere& operator=(CV_BSphere&& other) = default;
    /// Destructor
    virtual ~CV_BSphere() = default;

    /// Set the center of the bounding sphere
    /// 
    /// @param _Center The center vector
    void SetCenter(const Vect& _Center);

    /// Set the radius of the bounding sphere
    /// 
    /// @param _Radius The radius value
    void SetRadius(const float& _Radius);

    /// Compute data for the bounding sphere from the given model and transformation matrix
    /// 
    /// @param ColModel Pointer to the model used to compute the data
    /// @param matrix The transformation matrix
    virtual void ComputeData(Model* ColModel, const Matrix& matrix) override;

    /// Check intersection between this bounding sphere and another collision volume
    /// 
    /// @param other The other collision volume to check against
    /// @return true if intersection occurs, false otherwise
    virtual const bool IntersectAccept(const CollisionVolume& other) const override;

    /// Check intersection between this bounding sphere and another bounding sphere
    /// 
    /// @param other The other bounding sphere to check against
    /// @return true if intersection occurs, false otherwise
    virtual const bool IntersectVisit(const CV_BSphere& other) const override;

    /// Check intersection between this bounding sphere and an axis-aligned bounding box
    /// 
    /// @param other The axis-aligned bounding box to check against
    /// @return true if intersection occurs, false otherwise
    virtual const bool IntersectVisit(const CV_AABB& other) const override;

    /// Check intersection between this bounding sphere and an oriented bounding box
    /// 
    /// @param other The oriented bounding box to check against
    /// @return true if intersection occurs, false otherwise
    virtual const bool IntersectVisit(const CV_OBB& other) const override;

    /// Check intersection between this bounding sphere and a terrain cell
    /// 
    /// @param Terrain The terrain cell to check against
    /// @return true if intersection occurs, false otherwise
    virtual const bool IntersectVisit(const TerrainCell& Terrain) const override;

    /// Get the center of the bounding sphere
    /// 
    /// @return The center vector
    const Vect& GetCenter() const;

    /// Get the radius of the bounding sphere
    /// 
    /// @return The radius value
    const float GetRadius() const;

    /// Get the squared radius of the bounding sphere
    /// 
    /// @return The squared radius value
    const float GetRadiusSqr() const;

private:
    /// Called to visualize the bounding sphere
    /// 
    /// This is a pure virtual function to be overridden by derived classes.
    virtual void debug() const;

    /// Called to visualize the bounding sphere with a specific color
    /// 
    /// This is a pure virtual function to be overridden by derived classes.
    /// 
    /// @param color The color to visualize the bounding sphere with
    virtual void debug(const Vect& color) const;

private:
    Vect Center; ///< The center of the bounding sphere
    float Radius; ///< The radius of the bounding sphere
};

#endif // CV_BSPHERE_H
