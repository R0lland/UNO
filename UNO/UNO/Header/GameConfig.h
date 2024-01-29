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
    static int constexpr NUMBER_OF_WILD_PLUS_CARDS = 4;
    static int constexpr NUMBER_OF_SWAP_CARDS = 2;
    static int constexpr NUMBER_OF_SKIP_CARDS = 2;
    static int constexpr NUMBER_OF_DISCARD_PLUS_CARDS = 1;
    
    static int constexpr PLUS_CARD_NUMBER_TO_DRAW = 2;
    static int constexpr WILD_CARD_NUMBER_TO_DRAW = 4;
    static int constexpr SKIP_CARD_NUMBER_TO_SKIP = 2;

    //Deal Cards
    static int constexpr NUMBER_OF_CARDS_TO_DEAL = 2;
    static int constexpr NUMBER_OF_CARDS_TO_DRAW_IF_PLAYER_DIDNT_SHOUT_UNO = 2;

    //Total Cards
    //static int constexpr TOTAL_CARDS = ((MAX_NUMBER_CARD+1)*NUMBER_OF_CARDS_EQUALS) + NUMBER_OF_PLUS_CARDS + NUMBER_OF_REVERSE_CARDS + (NUMBER_OF_WILD_CARDS*2) + NUMBER_OF_SKIP_CARDS;
};
