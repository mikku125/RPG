#ifndef UNIT_HPP
#define UNIT_HPP

#include<string>

#include "inventory.hpp"
#include "mapobject.hpp"
#include "map.hpp"

namespace RPG {
    class Unit : public MapObject , public Inventory {
    protected :
        int hp;
        int maxHp;
        int mp;
        int maxMp;
        int dmg;
        int lvl;

    public :
        Unit(const std::string& str="noname", const char& c='X', const unsigned& x=0, const unsigned& y=0, const bool& b=false,
             const int& h=1, const int& mH=1, const int& m=1, const int& mM=1, const int& d=1, const int& l=1)
        : MapObject(str,c,x,y,b), hp(h), maxHp(mH), mp(m), maxMp(mM), dmg(d), lvl(l)
        {}

        virtual void info() const;

        void moveL();

        void moveR();

        void moveU();

        void moveD();

        unsigned action();

        virtual ~Unit(){}
    };
}

#endif // UNIT_HPP
