#pragma once
#include "Input.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class Game {
public:
	void load();
	void update();
	void render();
	void clean();

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* playerTex;
	SDL_Rect srcRect, destRect;

	static SDL_Event event;

private:
	Input* i;
};
