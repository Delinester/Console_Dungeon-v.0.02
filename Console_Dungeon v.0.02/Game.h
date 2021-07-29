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
	//�������� ���������, ����� ����� � ������
	void createCharacter();
	//����� ������� � ��������������� ��� ���������
	void monsterSpawn();
	void enemyBattle(Enemy& enemy);
	void gameOver(Enemy enemy);
	//��������� ��������� �������
	void createRoom();
	
};

