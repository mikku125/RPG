#ifndef CONT_HPP
#define CONT_HPP

#include "mapobject.hpp"
#include "inventory.hpp"

namespace Rpg
{
    class Cont : public MapObject , public Inventory
    {
    public:
        Cont(const std::string& str = "noname", char c = 'X', unsigned x = 0, unsigned y = 0)
        : MapObject(str,c,x,y), Inventory()
        {}

        void info() const;
        virtual unsigned call() const;
        unsigned action();
    };
}
#endif // CONT_HPP
