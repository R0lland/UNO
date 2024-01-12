#pragma once

enum class card_color
{
    NONE = 0,
    RED = 1,
    GREEN = 2,
    BLUE = 3,
    YELLOW = 4,
};

static card_color IntToEnumColor(int color_id);

static bool ColorEquals(const card_color color1, const card_color color2);
