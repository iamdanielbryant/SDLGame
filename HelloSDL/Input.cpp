#include "Input.h"

bool Input::isKeyDown(int key) {
	if (sdlEvents->type == SDL_KEYDOWN) {
		if (sdlEvents->key.keysym.sym == key) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Input::setSDLEvent(SDL_Event &e) {
	sdlEvents = &e;
}

