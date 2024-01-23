#include "TurnManager.h"

#include <iostream>

#include "ColorUtils.h"
#include "GameConfig.h"

TurnManager::TurnManager(std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<Deck> deck) : players_(players), deck_(std::move(deck))
{}

bool TurnManager::IsCardValidToPlay(const Card& card)
{
   if (card.GetColor() == current_turn_color_ || card.GetDisplayValue() == GetDiscardPileTopCard().GetDisplayValue() ||
       card.GetType() == card_type::WILD || current_turn_color_ == card_color::WILD)
   {
       return true;
   }
    return false;
}

void TurnManager::InitializeTurns()
{
    HandleDiscardCardToPile(deck_->DrawCard());
    HandleSetNewTurnColor(GetDiscardPileTopCard().GetColor());
    StartTurn(0);
}

void TurnManager::StartTurn(const int player_id_turn)
{
    ResetNumberOfMoves();
    Player& current_player = *players_[current_player_id_];
    current_player_id_ = player_id_turn;
    std::cout << std::endl;
    ShowPlayerDirection();
    current_player.PrintHand();
    std::cout << std::endl << "DECK: " << deck_->GetSize() << std::endl;
    std::cout << "PILE: ";
    ColorUtils::PrintColor(current_turn_color_);
    std::cout << " " << GetDiscardPileTopCard().GetDisplayValue() << std::endl;
    current_player.ChooseCard(this);
    std::cout << std::endl;
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

int TurnManager::GetNextPlayerId() const
{
    int new_player_id = current_player_id_ + (next_player_move_ * current_direction_);
    if (new_player_id < 0)
    {
        new_player_id = new_player_id + players_.size();
    }
    else if (new_player_id >= players_.size())
    {
        new_player_id = new_player_id - players_.size();
    }
    return new_player_id; 
}

void TurnManager::ResetNumberOfMoves()
{
    next_player_move_ = 1;
}

void TurnManager::ResetNumberOfDraws()
{
    number_of_cards_to_draw_ = 0;
}

void TurnManager::HandleMoveToNextPlayer()
{
    StartTurn(GetNextPlayerId());
}

void TurnManager::HandleDrawCardForNextPlayer(const int number_of_cards)
{
    DrawCardsForPlayer(*players_[GetNextPlayerId()], number_of_cards);
}

void TurnManager::HandleDiscardCardToPile(std::unique_ptr<Card> card)
{
    discard_pile_.push(std::move(card));
}

void TurnManager::HandleSetNewTurnColor(const card_color color)
{
    current_turn_color_ = color;
}

void TurnManager::HandleSkipNextPlayer()
{
    next_player_move_ = GameConfig::SKIP_CARD_NUMBER_TO_SKIP;
}

void TurnManager::HandleChangeGameDirection()
{
    current_direction_ = current_direction_ == NORMAL ? REVERTED : NORMAL;
}

void TurnManager::DrawCardsForPlayer(Player& player, const int number_of_cards) const
{
    for (int i = 0; i < number_of_cards; i++)
    {
        player.AddCardToHand(deck_->DrawCard());
    }
}

Card& TurnManager::GetDiscardPileTopCard()
{
    return *discard_pile_.top();
}
