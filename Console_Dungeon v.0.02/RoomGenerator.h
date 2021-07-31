#pragma once
#include "Random.h"
#include "Weapon.h"
#include "Game.h"
#include <iostream>
#include <vector>

class RoomGenerator {
public:
	enum class FloorItem {
		TRAP,
		TRAP1,
		TREASURE,
		MAX_ITEMS,
	};
	enum class Treasures {
		COINS,
		HEAL_POTION,
		MAX_TREASURES
	};
	enum class Assortment {
		NOTHING,
		GREAT_HAMMER = 100,
		HEAL_POTION = 30,
		RUNE_OF_ACCURACY = 500
	};
private:
	const int minRoomWidth = 10;
	const int minRoomLength = 10;
	const int maxRoomWidth = 60;
	const int maxRoomLength = 30;
	int currentRoomWidth, currentRoomLength;
	int currentMonstersInRoom = 0;
	Game* m_gamePtr;
public:
	RoomGenerator(Game* gameObj = nullptr) : m_gamePtr(gameObj) {

	}
private:
	void treasureFound() {
		Treasures treasure = static_cast<Treasures>(Random::randomize(0, static_cast<int>(Treasures::MAX_TREASURES) - 1));
		std::cout << "�� ���� �� ������, ��� ���-�� ��������. �� ���������� ���������� ������� � ������������ ���...\n";
		switch (treasure) {
		case Treasures::COINS:
			m_gamePtr->player.changeCoins(Random::randomize(10, 25));
			std::cout << "�� ����� ���������! ������ ��� ������ ����� " << m_gamePtr->player.getPlayerCoins() << " �����." << std::endl;
			break;
		case Treasures::HEAL_POTION:
			m_gamePtr->player.changeHealth(Random::randomize(15, 30));
			std::cout << "�� ����� ������� � ����������! ��� ����� �����, �������� ����������� �� "
				<< m_gamePtr->player.getPlayerHealth() << " �����." << std::endl;
			break;
		}
		system("Pause");
	}
	void trapFound() {
		m_gamePtr->player.changeHealth(Random::randomize(-20, -10));
		std::cout << "�� �������� ���������� �� �������� �����.\n";
		std::cout << "������� ������ ������� ����������.\n�������� �� ���� � ����� � ��� ��������� ���-�� ������.\n";
		std::cout << "�� ���������� ���� ����. ��� ����� �������� �������� �� " << m_gamePtr->player.getPlayerHealth() << " �����\n\n";
		if (m_gamePtr->player.getPlayerHealth() <= 0) m_gamePtr->gameOver(Enemy(Enemy::EnemyTypes::TRAP));
		system("Pause");
    }
	void spawnShop() {
		system("CLS");
		static std::vector<Assortment> stock{ Assortment::GREAT_HAMMER, Assortment::HEAL_POTION, Assortment::RUNE_OF_ACCURACY };
		std::cout << "������������ ������� ������ ���������� ������� �� ���.\n�� ���������� ���-������ � ���� ������." << std::endl;
		std::cout << "� ��� " << m_gamePtr->player.getPlayerCoins() << " �����.\n";
		std::cout << "� ���� �� �������� �����: " << std::endl;
		for (int i = 1; i <= stock.size(); i++) {
			std::cout << i << '.';
			if (stock[i - 1] == Assortment::GREAT_HAMMER) std::cout << "������������ �����(100 �����)\n";
			if (stock[i - 1] == Assortment::HEAL_POTION) std::cout << "����� ���������(30 �����)\n";
			if (stock[i - 1] == Assortment::RUNE_OF_ACCURACY) std::cout << "���� ��������(500 �����)\n";
		}
		short choice;
		do {
			std::cout << "\n��� ������ ����������? (������� ����� ������, ���� 0 ��� ������): ";
			std::cin >> choice;
			if (std::cin.fail() || choice > stock.size() || choice < 0) {
				std::cin.clear();
				std::cin.ignore(32000, '\n');
				continue;
			}
			if (static_cast<int>(stock[choice - 1]) > m_gamePtr->player.getPlayerCoins()) {
				std::cout << "\"����� ��������\" - ���������� ������� ������� ������...";
				continue;
			}
			if (stock[choice - 1] == Assortment::GREAT_HAMMER) {
				m_gamePtr->player.changeCoins(-static_cast<int>(stock[choice - 1]));
				m_gamePtr->player.setWeapon(Weapon::WeaponTypes::GREAT_HAMMER);
				std::cout << "������ � ��� � ����� " << m_gamePtr->player.getWeaponName() << std::endl;
				stock.erase(stock.begin() + choice - 1);
				system("Pause");
				break;
			}
			if (stock[choice - 1] == Assortment::HEAL_POTION) {
				m_gamePtr->player.changeCoins(-static_cast<int>(stock[choice - 1]));
				m_gamePtr->player.changeHealth(40);
				std::cout << "�� ����� ����� ��������� � ���������������� 40 ������ ��������."
					<< "������ � ��� " << m_gamePtr->player.getPlayerHealth() << " ����� ��������.\n";
				system("Pause");
				break;
			}
			if (stock[choice - 1] == Assortment::RUNE_OF_ACCURACY) {
				m_gamePtr->player.changeCoins(-static_cast<int>(stock[choice - 1]));
				m_gamePtr->player.setWeaponAccuracy(1);
				std::cout << "�� �������� ���� �������� � ���� ������� ������(" << m_gamePtr->player.getWeaponName() << ")...\n";
				stock.erase(stock.begin() + choice - 1);
				system("Pause");
				break;
			}
		} while (choice != 0);
		createRoom();
	}
public:
	void createRoom() {
		m_gamePtr->roomNum++;
		if (m_gamePtr->roomNum % 2 == 0 && m_gamePtr->roomNum != 1) { spawnShop(); return; }
		int currentRoomLength = Random::randomize(minRoomLength, maxRoomLength);
		int currentRoomWidth = Random::randomize(minRoomWidth, maxRoomWidth);
		std::vector<std::vector<char>> room((currentRoomLength), std::vector<char>(currentRoomWidth));
		for (int x = 0; x < currentRoomLength; x++) {
			for (int y = 0; y < currentRoomWidth; y++) {
				if (x == 0 || x == currentRoomLength - 1) room[x][y] = '-';
				else if (y == 0 || y == currentRoomWidth - 1) room[x][y] = '|';
				else room[x][y] = '.';
			}
		}
		for (int i = 1, itemsAmount = (currentRoomLength + currentRoomWidth) / 3; i <= itemsAmount; i++) {
			int x = Random::randomize(0, currentRoomLength - 1), y = Random::randomize(0, currentRoomWidth - 1);
			if (room[x][y] != '@' && room[x][y] != '|' && room[x][y] != '-' && 
				room[x - 1][y] != '�' && room[x + 1][y] != '�' && room[x][y - 1] != '�' && room[x][y + 1] != '�') room[x][y] = '�';
			else i--;
		}
		for (int i = 1, monstersAmount = (currentRoomLength + currentRoomWidth) / 10; i <= monstersAmount; i++) {
			int x = Random::randomize(0, currentRoomLength - 1), y = Random::randomize(0, currentRoomWidth - 1);
			if (room[x][y] != '@' && room[x][y] != '|' && room[x][y] != '-' && room[x][y] != '�' &&
				room[x - 1][y] != 'E' && room[x + 1][y] != 'E' && room[x][y - 1] != 'E' && room[x][y + 1] != 'E') {
				currentMonstersInRoom++;
				room[x][y] = 'E';
			}
			else i--;
		}
		room[m_gamePtr->player.getPlayerXPos()][m_gamePtr->player.getPlayerYPos()] = '@';
		do {
			system("CLS");
			for (int x = 0; x < currentRoomLength; x++) {
				for (int y = 0; y < currentRoomWidth; y++) {
					std::cout << room[x][y];
				}
				std::cout << std::endl;
			}
			std::cout << "� ����� ������� ���������?\n";
			int tempX = m_gamePtr->player.getPlayerXPos();
			int tempY = m_gamePtr->player.getPlayerYPos();
			if (m_gamePtr->player.getInput() == true && room[m_gamePtr->player.getPlayerXPos()][m_gamePtr->player.getPlayerYPos()] != '|' &&
				room[m_gamePtr->player.getPlayerXPos()][m_gamePtr->player.getPlayerYPos()] != '-') {
				if (room[m_gamePtr->player.getPlayerXPos()][m_gamePtr->player.getPlayerYPos()] == 'E') {
					m_gamePtr->monsterSpawn();
					currentMonstersInRoom--;
				}
				if (room[m_gamePtr->player.getPlayerXPos()][m_gamePtr->player.getPlayerYPos()] == '�') {
					FloorItem item = static_cast<FloorItem>(Random::randomize(0, static_cast<int>(FloorItem::MAX_ITEMS) - 1));
					switch (item) {
					case FloorItem::TRAP:
					case FloorItem::TRAP1: trapFound(); break;
					case FloorItem::TREASURE: treasureFound(); break;
					}
				}
				room[m_gamePtr->player.getPlayerXPos()][m_gamePtr->player.getPlayerYPos()] = '@';
				room[tempX][tempY] = '.';
			}
			else m_gamePtr->player.movePlayerTo(tempX, tempY);
			
		} while (currentMonstersInRoom != 0);	
		createRoom();
	}
};

