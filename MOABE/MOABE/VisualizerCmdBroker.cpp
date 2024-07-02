#include "VisualizerCmdBroker.h"
#include "VisualizeCommand.h"
#include "Visualizer.h"

VisualizerCmdBroker::VisualizerCmdBroker() :
	cmdList()
{
}

VisualizerCmdBroker::~VisualizerCmdBroker()
{
	while (!this->cmdList.empty()) {
		delete this->cmdList.top();
		this->cmdList.pop();
	}
}

void VisualizerCmdBroker::PushCommand(VisualizeCommand* pCmd)
{
	this->cmdList.push(pCmd);
}

void VisualizerCmdBroker::ProcessCommands()
{
	while (!this->cmdList.empty()) {
		this->cmdList.top()->Execute();
		this->cmdList.top()->Return();
		this->cmdList.pop();
	}
}
