#include "WorldManager.h"

WorldManager::WorldManager(void)
{
}

WorldManager::~WorldManager(void)
{
}

WorldData* WorldManager::load(int worldID){
	int t_width, t_height, t_uniqTiles, t_tileSize,  t_chunkSize, t_numChunks, t_numZones;
	char s[50];
	sprintf_s(s, "map/world %i/map.dat", worldID);
	std::string worldDir = s;
	std::ifstream data(worldDir);

	data >> t_width;
	data >> t_height;
	data >> t_uniqTiles;
	data >> t_tileSize;
	data >> t_chunkSize;
	data >> t_numChunks;
	data >> t_numZones;

	data.close();

	Tile *t_tiles = loadTile(worldID, t_uniqTiles);
	Landscape *t_landscape = loadLandscape(worldID, t_width, t_height, t_tileSize, t_tiles);
	//zones
	//chunks

	WorldData *world = new WorldData(t_width, t_height, t_uniqTiles, t_tileSize, t_chunkSize, t_numChunks, t_numZones, t_landscape->tiles(), t_tiles, t_landscape->landscape(), t_landscape->tileSheet());

	return world;
}

Tile* WorldManager::loadTile(int worldID, int tiles){
	int t_X, t_Y, t_tileID, t_biomeID;
	float t_colourFade;
	bool t_canWeather, t_solid;

	Tile *t_tiles = new Tile[tiles];
	
	char s[50];
	sprintf_s(s, "map/world %i/tile.dat", worldID);
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
	sprintf_s(s, "map/world %i/map.map", worldID);
	std::string worldDir = s;
	std::ifstream data(worldDir);

	int *tiles = new int[width * height];
	for(int i = 0; i < width * height; i++){
		data >> tiles[i];
	}
	data.close();

	char t[50];
	sprintf_s(t, "map/world %i/tileSheet.png", worldID);

	SDL_Surface* t_tileSheet = IMG_Load(t);
	Landscape *t_landscape = new Landscape(width, height, tileSize, tiles, tileData, t_tileSheet);
	return t_landscape;
}

void WorldManager::save(int worldID, WorldData* data){
	char s[50];
	sprintf_s(s, "map/world %i/map.dat", worldID);
	std::string worldDir = s;
	std::ofstream file(worldDir);

	file << data->width() << std::endl;
	file << data->height() << std::endl;
	file << data->uniqTiles() << std::endl;
	file << data->tileSize() << std::endl;
	file << data->chunkSize() << std::endl;
	file << data->numChunks() << std::endl;
	file << data->numZones() << std::endl;

	file.close();

	saveTile(worldID, data->tileData(), data->uniqTiles());
	saveLandscape(worldID, data);
	std::cout << "save complete" << std::endl;
}

void WorldManager::saveTile(int worldID, Tile* tiles, int uniqTiles){
	char s[50];
	sprintf_s(s, "map/world %i/tile.dat", worldID);
	std::string worldDir = s;
	std::ofstream data(worldDir);

	for(int i = 0; i < uniqTiles; i++){
		data << tiles[i].X() << " ";
		data << tiles[i].Y() << " ";
		data << tiles[i].tileID() << " ";
		data << tiles[i].biomeID() << " ";
		data << tiles[i].colourFade() << " ";
		data << tiles[i].Weather() << " ";
		data << tiles[i].solid() << " ";
		data << std::endl;
	}

	data.close();
}

void WorldManager::saveLandscape(int worldID, WorldData* data){
	char s[50];
	sprintf_s(s, "map/world %i/map.map", worldID);
	std::string worldDir = s;
	std::ofstream file(worldDir);

	int t_width = 0;
	for(int i = 0; i < data->width() * data->height(); i++){
		if(t_width >= data->width()){
			t_width = 0;
			file << std::endl;
		}
		if(data->tiles()[i] < 10){
			file << 0;
		}
		file << data->tiles()[i] << " ";
		t_width++;
	}
}

//WorldData* WorldManager::newWorld(int worldID){
//	char s[50];
//	sprintf_s(s, "map/world %i/map.dat", worldID);
//	std::string worldDir = s;
//	std::ifstream data(worldDir);
//	if(data){
//		std::cout << "file exists" << std::endl;
//	}
//}