#pragma once
#include "WorldData.h"

static class WorldManager{
private:
	static Tile* loadTile(int worldID, int tiles);
	static Landscape* loadLandscape(int worldID, int width, int height, int tileSize, Tile tileData[]);

	static void saveTile(int worldID, Tile* tiles, int uniqTiles);
	static void saveLandscape(int worldID, WorldData* data);
public:
	WorldManager();
	~WorldManager(void);

	static WorldData* load(int worldID);
	static void save(int worldID, WorldData* data);

//	static WorldData* newWorld(int worldID);
};