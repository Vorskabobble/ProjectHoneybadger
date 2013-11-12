#include "Game.h"


Game::Game(void){
	setup();
}


Game::~Game(void){
}

void Game::setup(){
	tempWorld = new WorldManager();
	world = tempWorld->loadWorld(1);

	delete tempWorld;

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
}

void Game::draw(){
}
