#include "ScreenManager.h"

int main(int argc, char* argv[]){
	GameBase::initSDL(1280, 720);

	GameBase* menu = new ScreenManager();

	menu->setup();

	delete menu;

	return 0;
}