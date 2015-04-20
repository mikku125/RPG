#include<iostream>

#include "mapobject.hpp"

namespace RPG {

    void MapObject::info() const
    {
        std::cout << "this is " << name << '\n'
        << "symbol is " << symbol << '\n'
        << "position is : " << xpos << " , " << ypos << std::endl << std::endl;
    }

    unsigned MapObject::action()
    {
        return 0;
    }

}
