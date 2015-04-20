#ifndef CONT_HPP
#define CONT_HPP

#include "mapobject.hpp"
#include "inventory.hpp"

namespace RPG
{
    class Cont : public MapObject , public Inventory
    {
    public:
        Cont(const std::string& str="noname",char c='X',unsigned x=0,unsigned y=0,bool b=false)
        : MapObject(str,c,x,y,b)
        {}

        void info() const;

        unsigned action();
    };
}
#endif // CONT_HPP
