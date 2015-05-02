#include<iostream>
#include "object.hpp"

namespace Rpg {

    void Object::info() const
    {
        std::cout << name << std:: endl;
    }
}
