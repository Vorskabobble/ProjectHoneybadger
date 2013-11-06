#pragma once
#include "WorldConst.h"
class Landscape{
private:
	Tile *m_tileData;

	int *m_tiles;

	SDL_Surface *m_landscape;
	SDL_Surface *m_tileSheet;
public:
	Landscape(int width, int height, int tileSize, int tiles[], Tile tileData[], SDL_Surface* tileSheet);
	~Landscape(void);

	void createLandscape(int width, int height, int size);
	int* tiles();
	SDL_Surface* tileSheet();
	SDL_Surface* landscape();
};

