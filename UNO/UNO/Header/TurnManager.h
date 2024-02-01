#pragma once
#include <memory>
#include <stack>
#include <vector>

#include "Deck.h"
#include "ITurnActionHandler.h"
#include "Player.h"

enum direction
{
    NORMAL = 1,
    REVERTED = -1
};

class TurnManager : ITurnActionHandler
{
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<Deck> deck_ = std::make_unique<Deck>();
    std::unique_ptr<CardCollection> discard_pile_ = std::make_unique<CardCollection>();
    card_color current_turn_color_;
    direction current_direction_ = NORMAL;
    
    int current_player_id_ = 0;
    int current_turn_ = 0;
    int next_player_move_ = 1;
    int number_of_cards_to_draw_ = 0;
    bool game_ended_ = false;
    
    void ShowPlayers() const;
    int GetNextPlayerId() const;
    void ResetNumberOfMoves();
    void ResetNumberOfDraws();
    void SetTurnColor(card_color color);
    void ReShuffleDeckWithDiscardPile() const;
    void GameOver(Player& winner);
    void CheckForReplayGame();
    void ShowPlayersAvailableToSwapHands() const;
    void SwapHandsBetweenPlayers(Player& player1, Player& player2) const;
    void DrawCardsFromDiscardPileForPlayer(Player& player, int number_of_cards = 1) const;
    
public:
    TurnManager();
    void Initialize(std::vector<std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck);
    void StartTurn(int player_id_turn);
    void DrawCardsForPlayer(Player& player, int number_of_cards = 1) const;
    void PrintPlayerTurn(Player& player) const;
    Card& GetDiscardPileTopCard() const;
    bool GetGameEnded() const;
    void DiscardCardToPile(std::unique_ptr<Card> card) const;
    std::unique_ptr<Deck> ReturnMovedDeck();
    
    bool IsCardValidToPlay(const Card&) override;
    void HandleChangeGameDirection() override;
    void HandleDrawCardForNextPlayer(int number_of_cards) override;
    void HandleSetNewTurnColor(card_color color, bool show_message) override;
    void HandleEndTurn() override;
    void HandleSkipNextPlayer() override;
    void HandleDrawCardForCurrentPlayer(int number_of_cards) override;
    void PrintCurrentTurn(Player& player) override;
    void HandleSwapHands() override;
    void HandleDrawFromDiscardPileForNextPlayer(int draw_from_pile) override;
    void HandlePlayerUsedCard(Player& player, std::unique_ptr<Card> card) override;
    void HandleClearConsole() override;
    void HandleShoutUno() override;
};
