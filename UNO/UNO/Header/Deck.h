#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Deck
{
private:
    std::shared_ptr<std::vector<Card>> cards_;
public:
    Deck() = default;
    void shuffle();
    void take_cards();
};
