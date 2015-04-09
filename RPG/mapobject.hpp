#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP
#include "object.hpp"

namespace RPG {
    class MapObject : public Object {
    protected:
        int xpos;
        int ypos;
        bool movable;
    public:
        MapObject(const std::string& str="noname",int x=0,int y=0,bool b=false)
        : Object(str), xpos(x), ypos(y), movable(b)
        {

        }
        virtual void info() const;
        virtual ~MapObject()
        {

        }
    };
}

#endif // MAPOBJECT_HPP
