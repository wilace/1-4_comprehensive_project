#include "battle.hpp"

// #include <algorithm>
#include <iostream>
#include <limits>

namespace battle {

auto Battle(Character& hero, Character& enemy) -> void {
    int turn = 1;
    int selected = -1;

    while (true) {
        std::cout << "\n\n=== ターン " << turn << " ===\n";
        std::cout << hero.GetName() << " HP " << hero.GetHp() << "/"
                  << hero.GetMaxHp() << " " << "回復残り "
                  << hero.GetHealsLeft() << "\n"
                  << enemy.GetName() << " HP " << enemy.GetHp() << "/"
                  << enemy.GetMaxHp() << "\n\n";

        if (turn % 3 == 0) {
            enemy.SetIsStrong(true);
        }

        std::cout << "行動 (1:攻撃 2:防御 3:回復) > ";
        std::cin >> selected;

        if (selected != 1 && selected != 2 && selected != 3) {
            std::cout << "コマンドを正しく入力してください\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (static_cast<battle::BattleCommand>(selected)) {
            case battle::BattleCommand::kAttack:
                battle::Attack(hero, enemy);
                break;

            case battle::BattleCommand::kDefense:
                battle::Guard(hero);
                break;

            case battle::BattleCommand::kHeal:
                if (hero.GetHealsLeft() == 0) {
                    std::cout << "MPが足りない！\n";
                    continue;
                }

                battle::Heal(hero);
                break;
        }

        if (enemy.GetHp() == 0) {
            std::cout << enemy.GetName() << "を倒した！！ " << turn
                      << "ターンで勝利\n";
            break;
        }

        battle::Attack(enemy, hero);

        if (hero.GetHp() == 0) {
            std::cout << hero.GetName() << "は倒れた... " << turn
                      << "ターンで敗北\n";
            break;
        }

        if (hero.GetIsGuard()) {
            hero.SetIsGuard(false);
        }

        if (enemy.GetIsStrong()) {
            enemy.SetIsStrong(false);
        }

        ++turn;
    }
}

auto Attack(const Character& attack_side, Character& defense_side) -> void {
    int damage = CalculateDamage(attack_side, defense_side);
    std::cout << attack_side.GetName() << "の攻撃！ " << defense_side.GetName()
              << " に " << damage << " のダメージ\n";

    int hp_amount = defense_side.GetHp() - damage;

    if (hp_amount < 0) {
        defense_side.SetHp(0);
        return;
    }

    defense_side.SetHp(hp_amount);
}

auto Guard(Character& character) -> void {
    std::cout << character.GetName() << " は防御体勢をとった！\n";
    character.SetIsGuard(true);
}

auto Heal(Character& character) -> void {
    int healed = 0;
    if (character.hp + kHealAmount > character.kMaxHp) {
        healed = character.kMaxHp - character.hp;
        character.hp = character.kMaxHp;
    } else {
        character.hp += kHealAmount;
        healed = kHealAmount;
    }

    std::cout << character.GetName() << "のHPが " << healed << " 回復した！\n";
    --character.heals_left;
}

} // namespace battle