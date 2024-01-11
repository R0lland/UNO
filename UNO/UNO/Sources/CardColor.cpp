#include "CardColor.h"

card_color IntToEnumColor(int color_id)
{
    return static_cast<card_color>(color_id);
}

bool ColorEquals(const card_color color1, const card_color color2)
{
    return color1 == color2;
}
