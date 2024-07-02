#ifndef VISUALIZETERRAINCELLCMD_H
#define VISUALIZETERRAINCELLCMD_H

#include "VisualizeCommand.h"
#include <Vect.h>

class GraphicsObject_Wireframe;

struct TerrainCell;

class VisualizeTerrainCellCmd : public VisualizeCommand
{
public:
	VisualizeTerrainCellCmd() = delete;
	VisualizeTerrainCellCmd(const VisualizeTerrainCellCmd& other) = default;
	VisualizeTerrainCellCmd& operator=(const VisualizeTerrainCellCmd& other) = default;
	VisualizeTerrainCellCmd(VisualizeTerrainCellCmd&& other) = default;
	VisualizeTerrainCellCmd& operator=(VisualizeTerrainCellCmd&& other) = default;
	~VisualizeTerrainCellCmd() = default;

	VisualizeTerrainCellCmd(GraphicsObject_Wireframe& _UnitBox);

	void SetData(const TerrainCell* _pCell, const Vect& _Color);

	virtual void Execute() const override;
	virtual void Return() override;

private:
	GraphicsObject_Wireframe& UnitBox;
	const TerrainCell* pCell;
	Vect Color;
};

#endif // VISUALIZETERRAINCELLCMD_H
