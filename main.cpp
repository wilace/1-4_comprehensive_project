#include "battle.hpp"
#include "character.hpp"

#include <ios>
#include <iostream>
#include <limits>

auto main() -> int {
    int level = -1;

    const std::string hero_name = "勇者";
    const int hero_hp = 100;
    const int hero_attack_power = 18;
    const int hero_defense_power = 5;
    const int hero_heals_left = 3;

    const std::string enemy_name = "ドラゴン";
    int enemy_hp = -1;
    int enemy_attack_power = -1;
    int enemy_defense_power = -1;
    const int enemy_heals_left = 0;

    while (true) {
        int input = -1;
        std::cout << "難易度選択 (1:ノーマル 2:ハード) > ";
        std::cin >> input;
        std::cout << "\n";

        if (input != 1 && input != 2) {
            std::cout << "正しい値を入力してください\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (input) {
            case 1:
                level = 1;
                enemy_hp = 80;
                enemy_attack_power = 16;
                enemy_defense_power = 6;
                break;

            case 2:
                level = 2;
                enemy_hp = 120;
                enemy_attack_power = 20;
                enemy_defense_power = 8;
                break;

            default:
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