#include "character.hpp"

#include <algorithm>
#include <iostream>

namespace battle {

auto Attack(const Character& attack_side, Character& defense_side) -> void {
    int damage = CalculateDamage(attack_side, defense_side);

    int hp_amount = defense_side.GetHp() - damage;
    defense_side.SetHp(hp_amount);
}

auto Guard(Character& character) -> void {
    character.SetIsGuard(true);
}

auto Heal(Character& character) -> void {
    int healed = 0;
    if (character.hp + kHealAmount > character.kMaxHp) {
        healed = character.hp + kHealAmount - character.kMaxHp;
        character.hp = character.kMaxHp;
    } else {
        character.hp += kHealAmount;
        healed = kHealAmount;
    }

    std::cout << "HPが" << healed << "回復した！\n";
    --character.heals_left;
}

auto CalculateDamage(const Character& attack_side,
                     const Character& defense_side) -> int {
    int result = 0;

    if (attack_side.is_strong) {
        result += attack_side.kAttackPower * kStrongDamageMultiplier;
    } else {
        result += attack_side.kAttackPower * kDamageMultiplier;
    }

    result -= defense_side.kDefensePower;

    if (defense_side.is_guard) {
        result /= 2;
    }

    return std::max(1, result);
}

} // namespace battle