#include "../Header/Card.h"

Card::Card(const card_color color, const int number)
{
    color_ = color;
    number_ = number;
}

card_color Card::GetColor() const
{
    return color_;
}
