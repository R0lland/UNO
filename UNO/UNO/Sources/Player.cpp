#include "Player.h"

#include <iostream>

void Player::AddCardToHand(std::unique_ptr<Card> card)
{
    hand_.push_back(std::move(card));
}

void Player::PrintHand() const
{
    for (int i = 0; i < hand_.size(); i++)
    {
        hand_[i]->Print(i);
    }
}

std::vector<std::unique_ptr<Card>>& Player::GetHand()
{
    return hand_;
}
