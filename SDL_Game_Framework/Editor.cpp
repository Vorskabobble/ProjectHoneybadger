#include "Editor.h"


Editor::Editor(void)
{
	m_selTile = 1;
}


Editor::~Editor(void)
{
	delete world;
}

void Editor::setup(){
	world = WorldManager::load(1);

	m_tile.w = m_tile.h = m_place.w = m_place.h = world->tileSize();
	m_tile.x = m_tile.y = m_place.x = m_place.y = 0;
}

void Editor::start(){
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

void Editor::editTile(){
	int temp;
	temp = (pmouseX/world->tileSize()) + ((pmouseY /world->tileSize()) *world->width());
	world->tiles()[temp] = m_selTile;
	redrawTile();
}

void Editor::redrawTile(){
	m_place.x = ((pmouseX/world->tileSize()) * world->tileSize());
	m_place.y = ((pmouseY/world->tileSize()) * world->tileSize());

	m_tile.x = (m_selTile % (world->tileSheet()->w / world->tileSize())) * world->tileSize();
	m_tile.y = (m_selTile / (world->tileSheet()->w / world->tileSize())) * world->tileSize();

	SDL_BlitSurface(world->tileSheet(), &m_tile, world->landscape(), &m_place);
}

void Editor::onMousePressed(){
	if(mouseButton = SDL_BUTTON_LEFT){
		editTile();
	}
	if(mouseButton = SDL_BUTTON_MIDDLE){
		for(int i = 0; i < world->uniqTiles(); i++){
			cout << world->tiles()[i] << endl;
		}
	}
}
