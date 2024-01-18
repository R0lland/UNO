#include "Player.h"

#include <iostream>

#include "InputOutputHelper.h"

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

int Player::GetHandSize() const
{
    return hand_.size();
}

void Player::ChooseCard()
{
    int card_id = -1;
    while (!InputOutputHelper::InputNumberInRange(0, hand_.size()-1, card_id))
    {
        card_id = InputOutputHelper::ForceGetInput<int>(name_ + ", choose one card from your Deck: ");
    }
    std::unique_ptr<Card>& card = hand_[card_id];
}
