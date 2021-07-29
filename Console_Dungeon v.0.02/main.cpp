#include "Game.h"
#include <cstdlib>

int main() {
	srand(static_cast<unsigned int>(time(0))); 
	rand();
	setlocale(LC_ALL, "Russian");
	Game game;
	game.createCharacter();
	game.createRoom();

	return 0;
}