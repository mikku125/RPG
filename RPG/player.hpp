#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "unit.hpp"
#include "inventory.hpp"
#include "cont.hpp"
#include "map.hpp"

namespace Rpg
{
    class Player : public Unit, public Inventory
    {
    protected:

    public:
        Player(std::string name="name", char s='H', unsigned x=0, unsigned y=0, int h=10, int d=1)
        : Unit(name,s,x,y,h,d) {}

        void useItem();
        virtual void info() const;
        virtual unsigned call() const;
        void move(bool*);
        void openInv();
        void openCont(Cont*,Map*);
        void fightUnit(Unit*,Map*);
    };
}
#endif // PLAYER_HPP
