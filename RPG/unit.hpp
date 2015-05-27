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
        Unit(const std::string& name = "name", char s = 'X', unsigned x = 0, unsigned y = 0, int h = 10, int d = 1)
        : MapObject(name,s,x,y) , hp(h), maxHp(h), dmg(d) {}

        virtual void info() const;
        void moveW();
        void moveS();
        void moveA();
        void moveD();
        virtual void move();

        int getHp() const
        {
            return hp;
        }

        int getMaxHp() const
        {
            return maxHp;
        }

        int getDmg() const
        {
            return dmg;
        }

        void changeHp(unsigned i)
        {
            hp += i;
        }

        void changeMaxHp(unsigned i)
        {
            maxHp += i;
        }

        void changeDmg(unsigned i)
        {
            dmg += i;
        }

        virtual unsigned call() const;
    };
}
#endif // PLAYER_HPP
