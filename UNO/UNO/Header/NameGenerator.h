#pragma once
#include <string>
#include <vector>

class NameGenerator
{
    std::vector<std::string> names_{};
public:
    NameGenerator();
    std::string GetName();
    void GenerateNames();
};
