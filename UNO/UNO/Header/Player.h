#pragma once
#include <memory>

#include "SpecialAction.h"
#include "Card.h"
#include "CardCollection.h"
#include "SpecialActionsCollection.h"

class Player
{
private:
    std::string name_;
    std::unique_ptr<CardCollection> hand_ = std::make_unique<CardCollection>();
    std::unique_ptr<SpecialActionsCollection> special_actions_ = std::make_unique<SpecialActionsCollection>();
    bool shout_uno_ = false;
    
    void PlayCard(int card_id, ITurnCardActionHandler* turn_handler);
public:
    explicit Player(std::string name);
    void AddCardToHand(std::unique_ptr<Card> card);
    void PrintHand() const;
    std::unique_ptr<CardCollection> MoveHand();
    std::string& GetName();
    void SwapHand(std::unique_ptr<CardCollection> hand);
    int GetHandSize() const;
    bool HandIsEmpty() const;
    bool HasShoutedUno() const;
    void ChooseAction(ITurnCardActionHandler* turn_handler);
    void ShowSpecialActions();
    bool CanShoutUno() const;
    void ShoutUno();
};
