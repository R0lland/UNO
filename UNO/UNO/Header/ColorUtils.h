﻿#pragma once
#include <map>
#include <memory>
#include <string>

#include "CardData.h"

class ColorInfo
{
public:
    std::string name;
    std::string color_dye_id;
};

class ColorUtils
{
    static std::map<card_color, std::shared_ptr<ColorInfo>> colors_info_;
public:
    
    static std::string& GetColorName(card_color color);
    static std::string& GetColorDyeId(card_color color);
    static void PrintColor(card_color color);
    static void PrintAllColorsWithId();
    static void PrintColorWithId(card_color color);

    static void PrintTextWithColor(const std::string& message, std::string color_id);
};
