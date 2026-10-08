#include "character.hpp"

// #include <algorithm>
#include <iostream>

namespace battle {

auto Attack(const Character& attack_side, Character& defense_side) -> void {
    int damage = CalculateDamage(attack_side, defense_side);
    std::cout << attack_side.GetName() << "の攻撃！ " << defense_side.GetName()
              << " に " << damage << " のダメージ\n";

    int hp_amount = defense_side.GetHp() - damage;

    if (hp_amount < 0) {
        defense_side.SetHp(0);
        return;
    }

    defense_side.SetHp(hp_amount);
}

auto Guard(Character& character) -> void {
    character.SetIsGuard(true);
}

auto Heal(Character& character) -> void {
    if (character.heals_left <= 0) {
        std::cout << "MPが足りない！\n";
        return;
    }

    int healed = 0;
    if (character.hp + kHealAmount > character.kMaxHp) {
        healed = character.kMaxHp - character.hp;
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

#if defined(BATTLE_DEBUG)
    std::cout << "攻撃力 - 防御力 = " << result << "\n";
#endif

    if (defense_side.is_guard) {
        result /= 2;
    }

#if defined(BATTLE_DEBUG)
    std::cout << "防御行動を考慮した最終数値: " << result << "\n";
#endif

    if (result < 1) {
#if defined(BATTLE_DEBUG)
        std::cout << "最終数値が1未満なので、1に変換\n";
#endif
        result = 1;
    }

    // return std::max(1, result);

    return result;
}

} // namespace battle