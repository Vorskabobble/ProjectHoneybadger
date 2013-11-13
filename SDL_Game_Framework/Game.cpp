#include "Game.h"


Game::Game(void){
	bg = NULL;
	setup();
}


Game::~Game(void){
	delete world;
}

void Game::setup(){
	world = WorldManager::loadWorld(2);

	designer = new ItemDesigner;
	myItem = designer->createArmor(25, 14, 4, 16);
	start();
}

void Game::start(){
	gameover = false;
	
	while(!gameover) {
		SDL_Delay(10);
		getUserInput();
		logic();
		SDL_BlitSurface(world->landscape(), NULL, screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void Game::logic(){
	cout << myItem->getName() << endl;
}

void Game::draw(){
}

void Game::onKeyReleased(){
	if(keyUp == SDLK_b){
		screenNum = 0;
		gameover = true;
	}
}