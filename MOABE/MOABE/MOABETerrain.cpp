#include "MOABETerrain.h"

#include "CV_BSphere.h"

#include "TerrainArea.h"

#include <Vect.h>
#include <Colors.h>
#include <EngineMath.h>
#include <Visualizer.h>
#include <VolumeAttorney.h>
#include <GameObjectAttorney.h>
#include <GraphicsObject_TextureLight.h>
#include <GraphicsObject_Wireframe.h>

MOABETerrain::~MOABETerrain()
{
	delete this->pTerrainArea;
	delete this->pTerrainModel;
	delete this->pTerrainGO;
	delete this->pTerrainGOWF;
}

Model* MOABETerrain::GetModel() const
{
	return this->pTerrainModel;
}

void MOABETerrain::Render()
{
	this->pTerrainGO->Render();
	// this->pTerrainGOWF->Render();
}

void MOABETerrain::SetWorld(const Matrix World)
{
	this->pTerrainGO->SetWorld(World);
	this->pTerrainGOWF->SetWorld(World);
}

void MOABETerrain::SetTexture(Texture* pTexture)
{
	this->pTerrainGO->SetTexture(pTexture);
}

void MOABETerrain::SetMaterial(const Vect& Ambient, const Vect& Diffuse, const Vect& Specular)
{
	this->pTerrainGO->SetMaterial(Ambient, Diffuse, Specular);
}

const TerrainModel* MOABETerrain::GetTerrainModel() const
{
	return this->pTerrainModel;
}

const TerrainArea* MOABETerrain::GetTerrainArea(const Vect& Min, const Vect& Max) const
{
	this->pTerrainArea->SetArea(Min, Max);
	return this->pTerrainArea;
}

const TerrainCell& MOABETerrain::privGetTerrainCell(const float x, const float z)
{
	int side = this->pTerrainModel->GetSideLen();
	side -= 1;

	int i = int(x / this->cellwidth);
	i += side / 2;

	int j = int(z / this->cellwidth);
	j += side / 2;

	if (i >= side)
		i = side - 1;
	else if (i < 0)
		i = 0;

	if (j >= side)
		j = side - 1;
	else if (j < 0)
		j = 0;

	return this->pTerrainModel->GetCellList()[j * side + i];
}

MOABETerrain::MOABETerrain(LPCWSTR heightmapFile, float len, float maxheight, float ytrans, int RepeatU, int RepeatV) :
	pTerrainArea(nullptr),
	pTerrainModel(new TerrainModel(heightmapFile, len, maxheight, ytrans, RepeatU, RepeatV)),
	pTerrainGO(nullptr),
	length(len),
	cellwidth()	
{
	assert(this->pTerrainModel); 

	this->pTerrainGO = new GraphicsObject_TextureLight(this->pTerrainModel);
	this->pTerrainGOWF = new GraphicsObject_Wireframe(this->pTerrainModel);
	this->pTerrainGOWF->SetColor(Colors::Green);
	
	this->cellwidth = this->pTerrainModel->GetCellWidth();

	this->pTerrainArea = new TerrainArea(*this->pTerrainModel);
}
