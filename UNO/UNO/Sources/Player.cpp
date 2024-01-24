#include "Player.h"

#include <iostream>
#include <memory>

#include "ConsolePrinter.h"
#include "InputOutputHelper.h"
#include "ITurnCardActionHandler.h"

bool Player::CanYellUno()
{
    return hand_.size() <= 2;
}

void Player::PlayCard(int card_id, ITurnCardActionHandler* turn_handler)
{
    Card& chosen_card = *hand_[card_id];
    turn_handler->HandleSetNewTurnColor(chosen_card.GetColor(), false);
    chosen_card.InvokeAction(turn_handler);
    turn_handler->HandleDiscardCardToPile(RemoveCardFromHand(card_id));
    turn_handler->HandleMoveToNextPlayer();
}

Player::Player(const std::string name) : name_(name)
{}

void Player::AddCardToHand(std::unique_ptr<Card> card)
{
    hand_.push_back(std::move(card));
}

void Player::PrintHand() const
{
    for (int i = 0; i < hand_.size(); i++)
    {
        hand_[i]->Print(i);
        if (i > 0 && i % 8 == 0)
        {
            std::cout << std::endl;
        }
    }
}

std::string& Player::GetName()
{
    return name_;
}

int Player::GetHandSize() const
{
    return hand_.size();
}

bool Player::HasCards() const
{
    return hand_.empty();
}

void Player::ChooseAction(ITurnCardActionHandler* turn_handler)
{
    int action_id = -1;
    bool action_validated = false;
    while (!action_validated)
    {
        action_id = -1;
        while (!InputOutputHelper::InputNumberInRange(0, hand_.size()-1, action_id) || !InputOutputHelper::InputNumberInRange(100, 103, action_id))
        {
            action_id = InputOutputHelper::ForceGetInput<int>(name_ + ", choose one card from your Deck or a special action: ");
        }
        action_validated = turn_handler->IsCardValidToPlay(*hand_[action_id]);
        PlayCard(action_id, turn_handler);
    }
}

std::unique_ptr<Card> Player::RemoveCardFromHand(const int card_id)
{
    std::unique_ptr<Card> card = std::move(hand_[card_id]);
    hand_.erase(hand_.begin() + card_id);
    return card;
}

void Player::ClearConsole()
{
    ConsolePrinter::ClearConsole();
}

void Player::DrawCard(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawCardForCurrentPlayer();
}

void Player::YellUno(ITurnCardActionHandler* turn_handler)
{
    yelled_uno_ = true;
}
