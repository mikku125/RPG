#include <iostream>

#include "game.hpp"

namespace RPG {
    void Game::startGame(){
        bool stop = false;
        Map stage(15,15);
        Player hero("warrior",'H',1,1,true,20,20,0,0,1);
        Unit unit("goblin",'G',3,5,true,10,10,0,0,4,1);
        Cont cont("chest",'C',3,1);
        Item item1("potion",true,0,0,0,0,0,10,0);
        Item item2("sword",false,20,20,0,0,2,0,0);
        stage.addMapObject(&hero);
        stage.addMapObject(&unit);
        stage.addMapObject(&cont);
        cont.addItem(&item1);
        cont.addItem(&item2);
        hero.info();
        unit.info();
        cont.info();
        stage.draw();

        while(!stop)
        {
            hero.movePlayer(&stop,&stage);
            stage.draw();
        }
    }
}
