#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "object.hpp"
#include "effect.hpp"

namespace RPG
{
    class Item : public Object, public Effect
    {
    protected:
        bool oneUse;
        int dur;
        int maxDur;

    public:
        Item(const std::string& str, const bool& o=true, const int& d = 0, const int& mD = 0,
             const int& hp=0, const int& mp=0, const int& dmg=0, const int& rhp=0, const int& rmp=0)
        : Object(str), Effect(hp,mp,dmg,rhp,rmp), oneUse(o), dur(d), maxDur(mD)
        {}

        virtual void info() const;

        virtual void useItem();

        virtual ~Item(){};
    };
}
#endif // ITEM_HPP
