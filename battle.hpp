#if not defined(DEFINED_BATTLE)

#define DEFINED_BATTLE
namespace battle {
class Character;

inline auto IsDead(int hp) -> bool {
    return hp == 0;
}

enum class BattleLevel {
    kNone = -1,
    kNormal = 1,
    kHard = 2,
};

enum class BattleCommand {
    kAttack = 1,
    kDefense = 2,
    kHeal = 3,
};

enum class TurnOfStrongAttack {
    kNone = -1,
    kNormal = 3,
    kHard = 2,
};

const int kDamageMultiplier = 1;
const int kStrongDamageMultiplier = 2;
const int kHealAmount = 30;

auto Battle(Character& hero, Character& enemy, BattleLevel level) -> void;

} // namespace battle

#endif