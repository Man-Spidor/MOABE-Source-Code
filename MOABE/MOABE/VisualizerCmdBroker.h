#ifndef VISUALIZERCMDBROKER_H
#define VISUALIZERCMDBROKER_H

#include "VisualizeCommand.h"
#include <stack>

class VisualizerCmdBroker
{
public:
	VisualizerCmdBroker();
	VisualizerCmdBroker(const VisualizerCmdBroker& other) = default;
	VisualizerCmdBroker& operator=(const VisualizerCmdBroker& other) = default;
	VisualizerCmdBroker(VisualizerCmdBroker&& other) = default;
	VisualizerCmdBroker& operator=(VisualizerCmdBroker&& other) = default;
	~VisualizerCmdBroker();

	void PushCommand(VisualizeCommand* pCmd);
	void ProcessCommands();

private:
	using CommandList = std::stack<VisualizeCommand*>;
	CommandList cmdList;
};

#endif // VISUALIZERCMDBROKER_H
