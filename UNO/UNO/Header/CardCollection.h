#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class CardCollection
{
protected:
    std::vector<std::shared_ptr<Card>> cards_{};
public:
    void AddCard(std::shared_ptr<Card> card);
    std::shared_ptr<Card> DrawTopCard();
    std::shared_ptr<Card> DrawRandomCard();
    std::shared_ptr<Card> DrawCard(int id);
    std::shared_ptr<Card> GetCard(int id) const;
    std::shared_ptr<Card> GetTopCard() const;
    void Shuffle();
    void ClearCollection();
    [[nodiscard]] int GetSize() const;
    [[nodiscard]] bool IsEmpty() const;
};
