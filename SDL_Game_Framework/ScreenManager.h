#pragma once
#include "gamebase.h"
#include "Editor.h"

class ScreenManager :public GameBase{
	GameBase* m_screen;
	AWSprite* btn[2];
public:
	void setup();
	void start();
	void logic();
	void draw();
	void onMouseReleased();
	void startEditor();
	void startGame();

	ScreenManager(void);
	~ScreenManager(void);
};

