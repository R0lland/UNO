#pragma once
#include <memory>
#include <vector>

#include "Card.h"
#include "CardFactory.h"

class Deck
{
private:
    std::vector<std::unique_ptr<Card>> cards_{};
    std::unique_ptr<CardFactory> card_factory_;
public:
    Deck();
    void AddCard(std::unique_ptr<Card> card);
    void Generate();
    int GetSize() const;
    void GenerateCardsFromColor(card_color color);
    void Shuffle();
    bool IsEmpty() const;
    void ClearDeck();
    std::unique_ptr<Card> DrawCard();
};
