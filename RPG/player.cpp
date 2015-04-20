#include <iostream>

#include "player.hpp"

namespace RPG
{
    void Player::info() const
    {
        std::cout << "This is level " << lvl << " " << name << '\n'
        << "number of hitpoints is " << hp << " of " << maxHp <<'\n'
        << "number of magicpoints is " << mp << " of " << maxMp << '\n'
        << "damage is " << dmg << '\n'
        << "position is : " << xpos << " , " << ypos << std::endl << std::endl;
    }

    void Player::movePlayer(bool* stop, Map* stage)
    {
        char key;
        std::cin >> key;
        switch (key)
        {
        case 'a':
            --ypos;
            break;
        case 'd':
            ++ypos;
            break;
        case 'w':
            --xpos;
            break;
        case 's':
            ++xpos;
            break;
        case 'i':
            openInventory();
            break;
        case '=':
            *stop = true;
            break;
        }
        unsigned marker;
        if ( check(stage) != this )
        {
            marker = check(stage) -> action();
        }
        switch (marker)
        {
        case 0:
            std::cout << "0";
            break;
        case 1:
            std::cout << "1";
            break;
        case 2:
            std::cout << "2";
            break;
        }
    }

    MapObject* Player::check(Map* stage)
    {
        for (unsigned i=0; i<stage->getLsSize(); ++i)
        {
            if ( stage->getMapObject(i)->getPos() == getPos() )
            {
                if ( stage->getMapObject(i) != this )
                {
                    return stage->getMapObject(i);
                }
            }
        }
        return this;
    }

    void Player::openInventory()
    {
        Inventory::info();
    }

}
