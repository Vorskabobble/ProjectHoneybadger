#include "Editor.h"


Editor::Editor(void)
{
	m_selTile = 1;

	m_cam.x = m_cam.y = 0;
	m_cam.w = screen->w;
	m_cam.h = screen->h;

	m_cUp = m_cDown = m_cLeft = m_cRight = click = false;

	m_bRadius = 2;
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
		camera();
		SDL_BlitSurface(world->landscape(), &m_cam, screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void Editor::editTile(){
	int temp;
	temp = ((pmouseX + m_cam.x)/world->tileSize()) + (((pmouseY + m_cam.y)/world->tileSize()) *world->width());
	world->tiles()[temp] = m_selTile;
	redrawTile();
}

void Editor::redrawTile(){
	m_place.x = (((pmouseX + m_cam.x)/world->tileSize()) * world->tileSize());
	m_place.y = (((pmouseY + m_cam.y)/world->tileSize()) * world->tileSize());

	m_tile.x = (world->tileData()[m_selTile].X() * world->tileSize());
	m_tile.y = (m_selTile / (world->tileSheet()->w / world->tileSize())) * world->tileSize();

	SDL_BlitSurface(world->tileSheet(), &m_tile, world->landscape(), &m_place);
}

void Editor::brush(){
	int t_cX = (pmouseX + m_cam.x)/world->tileSize();
	int t_cY = (pmouseY + m_cam.y)/world->tileSize();
	int t_X = t_cX - m_bRadius;
	int t_Y = t_cY - m_bRadius;

	int a = 0;
	int b = 0;

	for(int i = 0; i < (m_bRadius + m_bRadius + 1) * (m_bRadius + m_bRadius + 1); i++){
		if(t_X < t_cX){
			a = t_cX - t_X;
		}
		else{
			a = t_X - t_cX;
		}
		if(t_Y < t_cY){
			b = t_cY - t_Y;
		}
		else{
			b = t_Y - t_cY;
		}
		if(m_bRadius >= sqrt((a * a) + (b * b))){
			int temp = t_X + (t_Y * world->width());
			world->tiles()[temp] = m_selTile;
			m_place.x = t_X * world->tileSize();
			m_place.y = t_Y * world->tileSize();	
			m_tile.x = world->tileData()[m_selTile].X() * world->tileSize();
			m_tile.y = world->tileData()[m_selTile].Y() * world->tileSize();

			SDL_BlitSurface(world->tileSheet(), &m_tile, world->landscape(), &m_place);
		}
		t_X++;
		if(t_X > t_cX + m_bRadius){
			t_X = t_cX - m_bRadius;
			t_Y++;
		}
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
		for(int i = 0; i < world->uniqTiles(); i++){
			cout << world->tileData()[i].tileID() << endl;
		}
	}
	if(mouseButton == SDL_BUTTON_MIDDLE){
		for(int i = 0; i < world->width() * world->height(); i++){
			cout << world->tiles()[i] << " ";
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
	default: break;
	}
}

void Editor::onKeyReleased(){
	switch(keyUp){
	case SDLK_a: m_cLeft = false; break;
	case SDLK_d: m_cRight = false; break;
	case SDLK_w: m_cUp = false; break;
	case SDLK_s: m_cDown = false; break;
	default: break;
	}
}
