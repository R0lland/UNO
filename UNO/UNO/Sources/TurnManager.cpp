#include "TurnManager.h"

#include <iostream>
#include <algorithm>

#include "ColorUtils.h"
#include "ConsolePrinter.h"
#include "GameConfig.h"
#include "InputOutputHelper.h"

TurnManager::TurnManager()
{}

bool TurnManager::IsCardValidToPlay(const Card& card)
{
   if (card.GetCanBeUsedAnyTurn() || card.GetColor() == current_turn_color_ || card.GetDisplayValue() == GetDiscardPileTopCard()->GetDisplayValue() ||
       current_turn_color_ == card_color::WILD ||  current_turn_color_ == card_color::NONE)
   {
       return true;
   }
    return false;
}

void TurnManager::Initialize(std::vector<std::shared_ptr<Player>> players, std::shared_ptr<Deck> deck)
{
    players_ = std::move(players);
    deck_ = std::move(deck);
    DiscardCardToPile(deck_->DrawTopCard());
    SetTurnColor(GetDiscardPileTopCard()->GetColor());
    current_turn_ = 0;
    StartTurn(0);
}

void TurnManager::StartTurn(const int player_id_turn)
{
    ConsolePrinter::BreakLine();
    current_turn_++;
    ResetNumberOfMoves();
    current_player_id_ = player_id_turn;
    Player& current_player = *players_[current_player_id_];
    PrintPlayerTurn(current_player);
    current_player.ChooseAction(this);
}

void TurnManager::ShowPlayers() const
{
    std::string direction_arrow = current_direction_ == NORMAL ? "->" : "<-";
    std::string player_name;
    for (size_t i = 0; i < players_.size(); i++)
    {
        if (i >= players_.size() - 1)
        {
            direction_arrow = "";
        }

        player_name = players_[i]->GetName();

        player_name += ":" + std::to_string(players_[i]->GetHandSize());
        
        if (players_[i]->HasShoutedUno())
        {
            player_name += " (UNO)";
        }
        
        if (current_player_id_ != i)
        {
            ConsolePrinter::ShowMessage(player_name + " " + direction_arrow + " ", false);
        }
        else
        {
            player_name = "[" +  player_name + "]";
            ColorUtils::PrintTextWithColor(player_name, "aqua");
            ConsolePrinter::ShowMessage(" " + direction_arrow + " ", false);
        }
    }
    ConsolePrinter::BreakLine();
}

