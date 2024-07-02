#ifndef UPDATABLEDEREGCMD_H
#define UPDATABLEDEREGCMD_H

#include "RegistrationCommand.h"

class Updatable;

/// Registration command for deregistering an Updatable object.
///
/// This class encapsulates the deregistration of an Updatable object.
/// 
/// @note This class is for internal use only
class UpdatableDeRegCmd : public RegistrationCommand
{
public:
	/// Default Constructor
	UpdatableDeRegCmd() = delete;
	/// Copy Constructor
	UpdatableDeRegCmd(const UpdatableDeRegCmd& other) = delete;
	/// Assignment Operator
	UpdatableDeRegCmd& operator=(const UpdatableDeRegCmd& other) = delete;
	/// Move Constructor
	UpdatableDeRegCmd(UpdatableDeRegCmd&& other) = delete;
	/// Move Assigment
	UpdatableDeRegCmd& operator=(UpdatableDeRegCmd&& other) = delete;
	/// Destructor
	~UpdatableDeRegCmd() = default;

	/// Constructs an UpdatableDeRegCmd object.
	///
	/// @param _pUpdatable Pointer to the Updatable object to deregister.
	UpdatableDeRegCmd(Updatable* _pUpdatable);

	/// Executes the deregistration command.
	virtual void Execute() const override;

private:
	Updatable* pUpdatable;
};

#endif // UPDATABLEDEREGCMD_H
