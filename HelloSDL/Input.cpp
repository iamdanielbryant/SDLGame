#include "Input.h"

bool Input::isKeyDown(int key) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == key) {
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

SDL_Event* Input::getEvents(){
	return &e;
}

