#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Player
{
private:
    std::string name_;
    std::vector<std::unique_ptr<Card>> hand_{};
    bool yelled_uno_ = false;
public:
    explicit Player(std::string name);
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::string& GetName();
    int GetHandSize() const;
    void YellUno();
    bool HasCards() const;
    void ChooseCard(ITurnCardActionHandler* turn_handler);
    std::unique_ptr<Card> RemoveCardFromHand(int card_id);
};
