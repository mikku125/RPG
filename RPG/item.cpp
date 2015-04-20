#include <iostream>

#include "item.hpp"

namespace RPG
{
    void Item::info() const
    {
        std::cout << "This is " << name << std::endl;
        if (oneUse)
        {
            std::cout << "One use only!" << std::endl;
        }
        else
        {
            std::cout << "Durability " << dur << " of " << maxDur << std::endl;
        }
        std::cout << "effect is: ";
        Effect::info();
    }

    void Item::useItem()
    {

    }
}
