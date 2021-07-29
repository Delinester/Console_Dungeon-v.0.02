#pragma once
#include <string>
#include <iostream>
#include "Random.h"
#include "Constants.h"
class Enemy {
public:
	enum class EnemyTypes {
		SKELETON,
		ZOMBIE,
		SPIDER,
		TROLL,
		GHOST,
		KNIGHT,
		MAX_ENEMY_TYPES,
		TRAP
	};
private:
	int m_health;
	std::string m_name;
	//������������� m_type
	EnemyTypes m_type = static_cast<EnemyTypes>(Random::randomize(0, static_cast<int>(EnemyTypes::MAX_ENEMY_TYPES) - 1));
	int m_baseDamage;
	int m_dropCoins;
public:
	//�������������� ������ ������, ��� ��� m_type ���������
	Enemy(EnemyTypes type) : m_type(type) {
		if (m_type == EnemyTypes::TRAP) m_name = "������ ������";
	}
	Enemy() {
		switch (m_type) {
		case EnemyTypes::SPIDER:
			m_health = 30;
			m_name = "����";
			m_baseDamage = 6;
			m_dropCoins = 8;
			break;
		case EnemyTypes::SKELETON:
			m_health = 40;
			m_name = "������";
			m_baseDamage = 8;
			m_dropCoins = 13;
			break;
		case EnemyTypes::ZOMBIE:
			m_health = 50;
			m_name = "�����";
			m_baseDamage = 10;
			m_dropCoins = 16;
			break;
		case EnemyTypes::TROLL:
			m_health = 60;
			m_name = "������";
			m_baseDamage = 14;
			m_dropCoins = 17;
			break;
		case EnemyTypes::GHOST:
			m_health = 70;
			m_name = "�������";
			m_baseDamage = 16;
			m_dropCoins = 20;
			break;
		case EnemyTypes::KNIGHT:
			m_health = 100;
			m_name = "������";
			m_baseDamage = 20;
			m_dropCoins = 30;
			break;
		}		
		//������ ����� �������� � ��������� �� -30 ��������� �� +30 ��������� � ��������
		m_health += static_cast<float>(m_health) / 100 * Random::randomize(-Constants::healthPercentsRange, Constants::healthPercentsRange);
	}
	//�������
	const EnemyTypes getEnemyType() const { return m_type; }   
	const int getEnemyHealth() const { return m_health; }      
	const std::string& getEnemyName() const { return m_name; } 
	void changeHealth(int damage) { m_health += damage; }
	//���� ������� ����
	int dealDamage();
	//����
	int drop();

};

