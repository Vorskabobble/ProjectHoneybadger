#include "WorldManager.h"

WorldManager::WorldManager(void)
{
}


WorldManager::~WorldManager(void)
{
}

Tile* WorldManager::loadTile(int worldID, int tiles){
	int t_X, t_Y, t_tileID, t_biomeID;
	float t_colourFade;
	bool t_canWeather, t_solid;

	Tile *t_tiles = new Tile[tiles];
	
	char s[50];
	sprintf(s, "map/world %i/tile.dat", worldID);
	std::string worldDir = s;
	std::ifstream data(worldDir);

	for(int i = 0; i < tiles; i++){
		data >> t_X;
		data >> t_Y;
		data >> t_tileID;
		data >> t_biomeID;
		data >> t_colourFade;
		data >> t_canWeather;
		data >> t_solid;
		Tile *t_tile = new Tile(t_X, t_Y, t_tileID, t_biomeID, t_colourFade, t_canWeather, t_solid);
		t_tiles[i] = *t_tile;
	}

	data.close();

	Tile *t_tile = new Tile(t_X, t_Y, t_tileID, t_biomeID, t_colourFade, t_canWeather, t_solid);
	return t_tiles;
}

Landscape* WorldManager::loadLandscape(int worldID, int width, int height, int tileSize, Tile tileData[]){
	char s[50];
	sprintf(s, "map/world %i/map.map", worldID);
	std::string worldDir = s;
	std::ifstream data(worldDir);

	int *tiles = new int[width * height];
	for(int i = 0; i < width * height; i++){
		data >> tiles[i];
	}
	data.close();

	char t[50];
	sprintf(t, "map/world %i/tileSheet.png", worldID);

	SDL_Surface* t_tileSheet = IMG_Load(t);
	Landscape *t_landscape = new Landscape(width, height, tileSize, tiles, tileData, t_tileSheet);

	return t_landscape;
}

WorldData* WorldManager::load(int worldID){
	int t_width, t_height, t_tileSize,  t_chunkSize, t_numChunks, t_numZones;
	char s[50];
	sprintf(s, "map/world %i/map.dat", worldID);
	std::string worldDir = s;
	std::ifstream data(worldDir);

	data >> t_width;
	data >> t_height;
	data >> t_tileSize;
	data >> t_chunkSize;
	data >> t_numChunks;
	data >> t_numZones;

	data.close();

	Tile *t_tiles = loadTile(worldID, t_width * t_height);
	Landscape *t_landscape = loadLandscape(worldID, t_width, t_height, t_tileSize, t_tiles);
	//zones
	//chunks

	WorldData *world = new WorldData(t_width, t_height, t_tileSize, t_chunkSize, t_landscape->tiles(), t_tiles, t_landscape->landscape(), t_landscape->tileSheet());

	return world;
}

void WorldManager::save(int worldID, WorldData data){

}
