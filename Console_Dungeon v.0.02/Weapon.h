#pragma once
#include <string>
class Weapon {
public:
	enum class WeaponTypes {
		CROSSBOW = 1,
		KNIVES,
		SWORD,
		GREAT_HAMMER
	};
private:
	std::string m_name;
	WeaponTypes m_type;
	short m_baseDamage;
	short m_maxHitChance;
	short m_minHitChance = 1;
public:
	//������������� ������� ������ �� ����������� ����
	void initialize(WeaponTypes type) {
		m_type = type;
		switch (m_type) {
		case WeaponTypes::CROSSBOW:
			m_name = "�������";
			m_baseDamage = 50;
			m_maxHitChance = 2;
			break;
		case WeaponTypes::KNIVES:
			m_name = "�������";
			m_baseDamage = 15;
			m_maxHitChance = 2;
			m_minHitChance = 1;
			break;
		case WeaponTypes::SWORD:
			m_name = "���";
			m_baseDamage = 15;
			m_maxHitChance = 1;
			break;
		case WeaponTypes::GREAT_HAMMER:
			m_name = "������������ �����";
			m_baseDamage = 120;
			m_maxHitChance = 4;
			break;
		}
	}
	//������� ������
	const std::string& getName() const { return m_name; }
	const WeaponTypes getType() const { return m_type; }
	const int getBaseDamage() const { return m_baseDamage; }
	const int getMinHitChance() const{ return m_minHitChance; }
	const int getMaxHitChance() const{ return m_maxHitChance; }
	//������� ������
	void setMaxHitChance(int maxHitChance) { m_maxHitChance = 1; }
};

