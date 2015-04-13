#include<iostream>
#include "hero.hpp"

namespace RPG {

    void Hero::info() const
    {
        std::cout << name << '\t' << dmg << '\t' << hp << '\t' << exp << '\t' << xpos << '\t' << ypos << '\t' << std::endl;
    }
    void Hero::move()
    {
        char dir;
        std::cin >> dir;
        switch (dir)
        {
            case 'w' :
                --xpos;
                break;
            case 's' :
                ++xpos;
                break;
            case 'a' :
                --ypos;
                break;
            case 'd' :
                ++ypos;
                break;
            default :
                break;
        }
    }
}
