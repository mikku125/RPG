#ifndef HERO_HPP
#define HERO_HPP
#include "mapobject.hpp"

namespace RPG {
    class Hero : public MapObject {
    protected:
        int dmg;
        int hp;
    public:
        Hero(const std::string& str,int x=0,int y=0,int d=1,int h=1)
        : MapObject(str,x,y,true), dmg(d), hp(h)
        {

        }
        virtual void info() const;
        virtual ~Hero()
        {

        }
    };
}

#endif // HERO_HPP
