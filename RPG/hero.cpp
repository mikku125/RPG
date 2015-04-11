#include<iostream>
#include "hero.hpp"

namespace RPG {

    void Hero::info() const
    {
        std::cout << name << '\t' << dmg << '\t' << hp << '\t' << exp << '\t' << xpos << '\t' << ypos << '\t' << std::endl;
    }
    void Hero::move(char dir)
    {
        switch (dir)
        {
            case 'w' :
                ++ypos;
                break;
            case 's' :
                --ypos;
                break;
            case 'a' :
                --xpos;
                break;
            case 'd' :
                ++xpos;
                break;
        }
    }
}
