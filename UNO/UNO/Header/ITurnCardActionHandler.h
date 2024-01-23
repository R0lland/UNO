#pragma once
#include <memory>

#include "Card.h"

class ITurnCardActionHandler
{
public:
    virtual bool IsCardValidToPlay(const Card&) = 0;
    virtual void HandleChangeGameDirection() = 0;
    virtual void HandleMoveToNextPlayer() = 0;
    virtual void HandleDrawCardForNextPlayer(int number_of_cards) = 0;
    virtual void HandleDiscardCardToPile(std::unique_ptr<Card> card) = 0;
    virtual void HandleSetNewTurnColor(card_color color) = 0;
    virtual void HandleSkipNextPlayer() = 0;
};
