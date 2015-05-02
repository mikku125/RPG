#include "game.hpp"

#include <iostream>

namespace Rpg
{
    void Game::startGame()
    {
        bool stop = true;
        Player player;
        assignPlayer(&player);
        Unit unit("goblin",'G',3,4,5,1);
        Map map;
        map.addMapObj(&player);
        map.addMapObj(&unit);
        map.draw();
        while (stop)
        {
            checkMap(&map);
            player.move(&stop);
            map.draw();
        }
    }

    void Game::checkMap(Map* map)
    {
        for (unsigned i=1; i<map->getSize(); ++i)
        {
            if (( map->getMapObj(i)->getPos() == p1->getPos() )&&( map->getMapObj(i)->call() == 1) )
            {
                Unit enemy = dynamic_cast<Unit&>(*(map->getMapObj(i) ) );
                startFight(&enemy);
            }
        }
    }

    void Game::startFight(Unit* unit)
    {
        std::cout << "fight!" << std::endl;
        char fKey='a';
        while (fKey!='r')
        {
            unit->info();
            std::cout << "(A)ttack or (R)un?" << '\n';
            std::cin >> fKey;
            if (fKey=='a')
            {
                std::cout << "hit!" << '\n';
            }
        }
    }
}
