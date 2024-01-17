#include "ColorUtils.h"

std::string& ColorUtils::GetColorName(const card_color color)
{
    colors_info_.find(color);
    return colors_info_[color]->name;
}

std::string& ColorUtils::GetColorDyeId(card_color color)
{
    colors_info_.find(color);
    return colors_info_[color]->color_dye_id;
}

std::map<card_color, std::shared_ptr<ColorInfo>> ColorUtils::colors_info_{
                        {card_color::RED, std::make_shared<ColorInfo>("Red", "Red")},
                        {card_color::YELLOW, std::make_shared<ColorInfo>("Yellow", "Yellow")},
                        {card_color::GREEN, std::make_shared<ColorInfo>("Green", "Green")},
                        {card_color::BLUE, std::make_shared<ColorInfo>("Blue", "Blue")}};
