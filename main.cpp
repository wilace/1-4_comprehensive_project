#include "battle.hpp"
#include "character.hpp"

auto main() -> int {
    battle::Character hero{"勇者", 100, 18, 5, 3};
    battle::Character dragon{"ドラゴン", 80, 16, 6, 0};

    battle::Battle(hero, dragon);
}