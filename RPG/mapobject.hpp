#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP

#include "object.hpp"
#include "pos.hpp"

namespace RPG {
    class MapObject : public Object , public Pos{
    protected:
        char symbol;
        bool movable;

    public:
        MapObject(const std::string& str="noname",char c='X',unsigned x=0,unsigned y=0,bool b=false)
        : Object(str), Pos(x,y), symbol(c), movable(b)
        {}

        virtual void info() const;

        const char& getSymb() const
        {
            return symbol;
        }

        virtual unsigned action();

        virtual ~MapObject(){}
    };
}

#endif // MAPOBJECT_HPP
