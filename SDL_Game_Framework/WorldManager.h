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

	static bool worldExists(int worldID);

	static WorldData* loadWorld(int worldID);
	static bool saveWorld(int worldID, WorldData* data);

	//static WorldData* newWorld();
	//static void newTile(WorldData* world, int X, int Y, int tileID, int biomeID, float colourFade, bool canWeather, bool solid);
	//static void newLandscape(WorldData* world, int width, int height);
};