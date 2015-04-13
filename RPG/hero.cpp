#include<iostream>
#include "hero.hpp"

namespace RPG {

    void Hero::info() const
    {
        std::cout << "This is level " << lvl << " " << name << '\n'
        << "Number of hitpoints is " << hp << '\n'
        << "Damage is " << dmg << '\n'
        << "position is : " << xpos << " , " << ypos << std::endl;
    }
    void Hero::levelUp()
    {
        ++lvl;
    }
    void Hero::move(const Map& m)
    {
        char dir;
        std::cin >> dir;
        switch (dir)
        {
            case 'w' :
                if (isSpotEmpty(m,xpos-1,ypos) )
                {
                    --xpos;
                }
                break;
            case 's' :
                if (isSpotEmpty(m,xpos+1,ypos) )
                {
                    ++xpos;
                }
                break;
            case 'a' :
                if (isSpotEmpty(m,xpos,ypos-1) )
                {
                    --ypos;
                }
                break;
            case 'd' :
                if (isSpotEmpty(m,xpos,ypos+1) )
                {
                    ++ypos;
                }
                break;
            default :
                break;
        }
    }
    bool Hero::isSpotEmpty(const Map& m, const unsigned& x, const unsigned& y)
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
