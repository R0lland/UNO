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

    bool CanYellUno();
    void PlayCard(int card_id, ITurnCardActionHandler* turn_handler); 
public:
    explicit Player(std::string name);
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::string& GetName();
    int GetHandSize() const;
    bool HasCards() const;
    void ChooseAction(ITurnCardActionHandler* turn_handler);
    std::unique_ptr<Card> RemoveCardFromHand(int card_id);
    void ClearConsole();
    void DrawCard(ITurnCardActionHandler* turn_handler);
    void YellUno(ITurnCardActionHandler* turn_handler);
    
};
