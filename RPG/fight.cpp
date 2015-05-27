#include "fight.hpp"

#include <iostream>

namespace Rpg
{
    void Fight::startFight(Unit* player, Unit* enemy, Map* map)
    {
        std::cout << "Fight!" << std::endl;
        char key;
        bool stop = true;
        while ( stop )
        {
            std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
            if (player->getHp() < 1 )
            {
                key = '=';
            }
            else if (enemy->getHp() > 0)
            {
                enemy->info();
                std::cout << std::endl;
                player->info();
                std::cin >> key;
            }
            else
            {
                std::cout << "Enemy is defeated!" << std::endl;
                std::cin >> key;
                map->removeMapObj(enemy);
                key = '=';
            }
            switch (key)
            {
            case 'u':
                std::cout << "Hit!" << std::endl;
                enemy->changeHp(- player->getDmg() );
                player->changeHp(- enemy->getDmg() );
                break;
            case '=':
                if (enemy->getHp() > 0)
                {
                    player->changeHp(- enemy->getDmg() );
                }
                stop = false;
                break;
            }
        }
    }
}
