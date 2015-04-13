#include<iostream>
#include "unit.hpp"

namespace RPG {
    void Unit::info() const
    {
        std::cout << "This is level " << lvl << " " << name << '\n'
        << "Number of hitpoints " << hp << '\n'
        << "Damage is " << dmg << '\n'
        << "position is : " << xpos << " , " << ypos << std::endl;
    }
    void Unit::levelUp()
    {
        ++lvl;
    }
    void Unit::move(const char& dir)
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
