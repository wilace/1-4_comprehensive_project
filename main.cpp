#include "battle.hpp"
#include "character.hpp"

auto main() -> int {
    const std::string hero_name = "勇者";
    const int hero_hp = 100;
    const int hero_attack_power = 18;
    const int hero_defense_power = 5;
    const int hero_heals_left = 3;

    const std::string enemy_name = "ドラゴン";
    const int enemy_hp = 80;
    const int enemy_attack_power = 16;
    const int enemy_defense_power = 6;
    const int enemy_heals_left = 0;

    battle::Character hero{hero_name, hero_hp, hero_attack_power,
                           hero_defense_power, hero_heals_left};
    battle::Character dragon{enemy_name, enemy_hp, enemy_attack_power,
                             enemy_defense_power, enemy_heals_left};

    battle::Battle(hero, dragon);
}