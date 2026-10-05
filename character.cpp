#include "character.hpp"

#include <algorithm>

auto battle::CalculateDamage(const Character& attack_side,
                             const Character& defense_side) -> int {
    int damage = 0;

    if (attack_side.is_strong_attack_) {
        damage = attack_side.kAttackPower * kMultiplierOfStrongAttack;
    } else {
        damage = attack_side.kAttackPower * kMultiplierOfNormalAttack;
    }

    damage -= defense_side.kDefensePower;

    if (defense_side.is_defense_) {
        damage /= 2;
    }

    damage = std::max(1, damage);

    return damage;
}