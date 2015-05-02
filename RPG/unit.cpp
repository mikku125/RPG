#include "unit.hpp"
#include <iostream>

namespace Rpg
{
    void Unit::info() const
    {
        std::cout << "This is " << name << '\n'
        << "hitpoints: " << hp << " of " << maxHp << '\n'
        << "damage: " << dmg << std::endl;
    }

    void Unit::moveW()
    {
        --xpos;
    }

    void Unit::moveS()
    {
        ++xpos;
    }

    void Unit::moveA()
    {
        --ypos;
    }

    void Unit::moveD()
    {
        ++ypos;
    }

    unsigned Unit::call() const
    {
        return 1;
    }
}
