#include "game.hpp"

#include <iostream>

namespace Rpg
{
    void Game::startGame()
    {
        bool stop = true;
        Player player;
        assignPlayer(&player);
        Unit unit("goblin",'G',3,4,5,3);
        Item item1("potion",true,0,0,0,10);
        Item item2("sword",false,10,0,1,0);
        Cont cont("chest",'C',5,5);
        cont.addItem(&item1);
        cont.addItem(&item2);
        Map map;
        map.addMapObj(&player);
        map.addMapObj(&unit);
        map.addMapObj(&cont);
        p1->info();
        //map.draw();
        while (stop)
        {
            map.draw();
            player.move(&stop);
            checkMap(&map,&stop);
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
                    fightUnit(unit,map,stop);
                }
                if ( map->getMapObj(i)->call() == 2 )
                {
                    Cont *cont = dynamic_cast<Cont*>(map->getMapObj(i) );
                    openCont(cont,map);
                }

            }
        }
    }

    void Game::fightUnit(Unit* unit, Map* map, bool* stop)
    {
        std::cout << "Fight!" << std::endl;
        char fKey='a';
        while (fKey!='r')
        {
            unit->info();
            std::cout << std::endl;
            p1->info();
            std::cout << "(A)ttack or (R)un?" << std::endl;
            std::cin >> fKey;
            if (fKey=='a')
            {
                std::cout << "Hit!" << std::endl;
                unit->changeHp(- p1->getDmg() );
                p1->changeHp(- unit->getDmg() );
            }
            if (unit->getHp() <1)
            {
                std::cout << "Enemy defeated! You win!" << std::endl;
                map->removeMapObj(unit);
                *stop = false;
                fKey = 'r';
            }
            if (p1->getHp() < 1)
            {
                std::cout << "You lose!" << std::endl;
                *stop = false;
                fKey = 'r';
            }
            map->draw();
        }
    }

    void Game::openCont(Cont* cont, Map* map)
    {
        char key;
        bool stop = true;
        while ( stop )
        {
            std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
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
