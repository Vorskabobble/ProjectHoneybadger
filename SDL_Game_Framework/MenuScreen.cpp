#include "MenuScreen.h"


MenuScreen::MenuScreen(void){
        screenNum = 0;
        setup();
}


MenuScreen::~MenuScreen(void){

}

void MenuScreen::setup(){
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

void MenuScreen::start(){
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

void MenuScreen::logic(){
}

void MenuScreen::draw(){
        for(int i = 0; i < 2; i++){
                btn[i]->update_everything();
        }
}

int MenuScreen::getScreenNum(){
        return screenNum;
}

void MenuScreen::onMouseReleased(){
        for(int i = 0; i < 2; i++){
                if(btn[i]->get_x()+btn[i]->get_width() + btn[i]->get_x() > mouseX && btn[i]->get_x() < mouseX && btn[i]->get_y() < mouseY && btn[i]->get_y() + btn[i]->get_height() > mouseY){
                        screenNum = i+1;

                        gameover = true;
                }
        }
}