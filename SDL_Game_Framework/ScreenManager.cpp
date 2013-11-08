#include "ScreenManager.h"


ScreenManager::ScreenManager(void){
	m_screen = NULL;
}


ScreenManager::~ScreenManager(void){

}

void ScreenManager::setup(){
	setBackground("images/menu_bg.jpg");
	
	for(int i = 0; i < 2; i++){
		btn[i] = new AWSprite();
	}

	btn[0]->setImage("images/editor_btn.png");
	btn[1]->setImage("images/game_btn.png");

	for(int i = 0; i < 2; i ++){
		btn[i]->set_world_position(screen->w/2-btn[i]->get_width()/2, 100+i*200);
	}

	start();
}

void ScreenManager::start(){
	gameover = false;
	while(!gameover) {
		SDL_Delay(10);
		getUserInput();
		logic();
		SDL_BlitSurface(bg, NULL, screen, NULL);
		draw();
		SDL_Flip(screen);
		post();
	}
}

void ScreenManager::logic(){
}

void ScreenManager::draw(){
	for(int i = 0; i < 2; i++){
		btn[i]->update_everything();
	}
}

void ScreenManager::startEditor(){
	m_screen = new Editor();
	m_screen->setup();
	m_screen->start();

	delete m_screen;
}

void ScreenManager::startGame(){

}

void ScreenManager::onMouseReleased(){
	for(int i = 0; i < 2; i++){
		if(btn[i]->get_x()+btn[i]->get_width() + btn[i]->get_x() > mouseX && btn[i]->get_x() < mouseX && btn[i]->get_y() < mouseY && btn[i]->get_y() + btn[i]->get_height() > mouseY){
			if(i == 0){
				startEditor();
			}

			if(i == 1){
				startGame();
			}

			cout << "clicked" << endl;
		}
	}
}