#ifndef COLLISIONTESTBASECOMMAND_H
#define COLLISIONTESTBASECOMMAND_H

/// Base class for collision test commands.
class CollisionTestCommand
{
public:
	/// Default Constructor
	CollisionTestCommand() = default;
	/// Copy Constructor
	CollisionTestCommand(const CollisionTestCommand& other) = default;
	/// Copy Assignment
	CollisionTestCommand& operator=(const CollisionTestCommand& other) = default;
	/// Move Constructor
	CollisionTestCommand(CollisionTestCommand&& other) = default;
	/// Move Assignment
	CollisionTestCommand& operator=(CollisionTestCommand&& other) = default;
	/// Destructor
	virtual ~CollisionTestCommand() = default;

	/// Execute the collision test command
	virtual void Execute() const = 0;

};

#endif // COLLISIONTESTBASECOMMAND_H
