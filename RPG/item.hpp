#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "object.hpp"
#include "effect.hpp"
#include "unit.hpp"

namespace Rpg
{
    class Item : public Object, public Effect
    {
    protected:
        bool oneUse;
        bool equip;
        int dur;
        int maxDur;

    public:
        Item(std::string str, bool o=true, bool e=false, int d = 0,
             int hp=0, int dmg=0, int rhp=0)
        : Object(str), Effect(hp,dmg,rhp), oneUse(o), equip(e), dur(d), maxDur(d)
        {}

        virtual void info() const;

        bool& isOneUse()
        {
            return oneUse;
        }

        bool& isEquip()
        {
            return equip;
        }

        void equipItem()
        {
            equip = !equip;
        }

        virtual ~Item(){};
    };
}
#endif // ITEM_HPP
