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
            --xpos;
            break;
        case 's':
            ++xpos;
            break;
        case 'a':
            --ypos;
            break;
        case 'd':
            ++ypos;
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
}
