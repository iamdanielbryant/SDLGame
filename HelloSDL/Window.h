#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>


class Window {
public:
	

	bool init();
	void render();
	void SDLError(const std::string&);
	SDL_Event& getSDLEvents();

private:
	SDL_Window* window;
	SDL_Event e;
};

#endif





