#include "character.hpp"

namespace battle {

auto Character::GetName() const -> std::string {
    return kName;
}

auto Character::GetMaxHp() const -> int {
    return this->kMaxHp;
}

auto Character::GetIsGuard() const -> bool {
    return this->is_guard;
};
auto Character::SetIsGuard(bool is_guard) -> void {
    this->is_guard = is_guard;
}

auto Character::GetHealsLeft() const -> int {
    return this->heals_left;
}

auto Character::GetHp() const -> int {
    return this->hp;
}
auto Character::SetHp(int hp) -> void {
    this->hp = hp;
}

auto Character::GetIsStrong() const -> bool {
    return this->is_strong;
}
auto Character::SetIsStrong(bool is_strong) -> void {
    this->is_strong = is_strong;
}

} // namespace battle