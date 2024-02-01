#pragma once
#include <memory>

#include "Card.h"
#include "Player.h"

class ITurnActionHandler
{
public:
    virtual bool IsCardValidToPlay(const Card&) = 0;
    virtual void HandleChangeGameDirection() = 0;
    virtual void HandleEndTurn() = 0;
    virtual void HandlePlayerUsedCard(Player& player, std::unique_ptr<Card> card) = 0;
    virtual void HandleDrawCardForNextPlayer(int number_of_cards) = 0;
    virtual void HandleDrawCardForCurrentPlayer(int number_of_cards) = 0;
    virtual void HandleSetNewTurnColor(card_color color, bool show_message) = 0;
    virtual void HandleSkipNextPlayer() = 0;
    virtual void HandleSwapHands() = 0;
    virtual void HandleDrawFromDiscardPileForNextPlayer(int number_of_cards) = 0;
    virtual void PrintCurrentTurn(Player& player) = 0;
    virtual void HandleClearConsole() = 0;
    virtual void HandleShoutUno() = 0;
};
