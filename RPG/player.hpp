#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "unit.hpp"
#include "cont.hpp"

namespace RPG
{
    class Player : public Unit
    {
    public:
        Player(const std::string& str="noname", const char& c='X', const unsigned& x=0, const unsigned& y=0, const bool& b=true,
             const int& h=1, const int& mH=1, const int& m=1, const int& mM=1, const int& d=1, const int& l=1)
        : Unit(str,c,x,y,b,hp,mH,mp,mM,d,l)
        {}

        void info() const;

        void movePlayer(bool*, Map*);

        void openInventory();

        MapObject* check(Map*);
    };
}
#endif // PLAYER_HPP
