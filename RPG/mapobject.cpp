#include<iostream>
#include "mapobject.hpp"

namespace RPG {

    void MapObject::info() const
    {
        std::cout << name << '\t' << xpos << '\t' << ypos << '\t' << movable << std::endl;
    }
}
