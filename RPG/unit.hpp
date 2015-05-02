#ifndef UNIT_HPP
#define UNIT_HPP

#include "mapobject.hpp"

namespace Rpg
{
    class Unit : public MapObject
    {
    protected:
        int hp;
        int maxHp;
        int dmg;
    public:
        Unit(std::string name="name", char s='X', unsigned x=0, unsigned y=0, int h=10, int d=1)
        : MapObject(name,s,x,y) , hp(h), maxHp(h), dmg(d) {}

        virtual void info() const;
        void moveW();
        void moveS();
        void moveA();
        void moveD();
        virtual unsigned call() const;
    };
}
#endif // PLAYER_HPP
