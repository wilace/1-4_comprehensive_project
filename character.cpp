#include "character.hpp"

#include "battle.hpp"

namespace battle {

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