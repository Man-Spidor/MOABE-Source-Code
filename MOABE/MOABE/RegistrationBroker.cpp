#include "RegistrationBroker.h"
#include "RegistrationCommand.h"

void RegistrationBroker::AddCommand(const RegistrationCommand* pCmd)
{
	this->cmdList.push_back(pCmd);
}

void RegistrationBroker::ProcessCommands()
{
	auto pCmdIter = this->cmdList.begin();

	while (!this->cmdList.empty()) {
		this->cmdList.front()->Execute();
		this->cmdList.pop_front();
	}
}
