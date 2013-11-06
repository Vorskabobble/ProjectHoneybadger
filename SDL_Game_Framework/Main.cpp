#include "Editor.h"

int main(int argc, char* argv[]){
	GameBase::initSDL(1200, 720);

	GameBase* editor = new Editor();

	editor->setup();
	editor->start();

	delete editor;


	return 0;
}