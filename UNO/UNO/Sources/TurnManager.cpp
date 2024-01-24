#include "TurnManager.h"

#include <iostream>

#include "ColorUtils.h"
#include "ConsolePrinter.h"
#include "GameConfig.h"

TurnManager::TurnManager(std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<Deck> deck) : players_(players), deck_(std::move(deck))
{
}

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
    SetTurnColor(GetDiscardPileTopCard().GetColor());
    StartTurn(0);
}

void TurnManager::StartTurn(const int player_id_turn)
{
    std::cout << std::endl;
    ColorUtils::PrintTextWithColor("- START TURN " + std::to_string(current_turn_), "grey");
    current_turn_++;
    ResetNumberOfMoves();
    current_player_id_ = player_id_turn;
    Player& current_player = *players_[current_player_id_];
    PrintPlayerTurn(current_player);
    current_player.ChooseAction(this);
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

        if (current_player_id_ != i)
        {
            std::cout << players_[i]->GetName() << " " << direction_arrow << " ";
        }
        else
        {
            player_name = "[" + players_[i]->GetName() + "]";
            ColorUtils::PrintTextWithColor(player_name, "aqua");
            std::cout << " " << direction_arrow << " ";
        }
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

void TurnManager::SetTurnColor(const card_color color)
{
    current_turn_color_ = color;
}

void TurnManager::HandleMoveToNextPlayer()
{
    ColorUtils::PrintTextWithColor("- END TURN " + std::to_string(current_turn_), "grey");
    std::cout << std::endl;
    StartTurn(GetNextPlayerId());
}

void TurnManager::HandleDrawCardForNextPlayer(const int number_of_cards)
{
    std::cout << players_[GetNextPlayerId()]->GetName() << " Draws " << number_of_cards << " card" << std::endl;
    DrawCardsForPlayer(*players_[GetNextPlayerId()], number_of_cards);
}

void TurnManager::HandleDiscardCardToPile(std::unique_ptr<Card> card)
{
    discard_pile_.push(std::move(card));
}

void TurnManager::HandleSetNewTurnColor(const card_color color, const bool show_message)
{
    if (show_message)
    {
        std::cout << players_[current_player_id_]->GetName() << " has set the Color to " << ColorUtils::GetColorName(color) << std::endl;
    }
    SetTurnColor(color);
}

void TurnManager::HandleSkipNextPlayer()
{
    std::cout << "Skipping " << players_[GetNextPlayerId()]->GetName() << " turn" << std::endl;
    next_player_move_ = GameConfig::SKIP_CARD_NUMBER_TO_SKIP;
}

void TurnManager::HandleDrawCardForCurrentPlayer()
{
    players_[current_player_id_]->AddCardToHand(deck_->DrawCard());
}

void TurnManager::HandleChangeGameDirection()
{
    ConsolePrinter::ShowMessage("Game direction has been changed");
    current_direction_ = current_direction_ == NORMAL ? REVERTED : NORMAL;
}

void TurnManager::DrawCardsForPlayer(Player& player, const int number_of_cards) const
{
    for (int i = 0; i < number_of_cards; i++)
    {
        player.AddCardToHand(deck_->DrawCard());
    }
}

void TurnManager::PrintPlayerTurn(const Player& player)
{
    std::cout << std::endl;
    ShowPlayerDirection();
    std::cout << "DECK: " << deck_->GetSize() << std::endl;
    std::cout << "PILE: ";
    ColorUtils::PrintColor(current_turn_color_);
    std::cout << " " << GetDiscardPileTopCard().GetDisplayValue() << std::endl << std::endl;
    std::cout << "CARDS: ";
    player.PrintHand();
    std::cout << std::endl;
    std::cout << "SPECIAL ACTIONS: ";
    std::cout << std::endl;
}

Card& TurnManager::GetDiscardPileTopCard()
{
    return *discard_pile_.top();
}
