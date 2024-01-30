#pragma once
#include <string>

class ITurnCardActionHandler;
class Player;

class SpecialAction
{
protected:
    int id_ = 0;
    std::string display_value_;
public:
    explicit SpecialAction(int id, std::string display_value);
    int GetId() const;
    void Print() const;
    virtual bool IsActionValidToUse(Player& player);
    virtual void InvokeAction(ITurnCardActionHandler* turn_handler);
};
