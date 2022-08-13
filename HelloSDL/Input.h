#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

enum KEYS {
	KEY_UP = SDLK_UP,
	KEY_DOWN = SDLK_DOWN,
	KEY_LEFT = SDLK_LEFT,
	KEY_RIGHT = SDLK_RIGHT,
	KEY_SPACE = SDLK_SPACE
};

class Input {
public:
	void updateInput();
	bool isKeyDown(int);
	void setSDLEvent(SDL_Event &e);
private:
	SDL_Event* sdlEvents;
};

#endif