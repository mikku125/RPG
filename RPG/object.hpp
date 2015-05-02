#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

namespace Rpg
{
    class Object
    {
    protected:
        std::string name;
        Object(std::string name="name")
        : name(name) {}

    public:
        virtual void info() const = 0;
        ~Object() {}
    };
}
#endif // OBJECT_HPP
