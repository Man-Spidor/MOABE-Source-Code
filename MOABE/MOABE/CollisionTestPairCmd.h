#ifndef COLLISIONTESTPAIRCMD_H
#define COLLISIONTESTPAIRCMD_H

#include "CollisionTestCommand.h"
#include "CollidableGroup.h"

class CollisionDispatchProxy;

/// Collision test command for testing collision between two collidable groups.
class CollisionTestPairCmd : public CollisionTestCommand
{
public:
	/// Constructor is deleted to prevent instantiation without required parameters
	CollisionTestPairCmd() = delete;
	/// Copy constructor is deleted to prevent unintended copying
	CollisionTestPairCmd(const CollisionTestPairCmd& other) = delete;
	/// Copy assignment operator is deleted to prevent unintended copying
	CollisionTestPairCmd& operator=(const CollisionTestPairCmd& other) = delete;
	/// Move constructor is deleted to prevent unintended moves
	CollisionTestPairCmd(CollisionTestPairCmd&& other) = delete;
	/// Move assignment operator is deleted to prevent unintended moves
	CollisionTestPairCmd& operator=(CollisionTestPairCmd&& other) = delete;
	/// Destructor
	virtual ~CollisionTestPairCmd();

	/// Constructor to initialize collision test pair command with required parameters.
	/// 
	/// @param _pDispatch Pointer to the collision dispatch proxy
	/// @param _colGroup1 First collidable group
	/// @param _colGroup2 Second collidable group
	CollisionTestPairCmd(CollisionDispatchProxy* _pDispatch, CollidableGroup& _colGroup1, CollidableGroup& _colGroup2);

	/// Execute the collision test command
	virtual void Execute() const override;

private:
	CollisionDispatchProxy* pDispatch; ///< Pointer to the collision dispatch proxy
	CollidableGroup& colGroup1; ///< First collidable group
	CollidableGroup& colGroup2; ///< Second collidable group
};

#endif // COLLISIONTESTPAIRCMD_H
