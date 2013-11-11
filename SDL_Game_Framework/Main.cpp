#include "ScreenManager.h"

int main(int argc, char* argv[]){
        GameBase::initSDL(1280, 720);
		cout << "SDL init" << endl;
        ScreenManager* myManager = new ScreenManager();

        delete myManager;

        return 0;
}