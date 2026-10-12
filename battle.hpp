#if not defined(DEFINED_BATTLE)

#define DEFINED_BATTLE
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

auto Battle(Character& hero, Character& enemy) -> void;

} // namespace battle

#endif