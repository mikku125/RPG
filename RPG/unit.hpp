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
        Unit(const std::string& str,unsigned x=0,unsigned y=0,int h=1,int d=1,char c='X')
        : MapObject(str,x,y,c,true), hp(h), dmg(d), lvl(1)
        {}
        virtual void info() const;
        virtual void moveLeft() ;
        virtual void moveRight() ;
        virtual void moveUp() ;
        virtual void moveDown() ;
        virtual void levelUp();
        virtual ~Unit(){}
    };
}

#endif // UNIT_HPP
