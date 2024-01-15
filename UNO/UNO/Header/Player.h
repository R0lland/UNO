#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Player
{
private:
    std::vector<std::shared_ptr<Card>> hand_{};
public:
    Player() = default;
    void AddCardToHand(const std::shared_ptr<Card>& card);
    void ChooseCard();
};
