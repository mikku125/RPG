#ifndef HERO_HPP
#define HERO_HPP
#include "mapobject.hpp"
#include "map.hpp"

namespace RPG {
    class Hero : public MapObject {
    protected:
        int hp;
        int dmg;
        int lvl;
    public:
        Hero(const std::string& str,unsigned x=0,unsigned y=0,int h=1,int d=1,char c='X')
        : MapObject(str,x,y,c,true), hp(h), dmg(d), lvl(1)
        {

        }
        virtual void info() const;
        virtual void move(const Map&);
        virtual void levelUp();
        bool isSpotEmpty(const Map&,const unsigned&,const unsigned&);
        virtual ~Hero(){}
    };
}

#endif // HERO_HPP
