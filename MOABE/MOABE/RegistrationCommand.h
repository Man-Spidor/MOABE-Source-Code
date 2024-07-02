#ifndef REGISTRATIONCOMMAND_H
#define REGISTRATIONCOMMAND_H

/// Base class for registration commands.
///
/// This class provides an interface for registration commands, which are used to encapsulate registration
/// operations for various game objects.
/// 
/// @note This class is for internal use only
class RegistrationCommand
{
public:
	/// Default Constructor
	RegistrationCommand() = default;
	/// Copy Constructor
	RegistrationCommand(const RegistrationCommand& other) = default;
	/// Assignment Operator
	RegistrationCommand& operator=(const RegistrationCommand& other) = default;
	/// Move Constructor
	RegistrationCommand(RegistrationCommand&& other) = default;
	/// Move Assigment
	RegistrationCommand& operator=(RegistrationCommand&& other) = default;
	/// Destructor
	virtual ~RegistrationCommand() = default;

	/// Executes the registration command.
	virtual void Execute() const = 0;
};

#endif // REGISTRATIONCOMMAND_H
