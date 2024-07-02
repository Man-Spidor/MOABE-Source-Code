#ifndef VISUALIZEOBBCMD_H
#define VISUALIZEOBBCMD_H

#include "VisualizeCommand.h"
#include <Vect.h>

class GraphicsObject_Wireframe;
class CV_OBB;

class VisualizeOBBCmd : public VisualizeCommand
{
public:
	VisualizeOBBCmd() = delete;
	VisualizeOBBCmd(const VisualizeOBBCmd& other) = default;
	VisualizeOBBCmd& operator=(const VisualizeOBBCmd& other) = default;
	VisualizeOBBCmd(VisualizeOBBCmd&& other) = default;
	VisualizeOBBCmd& operator=(VisualizeOBBCmd&& other) = default;
	~VisualizeOBBCmd() = default;

	VisualizeOBBCmd(GraphicsObject_Wireframe& _UnitBox);
	
	void SetData(const CV_OBB* _OBB, const Vect& _Color);

	virtual void Execute() const override;
	virtual void Return() override;

private:
	GraphicsObject_Wireframe& UnitBox;
	const CV_OBB* OBB;
	Vect Color;
};

#endif // VISUALIZEOBBCMD_H
