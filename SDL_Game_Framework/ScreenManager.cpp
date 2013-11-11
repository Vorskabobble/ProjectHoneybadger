#include "ScreenManager.h"


ScreenManager::ScreenManager(void){
        curScreen = new MenuScreen();
		cout << "Screen manager constructor" << endl;
        start();
}


ScreenManager::~ScreenManager(void){
}

void ScreenManager::start(){
	cout << "screen manager start" << endl;
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