int TurnManager::GetNextPlayerId() const
{
    const int players_size = static_cast<int>(players_.size());
    int new_player_id = current_player_id_ + (next_player_move_ * current_direction_);
    if (new_player_id < 0)
    {
        new_player_id = new_player_id + players_size;
    }
    else if (new_player_id >= players_size)
    {
        new_player_id = new_player_id - players_size;
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

void TurnManager::ReShuffleDeckWithDiscardPile() const
{
    std::shared_ptr<Card> last_card = discard_pile_->DrawTopCard();
    const int total_cards_in_pile = discard_pile_->GetSize();
    for (int i = 0; i < total_cards_in_pile; i++)
    {
        deck_->AddCard(discard_pile_->DrawTopCard());
    }
    DiscardCardToPile(std::move(last_card));
    deck_->Shuffle();
}

void TurnManager::GameOver(Player& winner)
{
    ConsolePrinter::ShowActionMessage(winner.GetName() + " used the last card and has shouted UNO");
    ConsolePrinter::BreakLine();
    ColorUtils::PrintTextWithColor("AND THE WINNER IS: " + winner.GetName(), "green");
    ConsolePrinter::BreakLine(2);
    players_.clear();
    deck_->ClearCollection();
    discard_pile_->ClearCollection();
    CheckForReplayGame();
}

void TurnManager::CheckForReplayGame()
{
    int play_again = -1;
    const std::string display_message = "[0] NO | [1] YES \nWould you like to play again? ";
    while (!InputOutputHelper::InputNumberInRange(0, 1, play_again))
    {
        play_again = InputOutputHelper::ForceGetInput<int>(display_message);
    }

    if (play_again == 0)
    {
        game_ended_ = true;
    }

    ConsolePrinter::ClearConsole();
}

void TurnManager::ShowPlayersAvailableToSwapHands() const
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

void TurnManager::SwapHandsBetweenPlayers(Player& player1, Player& player2) const
{
    ConsolePrinter::ShowActionMessage(player1.GetName() + " is swapping hand with " + player2.GetName());

    std::unique_ptr<CardCollection> hand_player1 = player1.MoveHand();
    std::unique_ptr<CardCollection> hand_player2 = player2.MoveHand();

    player1.SwapHand(std::move(hand_player2));
    player2.SwapHand(std::move(hand_player1));
}

void TurnManager::DrawCardsFromDiscardPileForPlayer(Player& player, const int number_of_cards) const
{
    ConsolePrinter::ShowActionMessage(player.GetName() + " is drawing " + std::to_string(number_of_cards) + " random cards from the discard pile");
    for (int i = 0; i < number_of_cards; i++)
    {
        player.AddCardToHand(discard_pile_->DrawRandomCard());
    }
}

void TurnManager::HandlePlayerUsedCard(Player& player, std::shared_ptr<Card> card)
{
    if (player.HandIsEmpty() && player.HasShoutedUno())
    {
        GameOver(player);
    }
    else
    {
        if (player.HandIsEmpty())
        {
            ConsolePrinter::ShowActionMessage(player.GetName() + " forgot to shout UNO");
            HandleDrawCardForCurrentPlayer(GameConfig::NUMBER_OF_CARDS_TO_DRAW_IF_PLAYER_DIDNT_SHOUT_UNO);
        }
        HandleSetNewTurnColor(card->GetColor(), false);
        card->InvokeAction(this);
        DiscardCardToPile(std::move(card));
        HandleEndTurn();
    }
}

void TurnManager::HandleClearConsole()
{
    ConsolePrinter::ClearConsole();
    Player& player = *players_[current_player_id_];
    PrintCurrentTurn(player);
    player.ChooseAction(this);
}

void TurnManager::HandleShoutUno()
{
    players_[current_player_id_]->TryToShoutUno();
    players_[current_player_id_]->ChooseAction(this);
}

void TurnManager::HandleDrawCardForNextPlayer(const int number_of_cards)
{
    ConsolePrinter::ShowActionMessage(players_[GetNextPlayerId()]->GetName() + " Draws " + std::to_string(number_of_cards) + " cards");
    DrawCardsForPlayer(*players_[GetNextPlayerId()], number_of_cards);
}

void TurnManager::DiscardCardToPile(std::shared_ptr<Card> card) const
{
    discard_pile_->AddCard(std::move(card));
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

void TurnManager::HandleEndTurn()
{
    ConsolePrinter::ShowCenterMessage(" END TURN " + std::to_string(current_turn_) + " ");
    ConsolePrinter::BreakLine();
    StartTurn(GetNextPlayerId());
}

void TurnManager::HandleSkipNextPlayer()
{
    ConsolePrinter::ShowActionMessage("Skipping " + players_[GetNextPlayerId()]->GetName() + " turn");
    next_player_move_ = GameConfig::SKIP_CARD_NUMBER_TO_SKIP;
}

void TurnManager::HandleDrawCardForCurrentPlayer(const int number_of_cards)
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
    const int players_size = static_cast<int>(players_.size());
    ShowPlayersAvailableToSwapHands();
    int player_to_swap_with_id= -1;
    while (!InputOutputHelper::InputNumberInRange(0, players_size - 1, player_to_swap_with_id) && player_to_swap_with_id != current_player_id_)
    {
        player_to_swap_with_id = InputOutputHelper::ForceGetInput<int>(current_player.GetName() + ", choose one player to swap hands with: ");
    }
    SwapHandsBetweenPlayers(current_player, *players_[player_to_swap_with_id]);
}

void TurnManager::HandleDrawFromDiscardPileForNextPlayer(int draw_from_pile)
{
    Player& player = *players_[GetNextPlayerId()];
    const int discard_pile_size = discard_pile_->GetSize();
    int draw_from_deck = 0;
    if (draw_from_pile > discard_pile_size)
    {
        draw_from_deck = abs(discard_pile_size - draw_from_pile);
        draw_from_pile = discard_pile_size;
    }
    DrawCardsFromDiscardPileForPlayer(player, draw_from_pile);
    if (draw_from_deck > 0)
    {
        ConsolePrinter::ShowActionMessage("Not enough cards on discard pile, drawing cards from Deck");
        HandleDrawCardForNextPlayer(draw_from_deck);
    }
}

void TurnManager::HandleChangeGameDirection()
{
    ConsolePrinter::ShowActionMessage("Game direction has been changed");
    current_direction_ = current_direction_ == NORMAL ? REVERTED : NORMAL;
}

void TurnManager::DrawCardsForPlayer(Player& player, const int number_of_cards) const
{
    for (int i = 0; i < number_of_cards; i++)
    {
        if (deck_->IsEmpty())
        {
            ReShuffleDeckWithDiscardPile();
        }

        if (!deck_->IsEmpty())
        {
            player.AddCardToHand(deck_->DrawTopCard());
        }
    }
}

void TurnManager::PrintPlayerTurn(Player& player) const
{
    ConsolePrinter::ShowCenterMessage("START TURN " + std::to_string(current_turn_));
    ConsolePrinter::BreakLine();
    ShowPlayers();
    ConsolePrinter::ShowMessage("DECK SIZE: " + std::to_string(deck_->GetSize()));
    ConsolePrinter::ShowMessage("PILE SIZE: " + std::to_string(discard_pile_->GetSize()));
    ConsolePrinter::ShowMessage("PILE TOP: ", false);
    ColorUtils::PrintColor(current_turn_color_);
    ConsolePrinter::ShowMessage(" " + GetDiscardPileTopCard()->GetDisplayValue());
    ConsolePrinter::BreakLine();
    ColorUtils::PrintTextWithColor("CARDS: ", "aqua");
    player.PrintHand();
    ConsolePrinter::BreakLine();
    ColorUtils::PrintTextWithColor("ACTIONS: ", "aqua");
    player.ShowSpecialActions();
    ConsolePrinter::BreakLine();
}

std::shared_ptr<Card> TurnManager::GetDiscardPileTopCard() const
{
    return discard_pile_->GetTopCard();
}

bool TurnManager::GetGameEnded() const
{
    return game_ended_;
}
