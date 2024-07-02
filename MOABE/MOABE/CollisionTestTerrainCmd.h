#ifndef COLLISIONTESTTERRAINRCMD_H
#define COLLISIONTESTTERRAINRCMD_H

#include "CollisionTestCommand.h"
#include "CollidableGroup.h"

class CollisionDispatchProxy;

/// Collision test command for testing collision between two collidable groups.
class CollisionTestTerrainCmd : public CollisionTestCommand
{
public:
	/// Constructor is deleted to prevent instantiation without required parameters
	CollisionTestTerrainCmd() = delete;
	/// Copy constructor is deleted to prevent unintended copying
	CollisionTestTerrainCmd(const CollisionTestTerrainCmd& other) = delete;
	/// Copy assignment operator is deleted to prevent unintended copying
	CollisionTestTerrainCmd& operator=(const CollisionTestTerrainCmd& other) = delete;
	/// Move constructor is deleted to prevent unintended moves
	CollisionTestTerrainCmd(CollisionTestTerrainCmd&& other) = delete;
	/// Move assignment operator is deleted to prevent unintended moves
	CollisionTestTerrainCmd& operator=(CollisionTestTerrainCmd&& other) = delete;
	/// Destructor
	virtual ~CollisionTestTerrainCmd();

	/// Constructor to initialize collision test Terrain command with required parameters.
	/// 
	/// @param _pDispatch Pointer to the collision dispatch proxy
	/// @param _colGroup1 First collidable group
	/// @param _colGroup2 Second collidable group
	CollisionTestTerrainCmd(CollisionDispatchProxy* _pDispatch, CollidableGroup& _colGroup);

	/// Execute the collision test command
	virtual void Execute() const override;

private:
	CollisionDispatchProxy* pDispatch; ///< Pointer to the collision dispatch proxy
	CollidableGroup& colGroup; ///< First collidable group
};

#endif // COLLISIONTESTTerrainCMD_H
