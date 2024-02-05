#pragma once
#include <memory>

#include "Card.h"
#include "CardCollection.h"
#include "CardFactory.h"

class Deck : public CardCollection
{
private:
    std::unique_ptr<CardFactory> card_factory_ = std::make_unique<CardFactory>();
    void GenerateCardsFromColor(card_color color);
public:
    void Generate();
};
