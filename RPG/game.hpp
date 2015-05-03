#ifndef GAME_HPP
#define GAME_HPP

#include "map.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "pos.hpp"
#include "cont.hpp"

namespace Rpg
{
    class Game
    {
    protected:
        Player* p1;
    public:
        Game()
        {}

        void assignPlayer(Player* player)
        {
            p1 = player;
        }
        void startGame();
        void checkMap(Map*,bool*);
        void fightUnit(Unit*,Map*);
        void openCont(Cont*,Map*);
    };
}
#endif // GAME_HPP
