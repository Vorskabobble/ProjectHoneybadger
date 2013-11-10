#pragma once
#include "gamebase.h"
#include "WorldManager.h"

class Editor : public GameBase{
private:
	int m_selTile;

	SDL_Rect m_place, m_tile, m_cam;
	bool m_cUp, m_cDown, m_cLeft, m_cRight;
	bool click;
	float m_brushSize;
public:
	Editor(void);
	~Editor(void);

	WorldData *world;
	
	void redrawTile(int x, int y, int tile);
	void brush();

	void setup();
	void start();
	void draw();

	void camera();

	void onMousePressed();
	void onMouseMoved();
	void onMouseReleased();
	void onKeyPressed();
	void onKeyReleased();
};