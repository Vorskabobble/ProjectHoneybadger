#include "ScreenManager.h"


ScreenManager::ScreenManager(void){
<<<<<<< HEAD
        curScreen = new MenuScreen();
        start();
=======
	curScreen = new MenuScreen();
	start();
>>>>>>> origin/Master
}


ScreenManager::~ScreenManager(void){
}

void ScreenManager::start(){
<<<<<<< HEAD
        while(curScreen != NULL){
                screenNum = curScreen->getScreenNum();
                changeScreen();
        }
}

void ScreenManager::changeScreen(){
        if(curScreen != NULL){
                delete curScreen;
                curScreen = NULL;
        }

        switch(screenNum){
        case MENU:
                        curScreen = new MenuScreen();
                        break;
        case EDITOR:
                        curScreen = new Editor();
                        break;
        case GAME:
                        break;
        default:
                        break;
        }
}
=======
	while(curScreen != NULL){
		screenNum = curScreen->getScreenNum();
		changeScreen();
	}
}

void  ScreenManager::changeScreen(){
	if(curScreen != NULL){
		delete curScreen;
		curScreen = NULL;
	}

	switch(screenNum){
	case MENU:
			curScreen = new MenuScreen();
			break;
	case EDITOR:
			curScreen = new Editor();
			break;
	case GAME:
			break;
	default:
			break;
	}
}
>>>>>>> origin/Master
