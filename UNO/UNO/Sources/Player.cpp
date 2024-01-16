#include "../Header/Player.h"

void Player::AddCardToHand(const std::shared_ptr<Card>& card)
{
    hand_.emplace_back(card);
}

std::vector<std::shared_ptr<Card>>& Player::GetHand()
{
    return hand_;
}
