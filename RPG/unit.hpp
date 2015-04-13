#ifndef UNIT_HPP
#define UNIT_HPP
#include<string>
#include "mapobject.hpp"

namespace RPG {
    class Unit : public MapObject {
    protected :
        int hp;
        int dmg;
        int lvl;
    public :
        Unit(const std::string& str,unsigned x=0,unsigned y=0,int h=1,int d=1)
        : MapObject(str,x,y,true), hp(h), dmg(d), lvl(1)
        {}
        virtual void info() const;
        virtual void move(const char&);
        virtual void levelUp();
        virtual ~Unit(){}
    };
}

#endif // UNIT_HPP
