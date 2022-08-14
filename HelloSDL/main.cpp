#include "Game.h"
#include <stdio.h>

Game* game;

int main(int argc, char* args[]) {
	game = new Game();

	game->load();
	game->update();
	game->clean();

	delete(game);

	return 0;
}