#include "character.hpp"

#include <algorithm>

auto battle::Character::Healing() -> void {
    this->the_remaining_amount_of_health_point_ += kAmountOfHealing;

    this->the_remaining_amount_of_health_point_ =
        std::min(the_remaining_amount_of_health_point_, this->kMaxHealthPoint);
}

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