#include "Player.h"


//Игрок наносит удар
int Player::dealDamage() {
	int additionalDamage = static_cast<float>(m_weapon.getBaseDamage()) / 100 * Constants::damagePercentsRange;
	int damage = m_weapon.getBaseDamage() + Random::randomize(-additionalDamage, additionalDamage);
	switch (m_weapon.getType()) {
	case Weapon::WeaponTypes::CROSSBOW:
		if (Random::randomize(m_weapon.getMinHitChance(), m_weapon.getMaxHitChance()) != 1) return 0;
		else return damage;
	case Weapon::WeaponTypes::GREAT_HAMMER:
		if (Random::randomize(m_weapon.getMinHitChance(), m_weapon.getMaxHitChance()) != 1) return 0;
		else return damage;
	case Weapon::WeaponTypes::KNIVES: {
	int additionalKnivesDamage = static_cast<float>(m_weapon.getBaseDamage()) / 100 * Constants::damageKnivesPercentsRange;
	if (Random::randomize(m_weapon.getMinHitChance(), m_weapon.getMaxHitChance()) == 1)
		damage = Random::randomize(m_weapon.getBaseDamage(), m_weapon.getBaseDamage() + additionalKnivesDamage);
	if (Random::randomize(m_weapon.getMinHitChance(), m_weapon.getMaxHitChance()) == 1)
		damage += Random::randomize(m_weapon.getBaseDamage(), m_weapon.getBaseDamage() + additionalKnivesDamage);
	return damage;
	}
	case Weapon::WeaponTypes::SWORD:
		return damage;
	}
}