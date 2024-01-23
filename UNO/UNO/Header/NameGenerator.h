#pragma once
#include <string>
#include <vector>

class NameGenerator
{
    std::vector<std::string> names_{
        "Mateus",
        "Tony",
        "Jason",
        "Vivek",
        "Sebastian",
        "Malenia",
        "Tabares",
        "Breno",
        "Joao",
        "Peter",
        "Nave",
        "Rofli"
    };
public:
    NameGenerator();
    std::string GetName();
};
