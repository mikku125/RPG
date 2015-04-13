#include "game.hpp"
#include "map.hpp"
#include "unit.hpp"
#include "hero.hpp"

namespace RPG {
    void Game::startGame(){
        bool stop = false;
        while(!stop)
        {
            RPG::Hero hero("warrior",1,1,5,1,'H');
            RPG::Unit monster("goblin",3,7,1,1,'G');
            RPG::Unit thing("chest",3,3,'C');
            monster.info();
            RPG::Map lvlMap;
            lvlMap.addMapObject(&hero);
            lvlMap.addMapObject(&monster);
            lvlMap.addMapObject(&thing);
            lvlMap.draw();
            hero.move();
            monster.moveRight();
            lvlMap.draw();
            hero.move();
            monster.moveRight();
            lvlMap.draw();
            hero.move();
            monster.moveUp();
            lvlMap.draw();
            stop= true;
        }
    }
}
