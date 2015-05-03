#include "player.hpp"
#include <iostream>

namespace Rpg
{
    void Player::info() const
    {
        std::cout << "You are " << name << '\n'
        << "hitpoints: " << hp << " of " << maxHp << '\n'
        << "damage: " << dmg << std::endl;
    }


    void Player::move(bool *stop)
    {
        char key;
        std::cin >> key;
        switch (key)
        {
        case 'w':
            moveW();
            break;
        case 's':
            moveS();
            break;
        case 'a':
            moveA();
            break;
        case 'd':
            moveD();
            break;
        case 'i':
            openInv();
            break;
        case '=':
            *stop = false;
            break;
        }
    }

    unsigned Player::call() const
    {
        return 0;
    }

    void Player::openInv()
    {
        char key;
        bool stop = true;
        while (stop)
        {
            std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
            if (itemsVec.size()!=0)
            {
                Inventory::info();
                std::cin>>key;
            }
            else
            {
                std::cout << "Inventory is empty" << std::endl;
                std::cin >> key;
                key = '=';
            }
            switch (key)
            {
            case 'w':
                moveCursorUp();
                break;
            case 's':
                moveCursorDown();
                break;
            case 'u':
                useItem();
                break;
            case '=':
                stop = false;
                break;
            }
        }
    }

    void Player::useItem()
    {
        if (getItem(cursor)->isOneUse() )
        {
            if (getItem(cursor)->getRepHp() )
            {
                if ( (maxHp-hp)<getItem(cursor)->getRepHp() )
                {
                    hp+=maxHp-hp;
                }
                else
                {
                    hp+=getItem(cursor)->getRepHp();
                }
            }
            removeItem(cursor);
        }
        else  if (getItem(cursor)->isEquip() )
        {
            if (getItem(cursor)->getIncHp() )
            {
                maxHp-=getItem(cursor)->getIncHp();
                hp = (hp>maxHp) ? (maxHp) : (hp);
            }
            if (getItem(cursor)->getIncDmg() )
            {
                dmg-=getItem(cursor)->getIncDmg();
            }
            getItem(cursor)->equipItem();
        }
        else
        {
            if (getItem(cursor)->getIncHp() )
            {
                maxHp+=getItem(cursor)->getIncHp();
            }
            if (getItem(cursor)->getIncDmg() )
            {
                dmg+=getItem(cursor)->getIncDmg();
            }
            getItem(cursor)->equipItem();
        }
    }

    void Player::openCont(Cont* cont, Map* map)
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
                takeItem(cont);
                break;
            case '=':
                stop = false;
                break;
            }
        }
    }

    void Player::fightUnit(Unit* unit, Map* map)
    {
        std::cout << "Fight!" << std::endl;
        char key;
        bool stop = true;
        while ( stop )
        {
            std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
            if (getHp() <1 )
            {
                key = '=';
            }
            else if (unit->getHp() > 0)
            {
                unit->info();
                std::cout << std::endl;
                Player::info();
                std::cin >> key;
            }
            else
            {
                std::cout << "Enemy is defeated!" << std::endl;
                std::cin >> key;
                map->removeMapObj(unit);
                key = '=';
            }
            switch (key)
            {
            case 'u':
                std::cout << "Hit!" << std::endl;
                unit->changeHp(- dmg );
                changeHp(- unit->getDmg() );
                break;
            case '=':
                if (unit->getHp() > 0)
                {
                    changeHp(- unit->getDmg() );
                }
                stop = false;
                break;
            }
        }
    }
}
