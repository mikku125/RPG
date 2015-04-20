#include <iostream>

#include "cont.hpp"

namespace RPG
{
    void Cont::info() const
    {
        MapObject::info();
        Inventory::info();
    }

    unsigned Cont::action()
    {
        return 1;
    }

}
