#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP
#include "object.hpp"

namespace RPG {
    class MapObject : public Object {
    protected:
        unsigned xpos;
        unsigned ypos;
        bool movable;
    public:
        MapObject(const std::string& str="noname",unsigned x=0,unsigned y=0,bool b=false)
        : Object(str), xpos(x), ypos(y), movable(b)
        {}
        virtual void info() const;
        virtual unsigned getXpos() const
        {
            return xpos;
        }
        virtual unsigned getYpos() const
        {
            return ypos;
        }
        virtual ~MapObject()
        {}
    };
}

#endif // MAPOBJECT_HPP
