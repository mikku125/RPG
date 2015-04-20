#include<iostream>

#include "unit.hpp"

namespace RPG {
    void Unit::info() const
    {
        std::cout << "This is level " << lvl << " " << name << '\n'
        << "number of hitpoints is " << hp << " of " << maxHp << '\n'
        << "number of magicpoints is " << mp << " of " << maxMp << '\n'
        << "damage is " << dmg << '\n'
        << "position is : " << xpos << " , " << ypos << std::endl << std::endl;
    }

    void Unit::moveL()
    {
       --ypos;
    }

    void Unit::moveR()
    {
        ++ypos;
    }

    void Unit::moveU()
    {
        --xpos;
    }

    void Unit::moveD()
    {
        ++xpos;
    }

    unsigned Unit::action()
    {
        return 2;
    }
}
