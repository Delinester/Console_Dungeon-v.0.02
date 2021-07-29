#pragma once
#include <string>
#include <iostream>
#include "Constants.h"
#include "Random.h"
#include "Weapon.h"
class Player {
private:
	//������ ��������� ���-�� �������� �� 100 �� 150
	int m_health = Random::randomize(100, 150);
	int m_coins = 0;
	std::string m_name;
	Weapon m_weapon;
public:
	Player() {}
	//������ ��� �����
	void setName() {
		std::cout << "�������� ������ ��������� (�� ����������): ";
		std::cin >> m_name;
	}
	//������ ��� ������
	void setWeapon(Weapon::WeaponTypes type) {		
		//�������������� ������ ������ �� ��� "����"
		m_weapon.initialize(type);
	}
	//��������� ���-�� ����� ���������
	void changeCoins(int coins) { m_coins += coins; }; 
	//��������� ���-�� ����� �������� ���������
	void changeHealth(int health) { m_health += health; }
	//����� �������
	const std::string& getWeaponName() const { return m_weapon.getName(); }
	const std::string& getPlayerName() const { return m_name; }
	const int getPlayerCoins() const { return m_coins; }
	const int getPlayerHealth() const { return m_health; }
	void setWeaponAccuracy(int maxHitChance) { m_weapon.setMaxHitChance(maxHitChance); }

	int dealDamage();
};

