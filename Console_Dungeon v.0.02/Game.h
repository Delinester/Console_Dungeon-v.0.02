#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
class Game {
public:
	enum class Rooms {
		MONSTERS = 1,
		TREASURE,
		TRAP,
		MAX_ROOMS,
		SHOP
	};
	enum class Treasures {
		COINS,
		HEAL_POTION,
		MAX_TREASURES
	};
	enum class Items {
		HEAL_POTION,
		MAX_ITEMS
	};
	enum class FirstAttack {
		ENEMY,
		PLAYER,
	};
	enum class Assortment {
		NOTHING,
		GREAT_HAMMER = 100,
		HEAL_POTION = 30,
		RUNE_OF_ACCURACY = 500
	};
private:
	Player player;
	int roomNum = 0;
public:
	//Создание персонажа, выбор имени и оружия
	void createCharacter();
	//Спавн монстра с предварительным его описанием
	void monsterSpawn();
	void enemyBattle(Enemy& enemy);
	void gameOver(Enemy enemy);
	//Генерация случайной комнаты
	void createRoom();
	
};

