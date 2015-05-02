#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP

#include "object.hpp"
#include "pos.hpp"

namespace Rpg
{
    class MapObject : public Object, public Pos
    {
    protected:
        char sym;
    public:
        MapObject(std::string name="name", char s='X', unsigned x=0, unsigned y=0)
        : Object(name), Pos(x,y), sym(s) {}

        char& getSym()
        {
            return sym;
        }

        virtual void info() const;
        virtual unsigned call() const=0;
        ~MapObject() {}
    };
}
#endif // MAPOBJECT_HPP
