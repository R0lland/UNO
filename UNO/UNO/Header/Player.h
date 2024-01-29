#pragma once
#include <memory>
#include <vector>

#include "Card.h"
#include "SpecialActionData.h"

class Player
{
private:
    std::string name_;
    std::vector<std::unique_ptr<Card>> hand_{};
    bool yelled_uno_ = false;

    bool CanYellUno() const;
    void PlayCard(int card_id, ITurnCardActionHandler* turn_handler);
    void DrawCard(ITurnCardActionHandler* turn_handler);
    void YellUno();
public:
    explicit Player(std::string name);
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::vector<std::unique_ptr<Card>> MoveHand();
    std::string& GetName();
    void SwapHand(std::vector<std::unique_ptr<Card>> hand);
    int GetHandSize() const;
    bool HandIsEmpty() const;
    bool HasYelledUno() const;
    void ChooseAction(ITurnCardActionHandler* turn_handler);
    std::unique_ptr<Card> RemoveCardFromHand(int card_id);
    void ClearConsole(ITurnCardActionHandler* turn_handler);
    void ShowSpecialActions(special_action action) const;
    void UseSpecialAction(special_action action, ITurnCardActionHandler* turn_handler);
};
