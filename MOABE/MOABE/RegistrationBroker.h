#ifndef REGISTRATIONBROKER_H
#define REGISTRATIONBROKER_H

#include <list>

class RegistrationCommand;

/// Registration broker for managing registration commands.
///
/// This class manages registration commands and processes them.
/// 
/// @note This class is for internal use only
class RegistrationBroker
{
public:
	RegistrationBroker() = default;
	RegistrationBroker(const RegistrationBroker& other) = default;
	RegistrationBroker& operator=(const RegistrationBroker& other) = default;
	RegistrationBroker(RegistrationBroker&& other) = default;
	RegistrationBroker& operator=(RegistrationBroker&& other) = default;
	~RegistrationBroker() = default;

	/// Adds a registration command to the broker.
	///
	/// @param cmd Pointer to the registration command to add.
	void AddCommand(const RegistrationCommand* cmd);

	/// Processes all registration commands in the broker.
	/// 
	/// Registration Commands processed second in the update loop
	void ProcessCommands();

private:
	using CommandList = std::list<const RegistrationCommand*>;
	CommandList cmdList;
};

#endif // REGISTRATIONBROKER_H
