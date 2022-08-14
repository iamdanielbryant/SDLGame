#include "Window.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>

bool Window::init() {
	bool success = true;
	window = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDLError("SDL couldn't initialize. ");
		success = false;
	}
	else {
		window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			SDLError("Window could not be created!");
			success = false;
		}
		else {
			success = true;
		}
	}
	return success;
}

//returns a SDL_Event reference to the Window classm's SDL_Event object.
 SDL_Event& Window::getSDLEvents() {
	return e;
}


SDL_Window* Window::getWindow() {
	return window;
}
