#pragma once
#include "gamebase.h"
#include "WorldManager.h"
#include "ItemDesigner.h"

class Game :public GameBase{
	WorldData* world;
	ItemDesigner* designer;
	Armor* myItem;

public:
	Game(void);
	~Game(void);

	void setup();
	void start();
	void logic();
	void draw();
	void onKeyReleased();
};

