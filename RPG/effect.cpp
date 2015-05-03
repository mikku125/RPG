#include <iostream>

#include "effect.hpp"

namespace Rpg
{
    void Effect::info() const
    {
        if (incHp)
        {
            std::cout << "increase hp by " << incHp << std::endl;
        }
        if (incDmg)
        {
            std::cout << "increase dmg by " << incDmg << std::endl;
        }
        if (repHp)
        {
            std::cout << "replenishes " << repHp << " hp" << std::endl;
        }
    }
}
