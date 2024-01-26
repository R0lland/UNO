#pragma once
#include <memory>

#include "Card.h"
#include "Player.h"

class ITurnCardActionHandler
{
public:
    virtual bool IsCardValidToPlay(const Card&) = 0;
    virtual void HandleChangeGameDirection() = 0;
    virtual void HandleMoveToNextPlayer(Player& current_player) = 0;
    virtual void HandleDrawCardForNextPlayer(int number_of_cards) = 0;
    virtual void HandleDrawCardForCurrentPlayer(int number_of_cards) = 0;
    virtual void HandleDiscardCardToPile(std::unique_ptr<Card> card) = 0;
    virtual void HandleSetNewTurnColor(card_color color, bool show_message) = 0;
    virtual void HandleSkipNextPlayer() = 0;
    virtual void HandleSwapHands() = 0;
    virtual void PrintCurrentTurn(Player& player) = 0;
};
