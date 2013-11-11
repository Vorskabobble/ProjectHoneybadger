#include "ScreenManager.h"

int main(int argc, char* argv[]){
        GameBase::initSDL(1280, 720);
        ScreenManager* myManager = new ScreenManager();

        delete myManager;

        return 0;
}