#include <iostream>

#include "item.hpp"

namespace Rpg
{
    void Item::info() const
    {
        std::cout << name << std::endl;
        if (oneUse)
        {
            std::cout << "One use only!" << std::endl;
        }
        else
        {
            if (equip)
            {
                std::cout << " - equipped" << std::endl;
            }
            std::cout << "Durability " << dur << " of " << maxDur << std::endl;
        }
        std::cout << "effect is: ";
        Effect::info();
    }

}
