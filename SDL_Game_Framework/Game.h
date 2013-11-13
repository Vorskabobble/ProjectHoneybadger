#pragma once
#include "gamebase.h"
#include "WorldManager.h"
#include "ItemDesigner.h"
<<<<<<< HEAD
#include "Camera.h"

class Chunk;
=======
#include "Player.h"
#include <vector>
>>>>>>> a6820ddf3e3d0ecafa17c55a94d38f9d4c7dd9b1

class Game :public GameBase{
	WorldData* world;
	ItemDesigner* designer;
<<<<<<< HEAD
	Armor* myItem;
	Chunk* loadedChunks;
	Chunk* curChunk;

	Camera* cam;

	AWSprite* player;

=======
	vector<Consumable*> myItem;
	Player* player;
>>>>>>> a6820ddf3e3d0ecafa17c55a94d38f9d4c7dd9b1
public:
	Game(void);
	~Game(void);

	void setup();
	void start();
	void logic();
	void draw();
<<<<<<< HEAD

	void collision();

=======
>>>>>>> a6820ddf3e3d0ecafa17c55a94d38f9d4c7dd9b1
	void onKeyPressed();
	void onKeyReleased();
};

