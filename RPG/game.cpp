#include "game.hpp"

#include <iostream>

namespace Rpg
{
    void Game::startGame()
    {
        bool stop = true;
        Player player;
        assignPlayer(&player);
        Unit unit1("goblin",'G',3,4,5,3);
        Unit unit2("goblin",'G',7,7,5,3);
        Unit unit3("ogre",'O',5,5,10,10);
        Item item1("potion",true,false,0,0,0,10);
        Item item2("sword",false,false,10,0,1,0);
        Cont cont("chest",'C',2,7);
        cont.addItem(&item1);
        cont.addItem(&item2);
        Map map;
        map.addMapObj(&player);
        map.addMapObj(&unit1);
        map.addMapObj(&unit2);
        map.addMapObj(&unit3);
        map.addMapObj(&cont);
        p1->info();
        //map.draw();
        while (stop)
        {
            map.draw();
            unit3.move();
            player.move(&stop);
            checkMap(&map,&stop);
            if (p1->getHp() < 1 )
            {
                std::cout << "You lose!" << std::endl;
                stop = false;
            }
            if (unit1.getHp() < 1 && unit2.getHp() < 1)
            {
                std::cout << "You win!" << std::endl;
                stop = false;
            }
        }
    }

    void Game::checkMap(Map* map, bool* stop)
    {
        for (unsigned i = 1; i < map->getSize(); ++i)
        {
            if ( map->getMapObj(i)->getPos() == p1->getPos() )
            {
                if ( map->getMapObj(i)->call() == 1 )
                {
                    Unit *unit = dynamic_cast<Unit*>(map->getMapObj(i) );
                    Fight fight;
                    fight.startFight(p1,unit,map);
                }
                if ( map->getMapObj(i)->call() == 2 )
                {
                    Cont *cont = dynamic_cast<Cont*>(map->getMapObj(i) );
                    p1->openCont(cont,map);
                }
            }
        }
    }
}
