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
        Item item1("potion",true,false,0,0,0,10);
        Item item2("sword",false,false,10,0,1,0);
        Cont cont("chest",'C',5,5);
        cont.addItem(&item1);
        cont.addItem(&item2);
        Map map;
        map.addMapObj(&player);
        map.addMapObj(&unit1);
        map.addMapObj(&unit2);
        map.addMapObj(&cont);
        p1->info();
        //map.draw();
        while (stop)
        {
            map.draw();
            player.move(&stop);
            checkMap(&map,&stop);
            if (p1->getHp() <1 )
            {
                stop = false;
            }
            if (unit1.getHp()<1 && unit2.getHp()<1)
            {
                std::cout << "You win!" << std::endl;
                stop = false;
            }
        }
    }

    void Game::checkMap(Map* map, bool* stop)
    {
        for (unsigned i=1; i<map->getSize(); ++i)
        {
            if ( map->getMapObj(i)->getPos() == p1->getPos() )
            {
                if ( map->getMapObj(i)->call() == 1 )
                {
                    Unit *unit = dynamic_cast<Unit*>(map->getMapObj(i) );
                    fightUnit(unit,map);
                }
                if ( map->getMapObj(i)->call() == 2 )
                {
                    Cont *cont = dynamic_cast<Cont*>(map->getMapObj(i) );
                    openCont(cont,map);
                }

            }
        }
    }

    void Game::fightUnit(Unit* unit, Map* map)
    {
        std::cout << "Fight!" << std::endl;
        char key;
        bool stop = true;
        while ( stop )
        {
            std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
            if (unit->getHp() > 0)
            {
                unit->info();
                std::cout << std::endl;
                p1->info();
                std::cin >> key;
            }
            else
            {
                std::cout << "Enemy is defeated!" << std::endl;
                std::cin >> key;
                map->removeMapObj(unit);
                key = '=';
            }
            if (p1->getHp() <1 )
            {
                std::cout << "You lose!" << std::endl;
                std::cin >> key;
                key = '=';
            }
            switch (key)
            {
            case 'u':
                std::cout << "Hit!" << std::endl;
                unit->changeHp(- p1->getDmg() );
                p1->changeHp(- unit->getDmg() );
                break;
            case '=':
                stop = false;
                break;
            }
        }
    }

    void Game::openCont(Cont* cont, Map* map)
    {
        char key;
        bool stop = true;
        while ( stop )
        {
            std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
            if (cont->getSize()!=0)
            {
                cont ->info();
                std::cin >> key;
            }
            else
            {
                std::cout << "Chest is empty!" << std::endl;
                std::cin >> key;
                map->removeMapObj(cont);
                key = '=';
            }
            switch (key)
            {
            case 'w':
                cont->moveCursorUp();
                break;
            case 's':
                cont->moveCursorDown();
                break;
            case 'u':
                cont->giveItem(p1);
                break;
            case '=':
                stop = false;
                break;
            }
        }
    }
}
