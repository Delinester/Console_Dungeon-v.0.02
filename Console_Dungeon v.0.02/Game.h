#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	enum class FirstAttack {
		ENEMY,
		PLAYER,
	};
	
public:
	Player player;
	std::string gameVersion = "Console Dungeon v 0.03\nChangelog:\n1.Added room drawing\n";
	int roomNum = 0;
public:
	//Создание персонажа, выбор имени и оружия
	void createCharacter();
	//Спавн монстра с предварительным его описанием
	void monsterSpawn();
	void enemyBattle(Enemy& enemy);
	void gameOver(Enemy enemy);
	//Генерация случайной комнаты
	

	
};

