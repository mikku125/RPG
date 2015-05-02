#include <iostream>

#include "cont.hpp"

namespace Rpg
{
    void Cont::info() const
    {
        MapObject::info();
        std::cout << "that contains:" << std::endl;
        std::cout << std::endl;
        Inventory::info();
    }

    unsigned Cont::call() const
    {
        return 2;
    }

}
