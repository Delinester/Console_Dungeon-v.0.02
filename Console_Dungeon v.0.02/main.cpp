#include "Game.h"
#include "RoomGenerator.h"
#include <cstdlib>

int main() {
	srand(static_cast<unsigned int>(time(0))); 
	rand();
	setlocale(LC_ALL, "Russian");
	Game game;
	Game* gameObj = &game;
	RoomGenerator generator(gameObj);

	game.startGame();
	generator.selectSize();
	generator.createRoom();

	return 0;
}