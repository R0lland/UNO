#include "SpecialAction.h"

#include "ColorUtils.h"
#include "ConsolePrinter.h"

SpecialAction::SpecialAction(const int id, const std::string display_value) : id_(id), display_value_(display_value)
{}

int SpecialAction::GetId() const
{
    return id_;
}

bool SpecialAction::IsActionValidToUse(Player& player)
{
    return true;
}

void SpecialAction::InvokeAction(ITurnActionHandler* turn_handler)
{
    
}

void SpecialAction::Print() const
{
    ConsolePrinter::ShowMessage("[" + std::to_string(id_) + "] " + " " + display_value_ + " | ", false);
}
