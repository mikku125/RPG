#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP
#include "object.hpp"

namespace RPG {
    class MapObject : public Object {
    protected:
        unsigned xpos;
        unsigned ypos;
        char symbol;
        bool movable;
    public:
        MapObject(const std::string& str="noname",unsigned x=0,unsigned y=0,char c='X',bool b=false)
        : Object(str), xpos(x), ypos(y), symbol(c), movable(b)
        {}
        virtual void info() const;
        virtual const unsigned& getXpos() const
        {
            return xpos;
        }
        virtual const unsigned& getYpos() const
        {
            return ypos;
        }
        virtual const char& getSym() const
        {
            return symbol;
        }
        virtual ~MapObject(){}
    };
}

#endif // MAPOBJECT_HPP
