#include "../Header/Card.h"

Card::Card(const card_color color) : color_(color)
{}

card_color Card::GetColor() const
{
    return color_;
}
