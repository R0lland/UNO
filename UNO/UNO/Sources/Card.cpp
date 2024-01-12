#include "../Header/Card.h"

Card::Card(const card_color color) : color_(color)
{
    color_ = card_color::RED;
}

card_color Card::GetColor() const
{
    return color_;
}
