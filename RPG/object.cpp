#include<iostream>
#include "object.hpp"

namespace RPG {

    void Object::info() const
    {
        std::cout << name << std:: endl;
    }
}
