#pragma once
#include "gamebase.h"
#include "WorldManager.h"

class Game :public GameBase{
	WorldManager* tempWorld;
	WorldData* world;

public:
	Game(void);
	~Game(void);

	void setup();
	void start();
	void logic();
	void draw();
};

