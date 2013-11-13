#pragma once
#include "gamebase.h"
#include "WorldManager.h"
#include "Camera.h"

class Editor : public GameBase{
private:
	int m_selTile;
	DWORD curTime, elasTime, fpsa, fpsc, fpsl;

	SDL_Rect m_place, m_tile, m_cam;
	Camera* m_mCam;
	bool click;
	float m_brushSize;
public:
	Editor(void);
	~Editor(void);

	void fps();

	WorldData *world;
	
	void redrawTile(int x, int y, int tile);
	void brush();

	void setup();
	void start();
	void logic();
	void draw();

	void onMousePressed();
	void onMouseMoved();
	void onMouseReleased();
	void onKeyPressed();
	void onKeyReleased();
};