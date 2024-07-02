#ifndef COLLISIONTESTSELFCMD_H
#define COLLISIONTESTSELFCMD_H

#include "CollisionTestCommand.h"
#include "CollidableGroup.h"

class CollisionDispatchProxy;

/// Collision test command for testing collision within a single collidable group.
class CollisionTestSelfCmd : public CollisionTestCommand
{
public:
	/// Constructor is deleted to prevent instantiation without required parameters
	CollisionTestSelfCmd() = delete;
	/// Copy constructor is deleted to prevent unintended copying
	CollisionTestSelfCmd(const CollisionTestSelfCmd& other) = delete;
	/// Copy assignment operator is deleted to prevent unintended copying
	CollisionTestSelfCmd& operator=(const CollisionTestSelfCmd& other) = delete;
	/// Move constructor is deleted to prevent unintended moves
	CollisionTestSelfCmd(CollisionTestSelfCmd&& other) = delete;
	/// Move assignment operator is deleted to prevent unintended moves
	CollisionTestSelfCmd& operator=(CollisionTestSelfCmd&& other) = delete;
	/// Destructor
	virtual ~CollisionTestSelfCmd();

	/// Constructor to initialize collision test self command with required parameters.
	/// 
	/// @param _pDispatch Pointer to the collision dispatch proxy
	/// @param _colGroup Collidable group for self collision test
	CollisionTestSelfCmd(CollisionDispatchProxy* _pDispatch, CollidableGroup& _colGroup);

	/// Execute the collision test command
	virtual void Execute() const override;

private:
	CollisionDispatchProxy* pDispatch; ///< Pointer to the collision dispatch proxy
	CollidableGroup& colGroup; ///< Collidable group for self collision test
};

#endif // COLLISIONTESTSELFCMD_H
