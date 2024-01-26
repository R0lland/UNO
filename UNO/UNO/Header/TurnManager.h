#pragma once
#include <memory>
#include <stack>
#include <vector>

#include "Deck.h"
#include "ITurnCardActionHandler.h"
#include "Player.h"

enum direction
{
    NORMAL = 1,
    REVERTED = -1
};

class TurnManager : ITurnCardActionHandler
{
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<Deck> deck_{};
    std::stack<std::unique_ptr<Card>> discard_pile_{};
    card_color current_turn_color_;
    direction current_direction_ = NORMAL;
    
    int current_player_id_ = 0;
    int current_turn_ = 0;
    int next_player_move_ = 1;
    int number_of_cards_to_draw_ = 0;
    
    void ShowPlayerDirection() const;
    int GetNextPlayerId() const;
    void ResetNumberOfMoves();
    void ResetNumberOfDraws();
    void SetTurnColor(card_color color);
    void ReShuffleDeckWithDiscardPile();
    void GameOver(Player& winner);
    void ShowPlayersAvailableToSwapHands();
    void SwapHandsBetweenPlayers(Player& player1, Player& player2);
public:
    explicit TurnManager(std::vector<std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck);
    void InitializeTurns();
    void StartTurn(int player_id_turn);
    void DrawCardsForPlayer(Player& player, int number_of_cards = 1);
    void PrintPlayerTurn(const Player& player);
    Card& GetDiscardPileTopCard();
    
    bool IsCardValidToPlay(const Card&) override;
    void HandleChangeGameDirection() override;
    void HandleMoveToNextPlayer(Player& current_player) override;
    void HandleDrawCardForNextPlayer(int number_of_cards) override;
    void HandleDiscardCardToPile(std::unique_ptr<Card> card) override;
    void HandleSetNewTurnColor(card_color color, bool show_message) override;
    void HandleSkipNextPlayer() override;
    void HandleDrawCardForCurrentPlayer(int number_of_cards) override;
    void PrintCurrentTurn(Player& player) override;
    void HandleSwapHands() override;
};
