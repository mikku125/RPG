#include<iostream>
#include "unit.hpp"

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
    void Unit::moveLeft(const Map& m)
    {
        if (isSpotEmpty(m,xpos,ypos-1) )
        {
            --ypos;
        }
    }
    void Unit::moveRight(const Map& m)
    {
        if (isSpotEmpty(m,xpos,ypos+1) )
        {
            ++ypos;
        }
    }
    void Unit::moveUp(const Map& m)
    {
        if (isSpotEmpty(m,xpos-1,ypos) )
        {
            --xpos;
        }
    }
    void Unit::moveDown(const Map& m)
    {
        if (isSpotEmpty(m,xpos+1,ypos) )
        {
            ++xpos;
        }
    }
    bool Unit::isSpotEmpty(const Map& m, const unsigned& x, const unsigned& y)
    {
        if (m.getMapSym(x,y)==' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
