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

	cam = new Camera(0, 0, screen->w, screen->h);
	cam->speed(5);

	curChunk = WorldManager::loadChunk(2, player->get_x() / world->tileSize(), player->get_y() / world->tileSize(), world->chunkSize(), world->chunkSize());

	designer = new ItemDesigner;
	myItem = designer->createArmor(25, 14, 4, 16);
	player = new AWSprite("images/wizard.png", 1);
	player->set_world_position(400, 400);
	player->set_transparent_colour(105, 107, 100);
	start();
}

void Game::start(){
	gameover = false;
	
	while(!gameover) {
		SDL_Delay(10);
		getUserInput();
		logic();
		SDL_BlitSurface(world->landscape(), &cam->cam(), screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void Game::logic(){
//	cout << myItem->getName() << endl;
	cam->update();

	//for(Tile* tile ; IN; curChunk->solidTiles()){
	//	cout << "tile" << endl;
	//}

}

void Game::draw(){
	player->update_everything();
}

void Game::collision(){

}

void Game::onKeyPressed(){
	switch(keyDown){
	case SDLK_a: cam->l(true); player->set_x_velocity(-5); break;
	case SDLK_s: cam->d(true); player->set_y_velocity(5); break;
	case SDLK_w: cam->u(true); player->set_y_velocity(-5); break;
	case SDLK_d: cam->r(true); player->set_x_velocity(5); break;
	}
}

void Game::onKeyReleased(){
	if(keyUp == SDLK_b){
		screenNum = 0;
		gameover = true;
	}
	switch(keyUp){
	case SDLK_a: cam->l(false); player->set_x_velocity(0); break;
	case SDLK_s: cam->d(false); player->set_y_velocity(0); break;
	case SDLK_w: cam->u(false); player->set_y_velocity(0); break;
	case SDLK_d: cam->r(false); player->set_x_velocity(0); break;
	}
}