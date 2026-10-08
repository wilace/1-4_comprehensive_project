#if not defined(DEFINED_CHARACTER)

#define DEFINED_CHARACTER
namespace battle {

const int kDamageMultiplier = 1;
const int kStrongDamageMultiplier = 2;
const int kHealAmount = 30;

class Character;

auto Attack(const Character& attack_side, Character& defense_side) -> void;
auto Guard(Character& character) -> void;
auto Heal(Character& character) -> void;

auto CalculateDamage(const Character& attack_side,
                     const Character& defense_side) -> int;

class Character {
    const int kMaxHp;
    const int kAttackPower;
    const int kDefensePower;

    int hp;
    int heals_left;

    bool is_guard = false;
    bool is_strong = false;

  public:
    Character();

    friend auto Heal(Character& character) -> void;

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

    friend auto CalculateDamage(const Character& attack_side,
                                const Character& defense_side) -> int;
};

} // namespace battle

#endif