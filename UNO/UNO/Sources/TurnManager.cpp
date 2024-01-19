﻿#include "TurnManager.h"

#include <iostream>

TurnManager::TurnManager(std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<Deck> deck) : players_(players), deck_(std::move(deck))
{}

bool TurnManager::IsCardValidToPlay(const std::unique_ptr<Card>& card)
{
   if (card->GetColor() == GetDiscardPileTopCard()->GetColor() || card->GetType() == GetDiscardPileTopCard()->GetType() || card->GetType() == card_type::WILD)
   {
       return true;
   }
    return false;
}

void TurnManager::AddToDiscardPile(std::unique_ptr<Card> card)
{
    discard_pile_.push(std::move(card));
}

void TurnManager::InitializeTurns()
{
    AddToDiscardPile(deck_->DrawCard());
    StartTurn(0);
}

void TurnManager::StartTurn(const int player_id_turn)
{
    current_player_id_ = player_id_turn;
    ShowPlayerDirection();
    players_[current_player_id_]->PrintHand();
    std::cout << "PILE: ";
    GetDiscardPileTopCard()->Print();
    players_[current_player_id_]->ChooseCard();
    std::cout << std::endl;
    SetNextPlayerTurn();
}

void TurnManager::ShowPlayerDirection() const
{
    std::string direction_arrow = current_direction_ == NORMAL ? "->" : "<-";
    std::string player_name = "";
    for (int i = 0; i < players_.size(); i++)
    {
        if (i >= players_.size() - 1)
        {
            direction_arrow = "";
        }
        player_name = current_player_id_ != i ? players_[i]->GetName() : "[" + players_[i]->GetName() + "]";
        std::cout << player_name << " " << direction_arrow << " ";
    }
    std::cout << std::endl;
}

void TurnManager::SetNextPlayerTurn(const int number_of_moves)
{
    int new_player_id = current_player_id_ + (number_of_moves * current_direction_);
    if (new_player_id < 0)
    {
        new_player_id = new_player_id + players_.size();
    }
    else if (new_player_id >= players_.size())
    {
        new_player_id = new_player_id - players_.size();
    }
    
    StartTurn(new_player_id);
}

void TurnManager::ChangeGameDirection()
{
    current_direction_ = current_direction_ == NORMAL ? REVERTED : NORMAL;
}

void TurnManager::AddCardToDiscardPile(std::unique_ptr<Card> card)
{
    discard_pile_.push(std::move(card));
}

void TurnManager::DrawCardsForPlayer(const std::unique_ptr<Player>& player, int number_of_cards) const
{
    for (int i = 0; i < number_of_cards; i++)
    {
        player->AddCardToHand(deck_->DrawCard());
    }
}

std::unique_ptr<Card>& TurnManager::GetDiscardPileTopCard()
{
    return discard_pile_.top();
}