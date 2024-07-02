#ifndef UPDATEABLEREGCMD_H
#define UPDATEABLEREGCMD_H

#include "RegistrationCommand.h"

class Updatable;

/// Registration command for registering an Updatable object.
///
/// This class encapsulates the registration of an Updatable object.
/// 
/// @note This class is for internal use only
class UpdatableRegCmd : public RegistrationCommand
{
public:
	/// Default Constructor
	UpdatableRegCmd() = delete;
	/// Copy Constructor
	UpdatableRegCmd(const UpdatableRegCmd& other) = delete;
	/// Assignment Operator
	UpdatableRegCmd& operator=(const UpdatableRegCmd& other) = delete;
	/// Move Constructor
	UpdatableRegCmd(UpdatableRegCmd&& other) = delete;
	/// Move Assigment
	UpdatableRegCmd& operator=(UpdatableRegCmd&& other) = delete;
	/// Destructor
	~UpdatableRegCmd() = default;

	/// Constructs an UpdatableRegCmd object.
	///
	/// @param _pUpdatable Pointer to the Updatable object to register.
	UpdatableRegCmd(Updatable* _pUpdatable);

	/// Executes the registration command.
	virtual void Execute() const override;

private:
	Updatable* pUpdatable;
};

#endif // UPDATEABLEREGCMD_H
