#pragma once
#include "gamebase.h"
#include "WorldManager.h"
#include "ItemDesigner.h"
#include "Camera.h"

class Chunk;

class Game :public GameBase{
	WorldData* world;
	ItemDesigner* designer;
	Armor* myItem;
	Chunk* loadedChunks;
	Chunk* curChunk;

	Camera* cam;

	AWSprite* player;

public:
	Game(void);
	~Game(void);

	void setup();
	void start();
	void logic();
	void draw();

	void collision();

	void onKeyPressed();
	void onKeyReleased();
};

