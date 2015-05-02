#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "unit.hpp"
#include "inventory.hpp"

namespace Rpg
{
    class Player : public Unit, public Inventory
    {
    protected:

    public:
        Player(std::string name="name", char s='H', unsigned x=0, unsigned y=0, int h=10, int d=1)
        : Unit(name,s,x,y,h,d) {}

        virtual void info() const;
        virtual unsigned call() const;
        void move(bool*);
        void openInv();
    };
}
#endif // PLAYER_HPP
