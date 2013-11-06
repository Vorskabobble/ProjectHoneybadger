#pragma once
#include "WorldConst.h"
#include "Landscape.h"

class WorldData{
private:
	int m_width, m_height, m_uniqTiles, m_tileSize, m_chunkSize;
	int *m_tiles;

//temp return type, change when classes have been coded
//	int *zones, *chunks;
	SDL_Surface *m_landscape;
	SDL_Surface *m_tileSheet;
	Tile *m_tileData;

public:
	WorldData(int width, int height, int tileSize, int chunkSize, int tiles[], Tile tileData[], SDL_Surface* landscape, SDL_Surface* tileSheet);
	~WorldData();

	int width();
	int height();
	int uniqTiles();
	int tileSize();
	int chunkSize();
	int* tiles();

	SDL_Surface* landscape();
	SDL_Surface* tileSheet();

	Tile* tileData();
};
