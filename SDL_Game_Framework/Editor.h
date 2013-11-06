#pragma once
#include "gamebase.h"
#include "WorldManager.h"

class Editor : public GameBase{
private:
	int m_selTile;

	SDL_Rect m_place, m_tile;
public:
	Editor(void);
	~Editor(void);

	WorldData *world;
	void editTile();
	void redrawTile();

	void setup();
	void start();

	void onMousePressed();
};

