#pragma once
#include <memory>

enum class card_type;
enum class card_color;
class Card;

class CardFactory
{
public:
    [[nodiscard]] std::unique_ptr<Card> CreateWildPlusCard(int cards_to_draw) const;
    [[nodiscard]] std::unique_ptr<Card> CreateNumberCard(card_color color, card_type type, int number) const;
    [[nodiscard]] std::unique_ptr<Card> CreateReverseCard(card_color color, card_type type) const;
    [[nodiscard]] std::unique_ptr<Card> CreatePlusCard(card_color color, card_type type, int cards_to_draw) const;
    [[nodiscard]] std::unique_ptr<Card> CreateSkipCard(card_color color, card_type type) const;
    [[nodiscard]] std::unique_ptr<Card> CreateWildCard() const;
    [[nodiscard]] std::unique_ptr<Card> CreateSwapCard() const;
};
