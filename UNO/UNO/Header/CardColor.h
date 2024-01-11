#pragma once

enum class card_color
{
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    YELLOW = 3,
};

static card_color IntToEnumColor(int color_id);

static bool ColorEquals(const card_color color1, const card_color color2);
