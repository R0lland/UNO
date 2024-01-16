#pragma once
#include <memory>
#include <vector>

#include "Card.h"
#include "CardFactory.h"

class Deck
{
private:
    std::vector<std::shared_ptr<Card>> cards_{};
    std::unique_ptr<CardFactory> card_factory_;
public:
    Deck() = default;
    void AddCard(const std::shared_ptr<Card>& card);
    void Generate();
    void GenerateCardsFromColor(card_color color);
    void Shuffle();
    std::shared_ptr<Card>& DrawCard();
};
