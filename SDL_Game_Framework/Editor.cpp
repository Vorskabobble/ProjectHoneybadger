#include "Editor.h"

Editor::Editor(void)
{
	m_selTile = 1;

	m_cam.x = m_cam.y = 0;
	m_cam.w = screen->w;
	m_cam.h = screen->h;

	m_cUp = m_cDown = m_cLeft = m_cRight = click = false;

	m_brushSize = 2;

	setup();
	start();
}

Editor::~Editor(void)
{
	delete world;
}

void Editor::setup(){
	world = WorldManager::loadWorld(0);
//	WorldManager::newWorld(2);

	m_tile.x = m_tile.y = m_place.x = m_place.y = 0;
	m_tile.w = m_tile.h = m_place.w = m_place.h = world->tileSize();
}

void Editor::start(){
	gameover = false;
	while(!gameover) {
		SDL_Delay(10);
		getUserInput();
		logic();
		camera();
		SDL_BlitSurface(world->landscape(), &m_cam, screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void Editor::draw(){
	print(m_brushSize, 10, 10, WHITE);
}

void Editor::redrawTile(int x, int y, int tile){
	m_place.x = x;
	m_place.y = y;

	m_tile.x = world->tileData()[tile].X() * world->tileSize();
	m_tile.y = world->tileData()[tile].Y() * world->tileSize();

	SDL_BlitSurface(world->tileSheet(), &m_tile, world->landscape(), &m_place);
}

void Editor::brush(){
	float t_cX = (pmouseX + m_cam.x)/world->tileSize();
	float t_cY = (pmouseY + m_cam.y)/world->tileSize();
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

void Editor::camera(){
	if(m_cDown && m_cam.y + m_cam.h < world->height() * world->tileSize()){
		m_cam.y += 10;
	}
	else if(m_cUp && m_cam.y >= 0){
		m_cam.y -= 10;
	}
	if(m_cRight  && m_cam.x + m_cam.w < world->width() * world->tileSize()){
		m_cam.x += 10;
	}
	else if(m_cLeft && m_cam.x >=0){
		m_cam.x -= 10;
	}
	if(m_cam.y < 0){
		m_cam.y = 0;
	}
	if(m_cam.x < 0){
		m_cam.x = 0;
	}
	if(m_cam.x + m_cam.w > world->width() * world->tileSize() && m_cam.w < world->width()){
		m_cam.x =  world->width() * world->tileSize() - m_cam.w;
	}
	if(m_cam.y + m_cam.h > world->height() * world->tileSize() && m_cam.h < world->height()){
		m_cam.y = world->height() * world->tileSize() - m_cam.h;
	}
}

void Editor::onMousePressed(){
	if(mouseButton == SDL_BUTTON_LEFT){
		brush();
		click = true;
	}
	if(mouseButton == SDL_BUTTON_RIGHT){
		if(m_selTile == 0){
			m_selTile = 1;
		}
		else{
			m_selTile = 0;
		}

	}
	if(mouseButton == SDL_BUTTON_MIDDLE){
		//delete world;
		//world = WorldManager::newWorld();
		//WorldManager::newLandscape(world, 200, 200);
	}
	if(mouseButton == SDL_BUTTON_WHEELUP){
		m_brushSize++;
	}
	if(mouseButton == SDL_BUTTON_WHEELDOWN){
		if(m_brushSize > 1){
			m_brushSize--;
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
	case SDLK_a: m_cLeft = true; break;
	case SDLK_d: m_cRight = true; break;
	case SDLK_w: m_cUp = true; break;
	case SDLK_s: m_cDown = true; break;
	case SDLK_p: WorldManager::saveWorld(1, world); break;
	default: break;
	}
}

void Editor::onKeyReleased(){
	switch(keyUp){
	case SDLK_a: m_cLeft = false; break;
	case SDLK_d: m_cRight = false; break;
	case SDLK_w: m_cUp = false; break;
	case SDLK_s: m_cDown = false; break;
	case SDLK_b: gameover = true; screenNum = 0; break;
	default: break;
	}
}
