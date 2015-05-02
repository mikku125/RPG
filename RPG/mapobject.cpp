#include "mapobject.hpp"

#include <iostream>

namespace Rpg
{
    void MapObject::info() const
    {
        std::cout << name << std::endl;
    }
}
