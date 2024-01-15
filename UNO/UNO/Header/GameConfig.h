#pragma once

class GameConfig
{
public:
    //Players
    static int constexpr MIN_PLAYERS = 2;
    static int constexpr MAX_PLAYERS = 10;

    //Number Cards
    static int constexpr MIN_NUMBER_CARD = 0;
    static int constexpr MAX_NUMBER_CARD = 9;
    static int constexpr NUMBER_OF_CARDS_EQUALS = 2;

    //Special cards
    static int constexpr NUMBER_OF_PLUS_CARDS = 2;
    static int constexpr NUMBER_OF_REVERSE_CARDS = 2;
    static int constexpr NUMBER_OF_WILD_CARDS = 4;
    static int constexpr NUMBER_OF_SKIP_CARDS = 2;
    static int constexpr PLUS_CARD_NUMBER_TO_DRAW = 2;

    //Deal Cards
    static int constexpr NUMBER_OF_CARDS_TO_DEAL = 7;
};
