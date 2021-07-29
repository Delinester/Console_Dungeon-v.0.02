#include "Enemy.h"

int Enemy::dealDamage() {
	short isSuccess = Random::randomize(0, 1);
	if (isSuccess == 0) return 0;
	if (isSuccess == 1) {
		short addDamage = ((static_cast<float>(m_baseDamage) / 100) * Constants::damagePercentsRange);
		int damage = m_baseDamage + Random::randomize(-addDamage, addDamage);
		return damage;
		}
}

int Enemy::drop () {
	system("CLS");
	std::cout << "�� �������� ����� " << m_name << std::endl;
	std::cout << "������ " << m_name << " ������ ������� � ��������, � ������� " << m_dropCoins << " �����" << std::endl;
	system("Pause");
	return m_dropCoins;
}
