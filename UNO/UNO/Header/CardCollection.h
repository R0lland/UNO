#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class CardCollection
{
protected:
    std::vector<std::unique_ptr<Card>> cards_{};
public:
    void AddCard(std::unique_ptr<Card> card);
    std::unique_ptr<Card> DrawTopCard();
    std::unique_ptr<Card> DrawRandomCard();
    std::unique_ptr<Card> DrawCard(int id);
    Card& GetCard(int id);
    Card& GetTopCard();
    void Shuffle();
    void ClearCollection();
    [[nodiscard]] int GetSize() const;
    [[nodiscard]] bool IsEmpty() const;
};
