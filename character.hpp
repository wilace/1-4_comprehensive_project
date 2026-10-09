#if not defined(DEFINED_CHARACTER)

#define DEFINED_CHARACTER
#include <string>
namespace battle {

class Character;

enum class BattleCommand {
    kAttack = 1,
    kDefense = 2,
    kHeal = 3,
};

const int kDamageMultiplier = 1;
const int kStrongDamageMultiplier = 2;
const int kHealAmount = 30;

auto Attack(const Character& attack_side, Character& defense_side) -> void;
auto Guard(Character& character) -> void;
auto Heal(Character& character) -> void;

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

    auto SetIsStrong(bool is_strong) -> void {
        this->is_strong = is_strong;
    }

    friend auto CalculateDamage(const Character& attack_side,
                                const Character& defense_side) -> int;
};

} // namespace battle

#endif