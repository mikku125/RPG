#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "object.hpp"
#include "effect.hpp"

namespace Rpg
{
    class Item : public Object, public Effect
    {
    protected:
        bool oneUse;
        int dur;
        int maxDur;

    public:
        Item(std::string str, bool o=true, int d = 0,
             int hp=0, int dmg=0, int rhp=0)
        : Object(str), Effect(hp,dmg,rhp), oneUse(o), dur(d), maxDur(d)
        {}

        virtual void info() const;

        virtual void useItem();

        bool& isOneUse()
        {
            return oneUse;
        }

        virtual ~Item(){};
    };
}
#endif // ITEM_HPP
