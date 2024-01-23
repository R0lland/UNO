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
    card_color current_turn_color_;
    direction current_direction_ = NORMAL;
    
    int current_player_id_ = 0;
    int next_player_move_ = 1;
    int number_of_cards_to_draw_ = 0;
    
    void ShowPlayerDirection() const;
    int GetNextPlayerId() const;
    void ResetNumberOfMoves();
    void ResetNumberOfDraws();
public:
    explicit TurnManager(std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<Deck> deck);
    void InitializeTurns();
    void StartTurn(int player_id_turn);
    void DrawCardsForPlayer(const std::unique_ptr<Player>& player, int number_of_cards = 1) const;
    
    std::unique_ptr<Card>& GetDiscardPileTopCard();
    
    bool IsCardValidToPlay(std::unique_ptr<Card>&) override;
    void HandleChangeGameDirection() override;
    void HandleMoveToNextPlayer() override;
    void HandleDrawCardForNextPlayer(int number_of_cards) override;
    void HandleDiscardCardToPile(std::unique_ptr<Card> card) override;
    void HandleSetNewTurnColor(card_color color) override;
    void HandleSkipNextPlayer() override;
};
