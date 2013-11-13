#pragma once
#include "gamebase.h"
#include "WorldManager.h"
#include "ItemDesigner.h"
#include "Player.h"
#include <vector>

class Game :public GameBase{
	WorldData* world;
	ItemDesigner* designer;
	vector<Consumable*> myItem;
	Player* player;
public:
	Game(void);
	~Game(void);

	void setup();
	void start();
	void logic();
	void draw();
	void onKeyPressed();
	void onKeyReleased();
};

