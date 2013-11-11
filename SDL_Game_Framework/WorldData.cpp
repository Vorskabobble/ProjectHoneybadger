#include "WorldData.h"

WorldData::WorldData(int width, int height, int uniqTiles, int tileSize, int chunkSize, int numChunks, int numZones, int tiles[], Tile tileData[], SDL_Surface* landscape, SDL_Surface* tileSheet){
	m_width = width;
	m_height = height;
	m_uniqTiles = uniqTiles;
	m_tileSize = tileSize;
	m_chunkSize = chunkSize;
	m_tiles = tiles;
	m_numChunks = numChunks;
	m_numZones = numZones;

	m_tileData = tileData;
	m_landscape = landscape;
	m_tileSheet = tileSheet;
}

WorldData::~WorldData(){
	delete[] m_tiles;
	delete[] m_tileData;
//	delete[] zones;
//	delete[] chunks;
	SDL_FreeSurface(m_landscape);
	SDL_FreeSurface(m_tileSheet);
}

int WorldData::width(){
	return m_width;
}

int WorldData::height(){
	return m_height;
}

int WorldData::uniqTiles(){
	return m_uniqTiles;
}

int WorldData::tileSize(){
	return m_tileSize;
}

int WorldData::chunkSize(){
	return m_chunkSize;
}

int* WorldData::tiles(){
	return m_tiles;
}

int WorldData::numChunks(){
	return m_numChunks;
}

int WorldData::numZones(){
	return m_numZones;
}

SDL_Surface* WorldData::landscape(){
	return m_landscape;
}

SDL_Surface* WorldData::tileSheet(){
	return m_tileSheet;
}

Tile* WorldData::tileData(){
	return m_tileData;
}

void WorldData::newLandscape(SDL_Surface* landscape){
	SDL_FreeSurface(m_landscape);
	m_landscape = landscape;
}