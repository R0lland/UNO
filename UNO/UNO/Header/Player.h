#pragma once
#include <memory>

#include "Card.h"
#include "CardCollection.h"
#include "SpecialActionData.h"

class Player
{
private:
    std::string name_;
    std::unique_ptr<CardCollection> hand_ = std::make_unique<CardCollection>();
    bool yelled_uno_ = false;

    bool CanYellUno() const;
    void PlayCard(int card_id, ITurnCardActionHandler* turn_handler);
    void DrawCard(ITurnCardActionHandler* turn_handler);
    void YellUno();
public:
    explicit Player(std::string name);
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::unique_ptr<CardCollection> MoveHand();
    std::string& GetName();
    void SwapHand(std::unique_ptr<CardCollection> hand);
    int GetHandSize() const;
    bool HandIsEmpty() const;
    bool HasYelledUno() const;
    void ChooseAction(ITurnCardActionHandler* turn_handler);
    void ClearConsole(ITurnCardActionHandler* turn_handler);
    void ShowSpecialActions(special_action action) const;
    void UseSpecialAction(special_action action, ITurnCardActionHandler* turn_handler);
};
