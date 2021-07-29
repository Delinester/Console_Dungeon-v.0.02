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
	std::cout << "Вы победили врага " << m_name << std::endl;
	std::cout << "Павший " << m_name << " роняет мешочек с монетами, в котором " << m_dropCoins << " монет" << std::endl;
	system("Pause");
	return m_dropCoins;
}
