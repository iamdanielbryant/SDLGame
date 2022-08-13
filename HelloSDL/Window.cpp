#include "Window.h"
#include <SDL.h>
#include <string>
#include <stdio.h>

bool Window::init() {

	gWindow = NULL;
	gScreenSurface = NULL;
	gHelloWorld = NULL;
	viewport.x = 0;
	viewport.y = 0;
	viewport.w = SCREEN_WIDTH;
	viewport.h = SCREEN_HEIGHT;

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDLError("SDL couldn't initialize. ");
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			SDLError("Window could not be created!");
			success = false;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

//returns a SDL_Event pointer to the Window class's SDL_Event object.
 SDL_Event* Window::getSDLEvents() {
	return &e;
}

bool Window::loadMedia() {
	bool success = true;

	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL) {
		SDLError("Unable to load image");
		success = false;
	}

	return success;
}

void Window::SDLError(const std::string& errorMessage) {
	printf("%s.\nSDL_Error: %s\n", errorMessage.c_str(), SDL_GetError());
}

void Window::render() {
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
	SDL_RenderSetViewport(gHelloWorld, &viewport);
	SDL_UpdateWindowSurface(gWindow);
}

void Window::close() {
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}