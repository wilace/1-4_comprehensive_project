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

    auto GetName() const -> std::string {
        return this->kName;
    };

    auto GetMaxHp() const -> int {
        return this->kMaxHp;
    };

    auto GetAttackPower() const -> int {
        return this->kAttackPower;
    };

    auto GetDefensePower() const -> int {
        return this->kDefensePower;
    };

    auto GetHp() const -> int {
        return this->hp;
    };
    auto SetHp(int hp) -> void {
        this->hp = hp;
    };

    auto GetIsGuard() const -> bool {
        return this->is_guard;
    };
    auto SetIsGuard(bool is_guard) -> void {
        this->is_guard = is_guard;
    };

    auto GetIsStrong() const -> bool {
        return this->is_strong;
    };
    auto SetIsStrong(bool is_strong) -> void {
        this->is_strong = is_strong;
    };

    auto GetHealsLeft() const -> int {
        return this->heals_left;
    };
    auto SetHealsLeft(int heals_left) -> void {
        this->heals_left = heals_left;
    };
};

} // namespace battle

#endif