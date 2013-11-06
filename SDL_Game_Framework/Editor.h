#pragma once
#include "gamebase.h"
#include "WorldManager.h"

class Editor : public GameBase{
private:
	int m_selTile;

	SDL_Rect m_place, m_tile, m_cam;
	bool m_cUp, m_cDown, m_cLeft, m_cRight;
public:
	Editor(void);
	~Editor(void);

	WorldData *world;
	void editTile();
	void redrawTile();

	void setup();
	void start();

	void camera();

	void onMousePressed();
	void onKeyPressed();
	void onKeyReleased();
};

