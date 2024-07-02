#ifndef ENGINEMATH_H
#define ENGINEMATH_H

#include "Matrix.h"

class CV_OBB;
class CV_AABB;
class CV_BoxBase;
class CV_BSphere;
class CollisionVolume;

class TerrainModel;

class MOABESpotLight;
class MOABEPointLight;

struct TerrainCell;

/// Utility class for mathematical operations related to the game engine.
class EngineMath
{
public:
	/// Clamps A Point to an AABB's Min/Max
	static const Vect ClampPoint(const Vect& center, const Vect& min, const Vect& max);

	/// Tests if two pairs of Min/Maxes overlap
	/// 
	/// @param A Object A's Min
	/// @param B Object A's Max
	/// @param C Object B's Min
	/// @param D Object B's Max
	/// @returns true if the intervals overlap, false otherwise
	static bool IntervalOverlap(const Vect& A, const Vect& B, const Vect& C, const Vect& D);

	/// Tests if one interval overlaps
	/// 
	/// @param a Min 1
	/// @param b Max 1
	/// @param c Min 2
	/// @param d Max 2
	/// @returns true if the intervals overlap, false otherwise
	static bool IntervalOverlap(const float a, const float b, const float c, const float d);

	/// Computes the Max half-projection of a Box Volume onto a given axis
	/// 
	/// @param proj The maximum projection of an OBB onto an axis
	/// @param Box The Box
	/// @param Axis The Axis
	/// @param AxisMag The Magnitude of the Axis
	static const float MaxHalfProjection(const CV_BoxBase& Box, const Vect& Axis, const float AxisMag);
	
	static const float MaxHalfProjection(const TerrainCell& Cell, const Vect& Axis, const float AxisMag);
		
	static const bool TestAxis(const CV_BoxBase& A, const CV_BoxBase& B, const Vect& axis, const float axisMag);
	
	static const bool TestAxis(const CV_BoxBase& A, const TerrainCell& B, const Matrix& CellWorld, const Vect& axis, const float axisMag);

	static const bool AxisOverlap(const Vect& Center1, const Vect& Center2, const Vect& Axis, const float proj1, const float proj2, const float AxisMag);

	static const bool TestPointMinMax(const Vect& Point, const Vect& Min, const Vect& Max, const float TestDist);
	
	static const bool TestPointMinMaxWorldToLocal(const Matrix& World, const Matrix& WorldInv, const Vect& Point, const Vect& Min, const Vect& Max, const float TestDist);

	static const bool TestPointTerrainCell(const TerrainCell& Cell, const Vect& Point, const float TestDist);

	static const bool TestPointTerrainCellByPos(const TerrainModel& Terrain, const float cellwidth, const float x, const float z, const Vect& Point, const float TestDist);

#pragma region Intersect Functions

	/// Generic Test Function For Testing If Two Collision Volumes IntersectAccept
	///
	/// Uses visitor pattern to correctly cast each Collision Volume to its proper type.
	/// 
	/// @param A The first collision volume
	/// @param B The second collision volume
	/// @return true if the volumes intersect, false otherwise
	static const bool Intersect(const CollisionVolume& A, const CollisionVolume& B);

	/// Check if two bounding spheres intersect.
	/// 
	/// This static function determines whether two bounding spheres intersect or not.
	/// 
	/// @param A The first bounding sphere
	/// @param B The second bounding sphere
	/// @return true if the bounding spheres intersect, false otherwise
	static const bool Intersect(const CV_BSphere& A, const CV_BSphere& B);

	/// Check if two bounding spheres intersect.
	/// 
	/// This static function determines whether two bounding spheres intersect or not.
	/// 
	/// @param A The first bounding sphere
	/// @param B The second bounding sphere
	/// @return true if the bounding spheres intersect, false otherwise
	static const bool Intersect(const CV_AABB& A, const CV_AABB& B);

	/// Check if an AABB and a BSpheres are intersecting.
	/// 
	/// This static function determines whether an AABB and a bounding spheres intersect or not.
	/// 
	/// @param A The AABB
	/// @param B The BSphere
	/// @return true if the AABB and BSphere intersect, false otherwise
	static const bool Intersect(const CV_AABB& A, const CV_BSphere& B);

	static const bool Intersect(const CV_OBB& A, const CV_BSphere& B);

	static const bool Intersect(const CV_OBB& A, const CV_OBB& B);

	static const bool Intersect(const CV_OBB& A, const CV_AABB& B);

	static const bool Intersect(const TerrainCell& Cell, const CV_BSphere& BSphere);

	static const bool Intersect(const TerrainCell& Cell, const CV_OBB& OBB);

	static const bool Intersect(const TerrainCell& Cell, const CV_AABB& AABB);

#pragma endregion

	static const TerrainCell& GetTerrainCellByPosition(const TerrainModel& Terrain, const float cellwidth, const float x, const float z);

	/// Sets the Initial Min/Max for an AABB
	///  
	/// Given two random points, this function finds the smalles and 
	/// largest vaules and seperates them out into their own 
	/// respective variables
	/// 
	/// @param min Can be any random point, but will always return 
	/// the smallest values in the pair
	/// @param max Can be any random point, but will always return 
	/// the largest values in the pair
	static void SetMinMax(Vect& min, Vect& max);

	/// Checks a Point For Any Mins/Maxes
	/// 
	/// Checks a Point To See If It Contains Points Smaller than the 
	/// current min/max.
	/// 
	/// @param vert The vertex to check
	/// @param min The current min
	/// @param max The current max
	static void CheckMinMax(const Vect& vert, Vect& min, Vect& max);

	static void CalculateBarycentricCord(float& height, Vect& normal, const TerrainCell& Cell, const Vect& P, const float CellWidth);

	// static float LightDistanceToPoint(const MOABEPointLight& pLight, const Vect& Point);
	// static float LightDistanceToPointSqr(const MOABEPointLight& pLight, const Vect& Point);
	// 
	// static float LightDistanceToPoint(const MOABESpotLight& pLight, const Vect& Point);
	// static float LightDistanceToPointSqr(const MOABESpotLight& pLight, const Vect& Point);
	// 
	// static const bool PointInCone(const Vect& TestPoint, const Vect& ConePoint, const Vect& Direction, const float ConeRange, const float ConeAngle);
	// static const bool PointInConePrecomputedDist(const Vect& TestPoint, const Vect& ConePoint, const Vect& Direction, const float ConeAngle, const float Distance);
};

#endif // ENGINEMATH_H
