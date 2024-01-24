#include "Player.h"

#include <iostream>
#include <memory>

#include "ConsolePrinter.h"
#include "InputOutputHelper.h"
#include "ITurnCardActionHandler.h"

bool Player::CanYellUno() const
{
    return hand_.size() == 2;
}

void Player::PlayCard(const int card_id, ITurnCardActionHandler* turn_handler)
{
    Card& chosen_card = *hand_[card_id];
    turn_handler->HandleSetNewTurnColor(chosen_card.GetColor(), false);
    chosen_card.InvokeAction(turn_handler);
    turn_handler->HandleDiscardCardToPile(RemoveCardFromHand(card_id));
    turn_handler->HandleMoveToNextPlayer(*this);
}

Player::Player(const std::string name) : name_(name)
{}

void Player::AddCardToHand(std::unique_ptr<Card> card)
{
    hand_.push_back(std::move(card));
    yelled_uno_ = false;
}

void Player::PrintHand() const
{
    for (int i = 0; i < GetHandSize(); i++)
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
    return static_cast<int>(hand_.size());
}

bool Player::HandIsEmpty() const
{
    return hand_.empty();
}

bool Player::HasYelledUno() const
{
    return yelled_uno_;
}

void Player::ChooseAction(ITurnCardActionHandler* turn_handler)
{
    bool action_validated = false;
    while (!action_validated)
    {
        int action_id = -1;
        while (!InputOutputHelper::InputNumberInRange(0, GetHandSize()-1, action_id))
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

void Player::ClearConsole(ITurnCardActionHandler* turn_handler)
{
    ConsolePrinter::ClearConsole();
    ChooseAction(turn_handler);
}

void Player::DrawCard(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawCardForCurrentPlayer(1);
    turn_handler->HandleMoveToNextPlayer(*this);
}

void Player::YellUno(ITurnCardActionHandler* turn_handler)
{
    if (CanYellUno())
    {
        ConsolePrinter::ShowMessage(name_ + " has yelled UNO!");
        yelled_uno_ = true;
    }
    else
    {
        ConsolePrinter::ShowMessage("You don't meet the requirements to yell UNO yet");
    }
    ChooseAction(turn_handler);
}
