#ifndef HERO_HPP
#define HERO_HPP
#include "mapobject.hpp"

namespace RPG {
    class Hero : public MapObject {
    protected:
        int dmg;
        int hp;
        int exp;
    public:
        Hero(const std::string& str,unsigned x=0,unsigned y=0,int d=1,int h=1,char c='X')
        : MapObject(str,x,y,c,true), dmg(d), hp(h), exp(0)
        {

        }
        virtual void info() const;
        virtual void move();
        virtual ~Hero(){}
    };
}

#endif // HERO_HPP
