#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Player
{
private:
    std::string name_;
    std::vector<std::unique_ptr<Card>> hand_{};
public:
    explicit Player(std::string name);
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::string& GetName();
    std::vector<std::unique_ptr<Card>>& GetHand();
};
