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

    void Effect::applyEffects(Unit* unit)
    {
        if (incHp)
        {
            unit->changeMaxHp(incHp);
        }
        if (incDmg)
        {
            unit->changeDmg(incDmg);
        }
        if (repHp)
        {
            if ( (unit->getMaxHp() - unit->getHp() )<repHp )
            {
                repHp = (unit->getMaxHp() - unit->getHp() );
            }
            unit->changeHp(repHp);
        }
    }
}
