#include "Player.h"

#include <iostream>
#include <memory>

#include "ConsolePrinter.h"
#include "GameConfig.h"
#include "InputOutputHelper.h"
#include "ITurnCardActionHandler.h"

bool Player::CanShoutUno() const
{
    return hand_->GetSize() == 2;
}

void Player::PlayCard(const int card_id, ITurnCardActionHandler* turn_handler)
{
    std::unique_ptr<Card> chosen_card_in_hand = hand_->DrawCard(card_id);
    Card& chosen_card = *chosen_card_in_hand;
    ConsolePrinter::ShowActionMessage(name_ + " has used the card: ", false);
    chosen_card.Print();
    ConsolePrinter::BreakLine();
    turn_handler->HandlePlayerUsedCard(*this, std::move(chosen_card_in_hand));
}

Player::Player(const std::string name) : name_(name)
{}

void Player::AddCardToHand(std::unique_ptr<Card> card)
{
    hand_->AddCard(std::move(card));
    shout_uno_ = false;
}

void Player::PrintHand() const
{
    for (int i = 0; i < GetHandSize(); i++)
    {
        if (i > 0 && i % 8 == 0)
        {
            std::cout << std::endl << "       ";
        }
        hand_->GetCard(i).Print(i);
    }
}

std::unique_ptr<CardCollection> Player::MoveHand()
{
    return std::move(hand_);
}

std::string& Player::GetName()
{
    return name_;
}

void Player::SwapHand(std::unique_ptr<CardCollection> hand)
{
    hand_ = std::move(hand);
    if (GetHandSize() <= 1)
    {
        ShoutUno();
    }
}

int Player::GetHandSize() const
{
    return hand_->GetSize();
}

bool Player::HandIsEmpty() const
{
    return hand_->IsEmpty();
}

bool Player::HasShoutedUno() const
{
    return shout_uno_;
}

void Player::ChooseAction(ITurnCardActionHandler* turn_handler)
{
    bool action_validated = false;
    while (!action_validated)
    {
        int action_id = -1;
        while (!InputOutputHelper::InputNumberInRange(0, GetHandSize() - 1, action_id) &&
            !InputOutputHelper::InputNumberInRange(special_actions_->GetStartingSpecialActionsId(), special_actions_->GetLastSpecialActionsId(), action_id))
        {
            action_id = InputOutputHelper::ForceGetInput<int>(
                name_ + ", choose one card from your Deck or a special action: ");
        }
        if (action_id >= special_actions_->GetStartingSpecialActionsId())
        {
            action_validated = true;
            special_actions_->UseAction(turn_handler, action_id);
        }
        else
        {
            action_validated = turn_handler->IsCardValidToPlay(hand_->GetCard(action_id));
            if (action_validated)
            {
                PlayCard(action_id, turn_handler);
            }
        }
    }
}

void Player::ShoutUno()
{
    if (CanShoutUno() && !HasShoutedUno())
    {
        ConsolePrinter::ShowActionMessage(name_ + " has shouted UNO!");
        shout_uno_ = true;
    }
}

void Player::ShowSpecialActions()
{
    special_actions_->PrintActions(*this);
}
