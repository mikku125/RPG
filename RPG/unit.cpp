#include "unit.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
        if (xpos > 0)
        {
            --xpos;
        }
    }

    void Unit::moveS()
    {
        if (xpos < 14)
        {
            ++xpos;
        }
    }

    void Unit::moveA()
    {
        if (ypos > 0)
        {
            --ypos;
        }
    }

    void Unit::moveD()
    {
        if (ypos < 14)
        {
            ++ypos;
        }
    }

    void Unit::move()
    {
        srand(time(NULL) );
        unsigned i = rand() % 4;
        switch (i)
        {
        case 0:
            moveW();
            break;
        case 1:
            moveS();
            break;
        case 2:
            moveA();
            break;
        case 3:
            moveD();
            break;
        }
    }

    unsigned Unit::call() const
    {
        return 1;
    }
}
