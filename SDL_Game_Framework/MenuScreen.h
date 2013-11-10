#pragma once
#include "gamebase.h"
#include "Editor.h"

class MenuScreen :public GameBase{
        AWSprite* btn[2];
        int screenNum;
public:
        void setup();
        void start();
        void logic();
        void draw();
        void onMouseReleased();
        int getScreenNum();

        MenuScreen(void);
        ~MenuScreen(void);
};
