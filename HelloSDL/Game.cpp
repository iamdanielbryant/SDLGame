#include "Game.h"
#include <stdio.h>

SDL_Event Game::event;

const int FPS = 60;
const int frameDelay = 1000 / FPS; // time between frames
Uint32 frameStart = 0;
int frameTime;
bool running = true;

void Game::load() {
	i = new Input();


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow("SDLGamek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}
	}
	destRect.h = 32;
	destRect.w = 32;

	SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}


void Game::update() {
	while (running) {
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;


		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				running = false;
			}

			if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_RIGHT) {
					destRect.x -= 1;
				}
			}
		}

		frameTime = SDL_GetTicks() - frameStart;
		
		//important updates here
		

		


		render();

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
void Game::render() {
	SDL_RenderClear(renderer);

	//render here
	SDL_RenderCopy(renderer, playerTex, NULL, &destRect);
	// end render

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	i = NULL;
	delete(i);

	SDL_Quit();
}