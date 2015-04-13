#ifndef UNIT_HPP
#define UNIT_HPP
#include<string>
#include "mapobject.hpp"
#include "map.hpp"

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
        virtual void moveLeft(const Map&) ;
        virtual void moveRight(const Map&) ;
        virtual void moveUp(const Map&) ;
        virtual void moveDown(const Map&) ;
        virtual void levelUp();
        bool isSpotEmpty(const Map&,const unsigned&,const unsigned&);
        virtual ~Unit(){}
    };
}

#endif // UNIT_HPP
