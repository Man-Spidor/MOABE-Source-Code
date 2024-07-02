#ifndef VOLUMEATTORNEY_H
#define VOLUMEATTORNEY_H

#include "CollisionVolume.h"

struct TerrainCell;

class VolumeAttorney
{
	friend class CV_OBB;
	friend class CV_AABB;
	friend class CV_BSphere;
	friend class Visualizer;
	friend class Collidable;
	friend class EngineMath;

	friend class MOABETerrain;

	friend class CollisionTestSelfCmd;
	friend class CollisionTestPairCmd;
	friend class CollisionTestTerrainCmd;

	static void ComputeData(CollisionVolume* pColVol, Model* ColModel, const Matrix& matrix) { pColVol->ComputeData(ColModel, matrix); };
	
	static const bool IntersectAccept(const CollisionVolume& A, const CollisionVolume& B) { return A.IntersectAccept(B); };
	static const bool IntersectVisit(const CollisionVolume& A, const CV_BSphere& other) { return A.IntersectVisit(other); };
	static const bool IntersectVisit(const CollisionVolume& A, const CV_AABB& other) { return A.IntersectVisit(other); };
	static const bool IntersectVisit(const CollisionVolume& A, const CV_OBB& other) { return A.IntersectVisit(other); };
	static const bool IntersectVisit(const CollisionVolume& A, const TerrainCell& other) { return A.IntersectVisit(other); };
	
	static void debug(const CollisionVolume& ColVol) { ColVol.debug(); };
	static void debug(const CollisionVolume& ColVol, const Vect& color) { ColVol.debug(color); };
};

#endif // VOLUMEATTORNEY_H