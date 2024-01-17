#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Player
{
private:
    std::vector<std::unique_ptr<Card>> hand_{};
public:
    Player() = default;
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::vector<std::unique_ptr<Card>>& GetHand();
};
