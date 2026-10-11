#if not defined(DEFINED_CHARACTER)

#define DEFINED_CHARACTER
#include <string>
namespace battle {

class Character {
    const std::string kName;
    const int kMaxHp;
    const int kAttackPower;
    const int kDefensePower;

    int hp;
    int heals_left;

    bool is_guard = false;
    bool is_strong = false;

  public:
    Character(std::string name, int max_hp, int attack_power, int defense_power,
              int heals_left)
        : kName(name), kMaxHp(max_hp), kAttackPower(attack_power),
          kDefensePower(defense_power), hp(max_hp), heals_left(heals_left) {};

    friend auto Heal(Character& character) -> void;

    auto GetName() const -> std::string;

    auto GetMaxHp() const -> int;

    auto GetIsGuard() const -> bool;
    auto SetIsGuard(bool is_guard) -> void;

    auto GetHealsLeft() const -> int;

    auto GetHp() const -> int;
    auto SetHp(int hp) -> void;

    auto GetIsStrong() const -> bool;
    auto SetIsStrong(bool is_strong) -> void;

    friend auto CalculateDamage(const Character& attack_side,
                                const Character& defense_side) -> int;
};

} // namespace battle

#endif