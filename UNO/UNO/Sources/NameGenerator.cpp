#include "NameGenerator.h"

NameGenerator::NameGenerator()
{
}

std::string NameGenerator::GetName()
{
    const int name_id = rand() % names_.size();
    std::string name = names_[name_id];
    names_.erase(names_.begin() + name_id);
    return name;
}

void NameGenerator::GenerateNames()
{
    names_.clear();
    names_ = {
        "Mateus",
        "Caio",
        "Rafael",
        "Pedro",
        "Taveiros",
        "Bruno",
        "Joao Wang",
        "Ezio Otaku",
        "Nave Enum",
        "Rofli",
        "Moises"
    };
}
