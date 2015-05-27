#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "unit.hpp"
#include "map.hpp"

namespace Rpg
{
    class Fight
    {
    public:
        void startFight(Unit*,Unit*,Map*);
    };
}
#endif // FIGHT_HPP
