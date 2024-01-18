#include "Player.h"

#include <iostream>

Player::Player(const std::string name) : name_(name)
{ }

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

std::string& Player::GetName()
{
    return name_;
}

std::vector<std::unique_ptr<Card>>& Player::GetHand()
{
    return hand_;
}
