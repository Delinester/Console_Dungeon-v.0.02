#pragma once
#include <string>
#include <iostream>
#include "Constants.h"
#include "Random.h"
#include "Weapon.h"
#include "Point2D.h"
class Player {
private:
	//Выдаем рандомное кол-во здоровья от 100 до 150
	int m_health = Random::randomize(100, 150);
	int m_coins = 0;
	std::string m_name;
	Weapon m_weapon;
	Point2D m_position;
public:
	Player() {
		m_position.moveTo(10, 10);
	}
	//Сеттер для имени
	void setName() {
		std::cout << "Назовите своего персонажа (на английском): ";
		std::cin >> m_name;
	}
	//Сеттер для оружия
	void setWeapon(Weapon::WeaponTypes type) {		
		//Инициализируем оружие исходя из его "типа"
		m_weapon.initialize(type);
	}
	//Изменение кол-ва монет персонажа
	void changeCoins(int coins) { m_coins += coins; }; 
	//Изменение кол-ва очков здоровья персонажа
	void changeHealth(int health) { m_health += health; }
	//Далее геттеры
	const std::string& getWeaponName() const { return m_weapon.getName(); }
	const std::string& getPlayerName() const { return m_name; }
	const int getPlayerCoins() const { return m_coins; }
	const int getPlayerHealth() const { return m_health; }
	void setWeaponAccuracy(int maxHitChance) { m_weapon.setMaxHitChance(maxHitChance); }

	void changePlayerXPos(int x) { m_position.changePosByX(x); }
	void changePlayerYPos(int y) { m_position.changePosByY(y); }
	void movePlayerTo(int x, int y) { m_position.moveTo(x, y); }
	int getPlayerXPos() const { return m_position.getX(); }
	int getPlayerYPos() const { return m_position.getY(); }

	bool getInput() {
		std::string input;
		std::cout << "В какую сторону двигаемся?(w, a, s, d) + ENTER\n";
		std::cin >> input;
		if (input == "w") { changePlayerXPos(-1); return true; }
		if (input == "s") { changePlayerXPos(1); return true; }
		if (input == "a") { changePlayerYPos(-1); return true; }
		if (input == "d") { changePlayerYPos(1); return true; }
		return false;
	}
	int dealDamage();
	
};

