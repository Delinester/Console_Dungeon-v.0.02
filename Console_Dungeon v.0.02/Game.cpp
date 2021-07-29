#include "Game.h"


	//�������� ���������, ����� ����� � ������
	void Game::createCharacter() {
		player.setName();
		system("CLS");
		std::cout << player.getPlayerName() << " - �������� �������� �����������, �������� ����������� � �������� � ������ ����������.\n";
		std::cout << "�������, �� ��������� � ��������, ������� ��� �������, �������, ������ ��� ���� ����������,\n";
		std::cout << "������������� � ��������� �����." << std::endl;
		std::cout << "����������� �������� �� �����...\n";
		std::cout << "�� �������� �� ������ �������, ������� � ���\n";
		std::cout << "1 - �������(������� ����. ���� ��������� 30 ���������)\n";
		std::cout << "2 - �������(������ ����. ������� ����. ���� ��������� 50 ��������� ������)\n";
		std::cout << "3 - ���(������ ����. ���� ��������� 100 ���������)\n";
		short weaponNum;
		do {
			std::cout << "����� ������ �������� ����� ������� � �����? ������� ����� ������: \n";
			std::cin >> weaponNum;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32000, '\n');
			}
		} while (weaponNum < 1 || weaponNum > 3);
		player.setWeapon(static_cast<Weapon::WeaponTypes>(weaponNum));
		system("CLS");
		std::cout << "����, " << player.getPlayerName() << ", � ��� � ����� " << player.getWeaponName() <<
			". �� ����� ���, � ��� " << player.getPlayerHealth() << " ����� ��������\n";
		std::cout << "���� ���� � �����, �� ������� � ������ ������...\n\n";
		system("Pause");
	}
	//����� ������� � ��������������� ��� ���������
	void Game::monsterSpawn() {
		Enemy enemy;
		std::cout << "����� ������ �� ��������� ������, �� �������� � �������, �� ������� �������� �������� �����...\n\n";
		switch (enemy.getEnemyType()) {
		case Enemy::EnemyTypes::SPIDER:
			std::cout << "��������� �� ������� �������, �� ��������� ������ ���������. ��� ��� ��� ��� ����� �� ����?\n";
			std::cout << "�� ������� ������ � ����������� ������� ��������.\n";
			std::cout << "� ���! �������� ������������ � ��������� ����� ����� ���. �����������, ��� �������� ����!\n\n";
			break;
		case Enemy::EnemyTypes::SKELETON:
			std::cout << "� ������ �������� ����� ����� ������.\n";
			std::cout << "��� ������ �� � ��� ������������, ������, �������� ��������, ����� ����������� � ���������������� " <<
				"��������.\n";
			std::cout << "� ���, ��� ������! �� �������� ����������!\n\n";
			break;
		case Enemy::EnemyTypes::ZOMBIE:
			std::cout << "�� ����� ���������� ���������� �����, ��-�� �������� ����������� ���������� ������.\n";
			std::cout << "�������� �������, �� ������������ � ��������� ����� ��������. �� �������� �����, ���������� " <<
				"���-�� �������!\n ���������� ���, �� ������� � �������� � ���� �������!\n\n";
			break;
		case Enemy::EnemyTypes::TROLL:
			std::cout << "�� �������� ���� ������� ��������� ����� ������� � ��������������� ����.\n";
			std::cout << "�������� ������������, ��� ������ �������� ����� ����� �� �����, �� ���� ����������� ���������� ����\n";
			std::cout << "�� ��������� � ��������� �����. � ���� ����� ���������� ������� ������� ������, �������� ������� �� " <<
				"������ ������.\n���� ������������ ��������� ���������� ������� �����, ������� ����� ���� �����������...\n\n";
			break;
		case Enemy::EnemyTypes::GHOST:
			std::cout << "�������� ��� ���������� ����� �������, ��� ������� ��� ��� ����� ���. "
				<< "\"��� �����������,\" - �������� ��.\n";
			std::cout << "�������� ����, ������� ���������� ������, ����������� ����� �� ���� �������.\n";
			std::cout << "�� ������ ��������� ������� �����. �����������, �� ������ �������������� �����. ��� �� �������!\n\n";
			break;
		case Enemy::EnemyTypes::KNIGHT:
			std::cout << "���� �������� � ������� ���� ���������� ���� �� ���� �������.\n";
			std::cout << "������� ���������� � ���������, �� ������� ���� ������������ � ���� �������...\n";
			std::cout << "� ��� ������������ ������, ������ � ������ �������! �� ��� ���� ����� �������, ��� �� �������\n";
			std::cout << "�������������, ������� ����� ���� ����� �� �� �����, � �� ������\n\n";
			break;
		}
		enemyBattle(enemy);
		system("Pause");
	}
	//�����
	void Game::enemyBattle(Enemy& enemy) {
		std::cout << enemy.getEnemyName() << " ����� " << enemy.getEnemyHealth() << " ����� ��������.\n";
		std::cout << player.getPlayerName() << " ����� " << player.getPlayerHealth() << " ����� ��������.\n\n";
		system("Pause"); std::cout << std::endl;
		//��� ����� ������
		FirstAttack firstAttack = static_cast<FirstAttack>(Random::randomize(0, 1));
		short gainedDamage;
		switch (firstAttack) {
		case FirstAttack::ENEMY:
			gainedDamage = enemy.dealDamage();
			player.changeHealth(-gainedDamage);
			std::cout << enemy.getEnemyName() << " �������� ������� " << gainedDamage << " ����� ����� " << player.getPlayerName()
				<< std::endl;
			break;
		case FirstAttack::PLAYER:
			gainedDamage = player.dealDamage();
			enemy.changeHealth(-gainedDamage);
			std::cout << "���������� ����������� � �����, �� ����� �������� " << gainedDamage << " �����!" << std::endl;
			break;
		}
		if (enemy.getEnemyHealth() <= 0) player.changeCoins(enemy.drop());
		if (player.getPlayerHealth() <= 0) gameOver(enemy);
		//////////////////////////////////////////////////////////
		//�����
		do {
			std::cout << "-----------------------------------------\n";
			std::cout << "� ����� " << player.getPlayerHealth() << " ����� ��������\n";
			std::cout << "� ����� " << enemy.getEnemyHealth() << " ����� ��������\n";
			std::cout << "-----------------------------------------\n\n";
			system("Pause"); system("CLS");
			int dealDamage = player.dealDamage();
			enemy.changeHealth(-dealDamage);
			std::cout << "����� ��������� " << player.getWeaponName() << ", �� ������� " << dealDamage
				<< " ����� ����� " << enemy.getEnemyName() << std::endl;
			system("Pause");
			std::cout << std::endl;
			if (enemy.getEnemyHealth() <= 0) {
				player.changeCoins(enemy.drop());
				break;
			}
			dealDamage = enemy.dealDamage();
			player.changeHealth(-dealDamage);
			std::cout << enemy.getEnemyName() << " ������� ������������ � ������� " << dealDamage << " ����� ����� "
				<< player.getPlayerName() << std::endl;
			system("Pause");
			std::cout << std::endl;
			if (player.getPlayerHealth() <= 0) gameOver(enemy);
		} while (enemy.getEnemyHealth() > 0);
		////////////////////////////////////
		createRoom();
	}
	//������ ������
	void Game::gameOver(Enemy enemy) {
		system("CLS");
		std::cout << enemy.getEnemyName() << " ���� �������� ����� " << player.getPlayerName() << std::endl;
		std::cout << "� ��� �������� ��������� " << player.getPlayerCoins() << " �����" << std::endl;
		std::cout << "������ � ������� " << roomNum << " ����� ����������� ����..." << std::endl;
		system("Pause"); std::cout << std::endl;
		exit(0);
	}
	//��������� ��������� �������
	void Game::createRoom() {
		roomNum++;
		Rooms room = static_cast<Rooms>(Random::randomize(1, static_cast<int>(Rooms::MAX_ROOMS) - 1));
		if (roomNum >= 10 && roomNum % 10 == 0) room = Rooms::SHOP;
		system("CLS");
		switch (room) {
		case Rooms::MONSTERS:
			monsterSpawn();
		case Rooms::TREASURE:
		{Treasures treasure = static_cast<Treasures>(Random::randomize(0, static_cast<int>(Treasures::MAX_TREASURES) - 1));
		switch (treasure) {
		case Treasures::COINS:
			player.changeCoins(Random::randomize(10, 25));
			std::cout << "�� ������� � ���������� �������, ���������� ������� ����� ������...\n";
			std::cout << "�� ����� ���������! ������ ��� ������ ����� " << player.getPlayerCoins() << std::endl << std::endl;
			system("Pause");
			createRoom();
			break;
		case Treasures::HEAL_POTION:
			player.changeHealth(Random::randomize(15, 30));
			std::cout << "�� ������� � ���������� �������, ���������� ������� ����� ������...\n";
			std::cout << "�� ����� ������� � ����������! ��� ����� �����, �������� ����������� �� "
				<< player.getPlayerHealth() << " �����." << std::endl << std::endl;
			system("Pause");
			createRoom();
			break;
		}
		break;
		}
		case Rooms::TRAP:
			player.changeHealth(Random::randomize(-12, -6));
			std::cout << "����� �� ������� � ����� ���������, �� �������� ���������� �� �������� �����.\n";
			std::cout << "������� ������ ������� ����������.\n�������� �� ���� � ����� � ��� ��������� ���-�� ������.\n";
			std::cout << "�� ���������� ���� ����. ��� ����� �������� �������� �� " << player.getPlayerHealth() << " �����\n\n";
			if (player.getPlayerHealth() <= 0) gameOver(Enemy(Enemy::EnemyTypes::TRAP));
			system("Pause"); std::cout << std::endl;
			createRoom();
			break;
			/////////////////////////////////�������
		case Rooms::SHOP:
			static std::vector<Assortment> stock{ Assortment::GREAT_HAMMER, Assortment::HEAL_POTION, Assortment::RUNE_OF_ACCURACY };
			std::cout << "������������ ������� ������ ���������� ������� �� ���.\n�� ���������� ���-������ � ���� ������." << std::endl;
			std::cout << "� ��� " << player.getPlayerCoins() << " �����.\n";
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
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32000, '\n');
					continue;
				}
				if (static_cast<int>(stock[choice - 1]) > player.getPlayerCoins()) {
					std::cout << "\"����� ��������\" - ���������� ������� ������� ������...";
					continue;
				}
				if (choice == 1) {
					player.changeCoins(-static_cast<int>(stock[choice - 1]));
					player.setWeapon(Weapon::WeaponTypes::GREAT_HAMMER);
					std::cout << "������ � ��� � ����� " << player.getWeaponName() << std::endl;
					stock.erase(stock.begin() + choice - 1);
					system("Pause");
					break;
				}
				if (choice == 2) {
					player.changeCoins(-static_cast<int>(stock[choice - 1]));
					player.changeHealth(40);
					std::cout << "�� ����� ����� ��������� � ���������������� 40 ������ ��������."
						<< "������ � ��� " << player.getPlayerHealth() << " ����� ��������.\n";
					system("Pause");
					break;
				}
				if (choice == 3) {
					player.changeCoins(-static_cast<int>(stock[choice - 1]));
					player.setWeaponAccuracy(1);
					std::cout << "�� �������� ���� �������� � ���� ������� ������...\n";
					stock.erase(stock.begin() + choice - 1);
					system("Pause");
					break;
				}
			} while (choice != 0);
			createRoom();

		}
		////////////////////////////////////////////////////////////////////
	}


