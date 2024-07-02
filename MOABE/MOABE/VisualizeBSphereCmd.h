#ifndef VISUALIZEBSPHERECMD_H
#define VISUALIZEBSPHERECMD_H

#include "VisualizeCommand.h"
#include "CV_BSphere.h"
#include <GraphicsObject_Wireframe.h>

class VisualizeBSphereCmd : public VisualizeCommand
{
public:
	VisualizeBSphereCmd() = delete;
	VisualizeBSphereCmd(GraphicsObject_Wireframe& _UnitBSphere);
	VisualizeBSphereCmd(const VisualizeBSphereCmd& other) = default;
	VisualizeBSphereCmd& operator=(const VisualizeBSphereCmd& other) = default;
	VisualizeBSphereCmd(VisualizeBSphereCmd&& other) = default;
	VisualizeBSphereCmd& operator=(VisualizeBSphereCmd&& other) = default;
	virtual ~VisualizeBSphereCmd() = default;

	void SetData(const CV_BSphere* _BSphere, const Vect& _Color);

	virtual void Execute() const override;
	virtual void Return() override;

private:
	GraphicsObject_Wireframe& UnitBSphere;
	const CV_BSphere* BSphere;
	Vect Color; 
};

#endif // VISUALIZEBSPHERECMD_H
