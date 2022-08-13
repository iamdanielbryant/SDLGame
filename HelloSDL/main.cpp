#include <string>
#include <SDL.h>

#include "Window.h"
#include "Input.h"

Window* mainWindow;
Input* mainInput;

Uint32 startTime = 0;

void arbitraryGameLoop(SDL_Event &e) {
	startTime = SDL_GetTicks();
	printf("%ims  since start time.", startTime);

	if (mainInput->isKeyDown(KEY_SPACE)) {
		printf("Spcae is down!");
	}
}

void createWindow(Window* _window) {
	bool quit = false;

	//sets a local variable to the the reference of e in Window.cpp
	SDL_Event* e = _window->getSDLEvents();
	mainInput->setSDLEvent(*_window->getSDLEvents());

	if (!_window->init()) {
		printf("Failed to initialize\n");
	}
	else {
		if (!_window->loadMedia()) {
			printf("Failed to load media");
		}
		else {
			printf("Loaded media & initialized\n");


			while (!quit) {
				arbitraryGameLoop(*e);
				while (SDL_PollEvent(e) != 0) {
					if (e->type == SDL_QUIT) {
						quit = true;
					}
					
					_window->render();
				}
			}

		}
	}
	_window->close();	
}

int main(int argc, char* args[]) {
	mainWindow = new Window();
	mainInput = new Input;

	printf("The window size is %i x %i\n", mainWindow->SCREEN_WIDTH, mainWindow->SCREEN_HEIGHT);

	createWindow(mainWindow);

	delete(mainWindow);
	delete(mainInput);

	return 0;
}