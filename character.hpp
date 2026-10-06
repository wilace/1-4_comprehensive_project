#ifndef DEFINED_CHARACTER

#define DEFINED_CHARACTER

namespace battle {
const int kAmountOfHealing = 30;
const int kMultiplierOfNormalAttack = 1;
const int kMultiplierOfStrongAttack = 2;

class Character {
    const int kMaxHealthPoint = -1;
    const int kAttackPower = -1;
    const int kDefensePower = -1;

    int the_remaining_amount_of_health_point_ = -1;
    int the_remaining_amount_of_magic_point_ = -1;

    bool is_defense_ = false;
    bool is_strong_attack_ = false;

  public:
    auto Defense() -> void {
        this->is_defense_ = true;
    }
    auto Healing() -> void;

    friend auto CalculateDamage(const Character& attack_side,
                                const Character& defense_side) -> int;
};

} // namespace battle

#endif