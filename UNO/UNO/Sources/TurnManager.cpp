#include "TurnManager.h"

#include <iostream>
#include <algorithm>

#include "ColorUtils.h"
#include "ConsolePrinter.h"
#include "GameConfig.h"
#include "InputOutputHelper.h"

TurnManager::TurnManager(std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<Deck> deck) : players_(players), deck_(std::move(deck))
{
}

bool TurnManager::IsCardValidToPlay(const Card& card)
{
   if (card.GetCanBeUsedAnyTurn() || card.GetColor() == current_turn_color_ || card.GetDisplayValue() == GetDiscardPileTopCard().GetDisplayValue() ||
       current_turn_color_ == card_color::WILD ||  current_turn_color_ == card_color::NONE)
   {
       return true;
   }
    return false;
}

void TurnManager::InitializeTurns()
{
    HandleDiscardCardToPile(deck_->DrawCard());
    SetTurnColor(GetDiscardPileTopCard().GetColor());
    current_turn_ = 0;
    StartTurn(0);
}

void TurnManager::StartTurn(const int player_id_turn)
{
    std::cout << std::endl;
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
    std::string player_name;
    for (int i = 0; i < players_.size(); i++)
    {
        if (i >= players_.size() - 1)
        {
            direction_arrow = "";
        }

        player_name = players_[i]->GetName();
        
        if (players_[i]->HasYelledUno())
        {
            player_name += " (UNO)";
        }
        
        if (current_player_id_ != i)
        {
            std::cout << player_name << " " << direction_arrow << " ";
        }
        else
        {
            player_name = "[" + player_name + "]";
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

void TurnManager::ReShuffleDeckWithDiscardPile()
{
    const int total_cards_in_pile = discard_pile_.size();
    for (int i = 0; i < total_cards_in_pile; i++)
    {
        deck_->AddCard(std::move(discard_pile_.top()));
        discard_pile_.pop();
    }
    deck_->Shuffle();
}

void TurnManager::GameOver(Player& winner)
{
    std::cout << std::endl;
    ConsolePrinter::ShowActionMessage(winner.GetName() + " used the last card and has shouted UNO");
    ConsolePrinter::ShowMessage(winner.GetName() + " WINS");
    players_.clear();
    deck_->ClearDeck();
    while (!discard_pile_.empty())
    {
        discard_pile_.pop();
    }
    ConsolePrinter::ShowMessage("Press any button to Quit");
    int input;
    std::cin >> std::ws >> input;
}

void TurnManager::ShowPlayersAvailableToSwapHands()
{
    for (int i = 0; i < players_.size(); i++)
    {
        if (i == current_player_id_)
        {
            continue;
        }
        ConsolePrinter::ShowMessage("[" + std::to_string(i) + "] ", false);
        ConsolePrinter::ShowMessage(players_[i]->GetName() + " | ", false);
    }
    ConsolePrinter::BreakLine();
}

void TurnManager::SwapHandsBetweenPlayers(Player& player1, Player& player2)
{
    ConsolePrinter::ShowActionMessage(player1.GetName() + " is swapping hand with " + player2.GetName());

    std::vector<std::unique_ptr<Card>> hand_player1 = player1.MoveHand();
    std::vector<std::unique_ptr<Card>> hand_player2 = player2.MoveHand();

    player1.SwapHand(std::move(hand_player2));
    player2.SwapHand(std::move(hand_player1));
}

void TurnManager::HandleMoveToNextPlayer(Player& current_player)
{
    if (current_player.HandIsEmpty())
    {
        if (current_player.HasYelledUno())
        {
            GameOver(current_player);
            
            return;
        }
        ConsolePrinter::ShowActionMessage(current_player.GetName() + " forgot to shout UNO");
        HandleDrawCardForCurrentPlayer(GameConfig::NUMBER_OF_CARDS_TO_DRAW_IF_PLAYER_DIDNT_SHOUT_UNO);
    }
    
    ColorUtils::PrintTextWithColor("- END TURN " + std::to_string(current_turn_), "grey");
    std::cout << std::endl;
    StartTurn(GetNextPlayerId());
}

void TurnManager::HandleDrawCardForNextPlayer(const int number_of_cards)
{
    ConsolePrinter::ShowActionMessage(players_[GetNextPlayerId()]->GetName() + " Draws " + std::to_string(number_of_cards) + " cards");
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
        ConsolePrinter::ShowActionMessage(players_[current_player_id_]->GetName() + " has set the Color to ", false);
        ColorUtils::PrintColor(color);
        ConsolePrinter::BreakLine();
    }
    SetTurnColor(color);
}

void TurnManager::HandleSkipNextPlayer()
{
    ConsolePrinter::ShowActionMessage("Skipping " + players_[GetNextPlayerId()]->GetName() + " turn");
    next_player_move_ = GameConfig::SKIP_CARD_NUMBER_TO_SKIP;
}

void TurnManager::HandleDrawCardForCurrentPlayer(int number_of_cards)
{
    ConsolePrinter::ShowActionMessage( players_[current_player_id_]->GetName() + " Draws " + std::to_string(number_of_cards) + " card");
    DrawCardsForPlayer(*players_[current_player_id_], number_of_cards);
}

void TurnManager::PrintCurrentTurn(Player& player)
{
    PrintPlayerTurn(player);
}

void TurnManager::HandleSwapHands()
{
    Player& current_player = *players_[current_player_id_];
    ShowPlayersAvailableToSwapHands();
    int player_to_swap_with_id= -1;
    while (!InputOutputHelper::InputNumberInRange(0, players_.size() - 1, player_to_swap_with_id) && player_to_swap_with_id != current_player_id_)
    {
        player_to_swap_with_id = InputOutputHelper::ForceGetInput<int>(current_player.GetName() + ", choose one player to swap hands with: ");
    }
    SwapHandsBetweenPlayers(current_player, *players_[player_to_swap_with_id]);
}

void TurnManager::HandleChangeGameDirection()
{
    ConsolePrinter::ShowActionMessage("Game direction has been changed");
    current_direction_ = current_direction_ == NORMAL ? REVERTED : NORMAL;
}

void TurnManager::DrawCardsForPlayer(Player& player, int number_of_cards)
{
    for (int i = 0; i < number_of_cards; i++)
    {
        if (deck_->GetSize() <= 0)
        {
            ReShuffleDeckWithDiscardPile();
        }
        
        player.AddCardToHand(deck_->DrawCard());
    }
}

void TurnManager::PrintPlayerTurn(const Player& player)
{
    ColorUtils::PrintTextWithColor("- START TURN " + std::to_string(current_turn_), "grey");
    std::cout << std::endl;
    ShowPlayerDirection();
    std::cout << "DECK: " << deck_->GetSize() << std::endl;
    std::cout << "PILE: ";
    ColorUtils::PrintColor(current_turn_color_);
    std::cout << " " << GetDiscardPileTopCard().GetDisplayValue() << std::endl << std::endl;
    ColorUtils::PrintTextWithColor("CARDS: ", "aqua");
    player.PrintHand();
    std::cout << std::endl;
    ColorUtils::PrintTextWithColor("ACTIONS: ", "aqua");
    player.ShowSpecialActions(special_action::DRAW_CARD);
    std::cout << " | ";
    player.ShowSpecialActions(special_action::CLEAR_CONSOLE);
    std::cout << " | ";
    player.ShowSpecialActions(special_action::YELL_UNO);
    std::cout << std::endl;
}

Card& TurnManager::GetDiscardPileTopCard()
{
    return *discard_pile_.top();
}
