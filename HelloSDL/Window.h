#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>


class Window {
public:

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	bool init();
	bool loadMedia();
	void close();
	void SDLError(const std::string&);
	void render();
	SDL_Event* getSDLEvents();
	SDL_Rect viewport;

private:
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	SDL_Renderer* gHelloWorld;
	SDL_Event e;
};

#endif





