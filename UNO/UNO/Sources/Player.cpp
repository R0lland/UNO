﻿#include "Player.h"

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
    std::unique_ptr<Card> chosen_card_in_hand = RemoveCardFromHand(card_id);
    Card& chosen_card = *chosen_card_in_hand;
    ConsolePrinter::ShowActionMessage(name_ + " has used the card: ", false);
    chosen_card.Print();
    ConsolePrinter::BreakLine();
    turn_handler->HandleSetNewTurnColor(chosen_card.GetColor(), false);
    chosen_card.InvokeAction(turn_handler);
    turn_handler->HandleDiscardCardToPile(std::move(chosen_card_in_hand));
    turn_handler->HandleMoveToNextPlayer(*this);
}

Player::Player(const std::string name) : name_(name)
{
}

void Player::AddCardToHand(std::unique_ptr<Card> card)
{
    hand_.push_back(std::move(card));
    yelled_uno_ = false;
}

void Player::PrintHand() const
{
    for (int i = 0; i < GetHandSize(); i++)
    {
        if (i > 0 && i % 8 == 0)
        {
            std::cout << std::endl << "       ";
        }
        hand_[i]->Print(i);
    }
}

std::vector<std::unique_ptr<Card>> Player::MoveHand()
{
    return std::move(hand_);
}

std::string& Player::GetName()
{
    return name_;
}

void Player::SwapHand(std::vector<std::unique_ptr<Card>> hand)
{
    hand_ = std::move(hand);
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
        while (!InputOutputHelper::InputNumberInRange(0, GetHandSize() - 1, action_id) && !InputOutputHelper::InputNumberInRange(100, 102, action_id))
        {
            action_id = InputOutputHelper::ForceGetInput<int>(
                name_ + ", choose one card from your Deck or a special action: ");
        }
        if (action_id >= 100)
        {
            action_validated = true;
            UseSpecialAction(static_cast<special_action>(action_id), turn_handler);
        }
        else
        {
            action_validated = turn_handler->IsCardValidToPlay(*hand_[action_id]);
            if (action_validated)
            {
                PlayCard(action_id, turn_handler);
            }
        }
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
    turn_handler->PrintCurrentTurn(*this);
    ChooseAction(turn_handler);
}

void Player::DrawCard(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawCardForCurrentPlayer(1);
    turn_handler->HandleMoveToNextPlayer(*this);
}

void Player::YellUno(ITurnCardActionHandler* turn_handler)
{
    if (CanYellUno() && !HasYelledUno())
    {
        ConsolePrinter::ShowActionMessage(name_ + " has yelled UNO!");
        yelled_uno_ = true;
    }
    ChooseAction(turn_handler);
}

void Player::ShowSpecialActions(const special_action action) const
{
    const std::string id = std::to_string(static_cast<int>(action));
    switch (action)
    {
    case special_action::DRAW_CARD:
        std::cout << "[" + id + "]" + " Draw Card";
        break;
    case special_action::CLEAR_CONSOLE:
        std::cout << "[" + id + "]" + " Clear Console";
        break;
    case special_action::YELL_UNO:
        if (CanYellUno() && !HasYelledUno())
        {
            std::cout << "[" + id + "]" + " Yell UNO";
        }
        break;
    }
}

void Player::UseSpecialAction(const special_action action, ITurnCardActionHandler* turn_handler)
{
    switch (action)
    {
    case special_action::DRAW_CARD:
        DrawCard(turn_handler);
        break;
    case special_action::CLEAR_CONSOLE:
        ClearConsole(turn_handler);
        break;
    case special_action::YELL_UNO:
        if (CanYellUno())
        {
            YellUno(turn_handler);
        }
        break;
    }
}
