#pragma once
#include "gamebase.h"
#include "WorldManager.h"

class Editor :
	public GameBase
{
public:
	Editor(void);
	~Editor(void);

	WorldData *world;

	void setup();
	void start();
};

