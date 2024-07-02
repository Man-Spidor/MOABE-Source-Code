#ifndef VISUALIZECOMMAND_H
#define VISUALIZECOMMAND_H

class VisualizeCommand
{
public:
	VisualizeCommand() = default;
	VisualizeCommand(const VisualizeCommand& other) = default;
	VisualizeCommand& operator=(const VisualizeCommand& other) = default;
	VisualizeCommand(VisualizeCommand&& other) = default;
	VisualizeCommand& operator=(VisualizeCommand&& other) = default;
	virtual ~VisualizeCommand() = default;

	virtual void Execute() const = 0;
	virtual void Return() = 0;
};

#endif // VISUALIZECOMMAND_H
