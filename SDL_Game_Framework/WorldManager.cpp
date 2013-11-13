#include "WorldManager.h"
using namespace std;

WorldManager::WorldManager(void)
{
}

WorldManager::~WorldManager(void)
{
}

bool WorldManager::worldExists(int worldID){
	char s[50];
	sprintf_s(s, "map/world %i/map.dat", worldID);
	string worldDir = s;
	ifstream data(worldDir);
	if(data){
		data.close();
		return true;
	}
	else{
		data.close();
		return false;
	}
}

WorldData* WorldManager::loadWorld(int worldID, bool small){
	editor = small;
	int t_width, t_height, t_uniqTiles, t_tileSize,  t_chunkSize, t_numChunks, t_numZones;
	char s[50];
	if(editor){
		sprintf_s(s, "map/world %i/editor.dat", worldID);
	}
	else{
		sprintf_s(s, "map/world %i/map.dat", worldID);
	}
	string worldDir = s;
	ifstream data(worldDir);

	if(!data){
		data.close();
		return NULL;
	}

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
	string worldDir = s;
	ifstream data(worldDir);

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
	string worldDir = s;
	ifstream data(worldDir);

	int *tiles = new int[width * height];
	for(int i = 0; i < width * height; i++){
		data >> tiles[i];
	}
	data.close();

	char t[50];
	if(editor){
		sprintf_s(s, "map/world %i/tileSheet.png", worldID);
	}
	else{
		sprintf_s(s, "map/world %i/stileSheet.png", worldID);
	}

	SDL_Surface* t_tileSheet = IMG_Load(t);
	Landscape *t_landscape = new Landscape(width, height, tileSize, tiles, tileData, t_tileSheet);
	return t_landscape;
}

Chunk* WorldManager::loadChunk(int worldID, int x, int y, int cSize, int tSize){
	char s[50];
	sprintf_s(s, "map/world %i/chunks/chunk%i%i.map", worldID, x, y);
	string worldDir = s;
	ifstream data(worldDir);

	Tile* t_tiles;
	for(int i = 0; i < cSize; i++){
		for(int j = 0; j < cSize; j++){
			int solid;
			data >> solid;
			if(solid == 1){
				t_tiles[i] = Tile(cSize * tSize * x * j, cSize * tSize * y * i);
			}
		}
	}
	Chunk* t_chunk = new Chunk(NULL, t_tiles);
}

bool WorldManager::saveWorld(int worldID, WorldData* data){
	if(worldID == 0){
		return false;
	}
	char s[50];
	sprintf_s(s, "map/world %i", worldID);
	if(!chdir(s)){
		mkdir(s);
	}
	sprintf_s(s, "map/world %i/map.dat", worldID);
	string worldDir = s;
	ofstream file(worldDir);

	data->numChunks((data->width() * data->height) / data->chunkSize());

	file << data->width() << endl;
	file << data->height() << endl;
	file << data->uniqTiles() << endl;
	file << data->tileSize() << endl;
	file << data->chunkSize() << endl;
	file << data->numChunks() << endl;
	file << data->numZones() << endl;

	file.close();

	saveTile(worldID, data->tileData(), data->uniqTiles());
	saveLandscape(worldID, data);

	return true;
}

void WorldManager::saveTile(int worldID, Tile* tiles, int uniqTiles){
	char s[50];
	sprintf_s(s, "map/world %i/tile.dat", worldID);
	string worldDir = s;
	ofstream data(worldDir);

	for(int i = 0; i < uniqTiles; i++){
		data << tiles[i].X() << " ";
		data << tiles[i].Y() << " ";
		data << tiles[i].tileID() << " ";
		data << tiles[i].biomeID() << " ";
		data << tiles[i].colourFade() << " ";
		data << tiles[i].Weather() << " ";
		data << tiles[i].solid() << " ";
		data << endl;
	}

	data.close();
}

void WorldManager::saveLandscape(int worldID, WorldData* data){
	char s[50];
	sprintf_s(s, "map/world %i/map.map", worldID);
	string worldDir = s;
	ofstream file(worldDir);

	int t_width = 0;
	for(int i = 0; i < data->width() * data->height(); i++){
		if(t_width >= data->width()){
			t_width = 0;
			file << endl;
		}
		if(data->tiles()[i] < 10){
			file << 0;
		}
		file << data->tiles()[i] << " ";
		t_width++;
	}
}

void WorldManager::saveChunks(int worldID, WorldData* data){
	for(int i = 0; i < data->width() / data->chunkSize(); i++){
		for(int j = 0; j < data->height() / data ->chunkSize(); j++){

		}
	}
}