#include<iostream>
#include "unit.hpp"
#include "mapobject.hpp"

namespace RPG {
    void Unit::info() const
    {
        std::cout << "This is level " << lvl << " " << name << '\n'
        << "Number of hitpoints is " << hp << '\n'
        << "Damage is " << dmg << '\n'
        << "position is : " << xpos << " , " << ypos << std::endl;
    }
    void Unit::levelUp()
    {
        ++lvl;
    }
    void Unit::moveLeft()
    {
        --ypos;
    }
    void Unit::moveRight()
    {
        ++ypos;
    }
    void Unit::moveUp()
    {
        --xpos;
    }
    void Unit::moveDown()
    {
        ++xpos;
    }
}
