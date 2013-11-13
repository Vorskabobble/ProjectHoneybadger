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

	player = new Player();

	designer = new ItemDesigner;

	for(int i = 0; i<100; i++){
		myItem.push_back(designer->createConsumable(25, rand() % 18, rand() % 10));
		cout << myItem[i]->getName() << endl;
	}

	start();
}

void Game::start(){
	gameover = false;
	
	while(!gameover) {
		SDL_Delay(10);
		getUserInput();
		logic();
		SDL_BlitSurface(world->landscape(), &player->getCam(), screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void Game::logic(){
	player->update();
}

void Game::draw(){
	player->update_everything(player->getCam().x, player->getCam().y);
}

void Game::onKeyPressed(){
	if(keyDown == SDLK_d){
		player->setRight(true);
	}

	if(keyDown == SDLK_s){
		player->setDown(true);
	}

	if(keyDown == SDLK_a){
		player->setLeft(true);
	}

	if(keyDown == SDLK_w){
		player->setUp(true);
	}
}

void Game::onKeyReleased(){
	if(keyUp == SDLK_d){
		player->setRight(false);
	}

	if(keyUp == SDLK_s){
		player->setDown(false);
	}

	if(keyUp == SDLK_a){
		player->setLeft(false);
	}

	if(keyUp == SDLK_w){
		player->setUp(false);
	}

	if(keyUp == SDLK_b){
		screenNum = 0;
		gameover = true;
	}
}