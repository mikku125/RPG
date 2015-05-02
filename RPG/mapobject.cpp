#include "mapobject.hpp"

#include <iostream>

namespace Rpg
{
    void MapObject::info() const
    {
        std::cout << "This is " << name << std::endl;
    }

    void MapObject::setSym(const char& c)
    {
        sym = c;
    }
}
