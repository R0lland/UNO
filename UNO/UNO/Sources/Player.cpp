#include "Player.h"

#include <iostream>

#include "ConsolePrinter.h"
#include "InputOutputHelper.h"
#include "ITurnCardActionHandler.h"

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

void Player::YellUno()
{
    yelled_uno_ = true;
}

void Player::ChooseCard(ITurnCardActionHandler* turn_handler)
{
    int card_id = -1;
    bool card_validated = false;
    while (!card_validated)
    {
        card_id = -1;
        while (!InputOutputHelper::InputNumberInRange(0, hand_.size()-1, card_id))
        {
            card_id = InputOutputHelper::ForceGetInput<int>(name_ + ", choose one card from your Deck: ");
        }
        card_validated = turn_handler->IsCardValidToPlay(hand_[card_id]);
    }
    turn_handler->HandleSetNewTurnColor(hand_[card_id]->GetColor());
    hand_[card_id]->InvokeAction(turn_handler);
    turn_handler->HandleDiscardCardToPile(RemoveCardFromHand(card_id));
    turn_handler->HandleMoveToNextPlayer();
}

std::unique_ptr<Card> Player::RemoveCardFromHand(const int card_id)
{
    std::unique_ptr<Card> card = std::move(hand_[card_id]);
    hand_.erase(hand_.begin() + card_id);
    return card;
}
