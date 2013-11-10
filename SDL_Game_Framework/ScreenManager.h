#pragma once
#include "MenuScreen.h"
#include "Editor.h"

enum Screens{MENU, EDITOR, GAME};

class ScreenManager{
<<<<<<< HEAD
        GameBase* curScreen;
        int screenNum;
public:
        ScreenManager(void);
        ~ScreenManager(void);
=======
	GameBase* curScreen;
	int screenNum;
public:
	ScreenManager(void);
	~ScreenManager(void);

	void start();
	void changeScreen();
};
>>>>>>> origin/Master

        void start();
        void changeScreen();
};
