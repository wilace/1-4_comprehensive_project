#include "battle.hpp"
#include "character.hpp"

#include <ios>
#include <iostream>
#include <limits>

auto main() -> int {
    battle::BattleLevel level = battle::BattleLevel::kNone;

    const std::string hero_name = battle::hero_data::kName;
    const int hero_hp = battle::hero_data::kMaxHp;
    const int hero_attack_power = battle::hero_data::kAttackPower;
    const int hero_defense_power = battle::hero_data::kDefensePower;
    const int hero_heals_left = battle::hero_data::kHealsLeft;

    const std::string enemy_name = battle::dragon_data::kName;
    int enemy_hp = -1;
    int enemy_attack_power = -1;
    int enemy_defense_power = -1;
    const int enemy_heals_left = battle::dragon_data::kHealsLeft;

    while (true) {
        int input = -1;
        std::cout << "難易度選択 (1:ノーマル 2:ハード) > ";
        std::cin >> input;
        std::cout << "\n";

        if (input != 1 && input != 2) {
            battle::ClearInput();
            continue;
        }

        level = static_cast<battle::BattleLevel>(input);
        switch (level) {
            case battle::BattleLevel::kNormal:
                enemy_hp = battle::dragon_data::kMaxHpNormal;
                enemy_attack_power = battle::dragon_data::kAttackPowerNormal;
                enemy_defense_power = battle::dragon_data::kDefensePowerNormal;
                break;

            case battle::BattleLevel::kHard:
                enemy_hp = battle::dragon_data::kMaxHpHard;
                enemy_attack_power = battle::dragon_data::kAttackPowerHard;
                enemy_defense_power = battle::dragon_data::kDefensePowerHard;
                break;

            case battle::BattleLevel::kNone:
                continue;
        }
        break;
    }

    battle::Character hero{hero_name, hero_hp, hero_attack_power,
                           hero_defense_power, hero_heals_left};
    battle::Character dragon{enemy_name, enemy_hp, enemy_attack_power,
                             enemy_defense_power, enemy_heals_left};

    battle::Battle(hero, dragon, level);
}

// 3の回答：
// 4の回答：明確な理由はない。そもそも、種類を列挙体として定義するという発想が出なかった。