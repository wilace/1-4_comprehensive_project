#if not defined(DEFINED_CHARACTER)

#define DEFINED_CHARACTER
#include <string>
namespace battle {

class Character;

auto CalculateDamage(const Character& attack_side,
                     const Character& defense_side) -> int;

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

    auto GetName() const -> std::string {
        return kName;
    }

    auto GetMaxHp() const -> int {
        return this->kMaxHp;
    }

    auto GetIsGuard() const -> bool {
        return this->is_guard;
    };
    auto SetIsGuard(bool is_guard) -> void {
        this->is_guard = is_guard;
    }

    auto GetHealsLeft() const -> int {
        return this->heals_left;
    }

    auto GetHp() const -> int {
        return this->hp;
    }
    auto SetHp(int hp) -> void {
        this->hp = hp;
    }

    auto GetIsStrong() const -> bool {
        return this->is_strong;
    }
    auto SetIsStrong(bool is_strong) -> void {
        this->is_strong = is_strong;
    }

    friend auto CalculateDamage(const Character& attack_side,
                                const Character& defense_side) -> int;
};

} // namespace battle

#endif