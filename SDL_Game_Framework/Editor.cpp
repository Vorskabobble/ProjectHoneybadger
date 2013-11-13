#include "Editor.h"

Editor::Editor(void)
{
	bg = NULL;
	m_selTile = 1;

	m_mCam = new Camera(0, 0, screen->w, screen->h);
	m_mCam->bound(true, true, true, true);
	m_mCam->xBound(0, 500*64);
	m_mCam->yBound(0, 500*64);

	click = shiftPressed = false;

	m_brushSize = 2;

	curTime = elasTime = fpsa = fpsc = fpsl = 0;

	setup();
	start();
}

Editor::~Editor(void)
{
	delete world;
}

void Editor::fps(){
	fpsc++;
	curTime = timeGetTime();
	elasTime = curTime - fpsl;

	if(elasTime > 1000){
		fpsa = fpsc;
		fpsc = 0;
		fpsl = curTime;
	}

}

void Editor::setup(){
	world = WorldManager::loadWorld(2);
	m_mCam->xBound(0, world->width() * world->tileSize());
	m_mCam->yBound(0, world->height() * world->tileSize());

	m_tile.x = m_tile.y = m_place.x = m_place.y = 0;
	m_tile.w = m_tile.h = m_place.w = m_place.h = world->tileSize();
}

void Editor::start(){
	gameover = false;
	while(!gameover) {
		SDL_Delay(10);
		getUserInput();
		logic();
		SDL_BlitSurface(world->landscape(), &m_mCam->cam(), screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void Editor::logic(){
	fps();
	m_mCam->update();
}

void Editor::draw(){
	print(m_brushSize, 10, 10, WHITE);
	print(m_selTile, 10, 30, WHITE);
	print((int)fpsa, 10, 50, GREEN);
}

void Editor::redrawTile(int x, int y, int tile){
	m_place.x = x;
	m_place.y = y;

	m_tile.x = world->tileData()[tile].X() * world->tileSize();
	m_tile.y = world->tileData()[tile].Y() * world->tileSize();

	SDL_BlitSurface(world->tileSheet(), &m_tile, world->landscape(), &m_place);
}

void Editor::brush(){
	float t_cX = (pmouseX + m_mCam->x())/world->tileSize();
	float t_cY = (pmouseY + m_mCam->y())/world->tileSize();
	float t_X = t_cX - (m_brushSize +1)/2;
	float t_Y = t_cY - (m_brushSize +1)/2;

	double a = 0;
	double b = 0;

	for(int i = 0; i <= m_brushSize; i++){
		for(int j = 0; j <= m_brushSize; j++){
			if(t_X < 0 || t_Y < 0 || t_X >= world->width() || t_Y >= world->height()){
				t_X++;
				continue;
			}

			a = t_X - t_cX;
			b = t_Y - t_cY;

			if(a < 0){
				a = -a;
			}
			if(b < 0){
				b = -b;
			}
			if(m_brushSize/2 > sqrt((a*a)+(b*b))){
				int temp = (int)t_X + ((int)t_Y * world->width());
				world->tiles()[temp] = m_selTile;

				redrawTile((int)t_X * world->tileSize(), (int)t_Y * world->tileSize(), m_selTile);
			}
			t_X++;
		}
		t_X = t_cX - (m_brushSize +1)/2;
		t_Y++;
	}
}

void Editor::onMousePressed(){
	if(mouseButton == SDL_BUTTON_LEFT){
		brush();
		click = true;
	}
	if(mouseButton == SDL_BUTTON_RIGHT){
	}
	if(mouseButton == SDL_BUTTON_MIDDLE){

	}
	if(mouseButton == SDL_BUTTON_WHEELUP){
		if(shiftPressed){
			if(m_selTile < world->uniqTiles() -1){
				m_selTile++;
			}
		}
		else{
			m_brushSize++;
		}
	}
	if(mouseButton == SDL_BUTTON_WHEELDOWN){
		if(shiftPressed){
			if(m_selTile > 0){
				m_selTile--;
			}
		}
		else{
			if(m_brushSize > 1){
				m_brushSize--;
			}
		}
	}
}

void Editor::onMouseMoved(){
	if(click){
		brush();
	}
}

void Editor::onMouseReleased(){
	if(mouseButton == SDL_BUTTON_LEFT){
		click = false;
	}
}

void Editor::onKeyPressed(){
	switch(keyDown){
	case SDLK_a: m_mCam->l(true); break;
	case SDLK_d: m_mCam->r(true); break;
	case SDLK_w: m_mCam->u(true); break;
	case SDLK_s: m_mCam->d(true); break;
	case SDLK_p: WorldManager::saveWorld(2, world); break;
	case SDLK_LSHIFT: shiftPressed = true; break;
	default: break;
	}
}

void Editor::onKeyReleased(){
	switch(keyUp){
	case SDLK_a: m_mCam->l(false); break;
	case SDLK_d: m_mCam->r(false); break;
	case SDLK_w: m_mCam->u(false); break;
	case SDLK_s: m_mCam->d(false); break;
	case SDLK_LSHIFT: shiftPressed = false; break;
	default: break;
	}
}
