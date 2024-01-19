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
    std::vector<std::unique_ptr<Player>>& players_;
    std::unique_ptr<Deck> deck_{};
    std::stack<std::unique_ptr<Card>> discard_pile_{};
    int current_player_id_ = 0;
    direction current_direction_ = NORMAL;
    
    void ShowPlayerDirection() const;
    int GetNextPlayerId(int number_of_moves = 1);
public:
    explicit TurnManager(std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<Deck> deck);
    void InitializeTurns();
    void StartTurn(int player_id_turn);
    void DrawCardsForPlayer(const std::unique_ptr<Player>& player, int number_of_cards = 1) const;
    
    std::unique_ptr<Card>& GetDiscardPileTopCard();
    
    bool IsCardValidToPlay(std::unique_ptr<Card>& card) override;
    void HandleChangeGameDirection() override;
    void HandleMoveToNextPlayer(int number_of_moves = 1) override;
    void HandleDrawCardForNextPlayer(int number_of_cards) override;
    void HandleDiscardCardToPile(std::unique_ptr<Card> card) override;
};
