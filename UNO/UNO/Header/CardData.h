#pragma once

enum class card_color
{
    NONE = 0,
    RED = 1,
    GREEN = 2,
    BLUE = 3,
    YELLOW = 4,
    WILD = 5
};

enum class card_type
{
    NUMBER = 0,
    PLUS_TWO = 1,
    SKIP = 2,
    REVERSE = 3,
    WILD = 4,
    SWAP = 5
};

static card_color IntToEnumColor(int color_id);

static bool ColorEquals(const card_color color1, const card_color color2);
