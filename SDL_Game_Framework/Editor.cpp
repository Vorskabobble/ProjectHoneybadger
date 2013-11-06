#include "Editor.h"


Editor::Editor(void)
{
}


Editor::~Editor(void)
{
	delete world;
}

void Editor::setup(){
	world = WorldManager::load(1);
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
