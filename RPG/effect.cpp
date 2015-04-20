#include <iostream>

#include "effect.hpp"

namespace RPG
{
    void Effect::info() const
    {
        if (incHp)
        {
            std::cout << "increase hp by " << incHp << std::endl;
        }
        if (incMp)
        {
            std::cout << "increase mp by " << incMp << std::endl;
        }
        if (incDmg)
        {
            std::cout << "increase dmg by " << incDmg << std::endl;
        }
        if (repHp)
        {
            std::cout << "replenishes " << repHp << " hp" << std::endl;
        }
        if (repMp)
        {
            std::cout << "replenishes " << repMp << " mp" << std::endl;
        }
    }
}
