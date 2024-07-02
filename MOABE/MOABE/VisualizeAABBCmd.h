#ifndef VISUALIZEAABBCMD_H
#define VISUALIZEAABBCMD_H

#include "VisualizeCommand.h"
#include <Vect.h>

class GraphicsObject_Wireframe;
class CV_AABB;

class VisualizeAABBCmd : public VisualizeCommand
{
public:
	VisualizeAABBCmd() = delete;
	VisualizeAABBCmd(const VisualizeAABBCmd& other) = default;
	VisualizeAABBCmd& operator=(const VisualizeAABBCmd& other) = default;
	VisualizeAABBCmd(VisualizeAABBCmd&& other) = default;
	VisualizeAABBCmd& operator=(VisualizeAABBCmd&& other) = default;
	~VisualizeAABBCmd() = default;

	VisualizeAABBCmd(GraphicsObject_Wireframe& _UnitBox);

	void SetData(const CV_AABB* _AABB, const Vect& _Color);

	virtual void Execute() const override;
	virtual void Return() override;

private:
	GraphicsObject_Wireframe& UnitBox;
	const CV_AABB* AABB;
	Vect Color;
};

#endif // VISUALIZEAABBCMD_H
