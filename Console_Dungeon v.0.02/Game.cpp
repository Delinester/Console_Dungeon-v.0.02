#include "Game.h"


	//�������� ���������, ����� ����� � ������
	void Game::createCharacter() {
		std::cout << gameVersion;
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
		system("CLS");
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
		if (enemy.getEnemyHealth() > 0) {
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
		}
		////////////////////////////////////
		
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
	
	


