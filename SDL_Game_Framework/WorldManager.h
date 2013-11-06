#pragma once
#include "WorldData.h"

static class WorldManager{
private:
	static Tile* loadTile(int worldID, int tiles);
	static Landscape* loadLandscape(int worldID, int width, int height, int tileSize, Tile tileData[]);
public:
	WorldManager();
	~WorldManager(void);

	static WorldData* load(int worldID);
	static void save(int worldID, WorldData data);
	static void newWorld(int worldID);
};