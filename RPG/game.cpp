#include "game.hpp"
#include "map.hpp"
#include "unit.hpp"

namespace RPG {
    void Game::startGame(){
        bool stop = false;
        while(!stop)
        {
            RPG::Unit monster("goblin",0,0,1,1);
            RPG::Unit thing("chest",3,3);
            monster.info();
            RPG::Map lvlMap;
            lvlMap.addMapObject(&monster);
            lvlMap.addMapObject(&thing);
            lvlMap.draw();
            monster.move('d');
            monster.move('d');
            monster.move('w');
            lvlMap.draw();
            stop= true;
        }
    }
}
