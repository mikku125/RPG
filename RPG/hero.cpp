#include<iostream>
#include "hero.hpp"

namespace RPG {

    void Hero::info() const
    {
        std::cout << name << '\t' << dmg << '\t' << hp << '\t' << xpos << '\t' << ypos << '\t' << std::endl;
    }
}
