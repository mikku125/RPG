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
        Inventory::info();
        unsigned i;
        std::cout << "Use item? 0-no, 1-first... \n";
        std::cin >> i;
        if (i!=0)
        {
            if (inv[i-1]->isOneUse() )
            {
                inv[i-1]->info();
                inv[i-1]->applyEffects(this);
                removeItem(i-1);
            }
            else
            {
                inv[i-1]->info();
                inv[i-1]->applyEffects(this);
            }

        }
    }
}
