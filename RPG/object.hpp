#ifndef OBJECT_HPP
#define OBJECT_HPP

#include<string>

namespace RPG {
    class Object {
    protected:
        std::string name;
        Object(const std::string& str = "noname" )
        : name(str)
        {}
    public:
        virtual void info() const = 0;
        virtual ~Object(){};
    };
}
#endif // OBJECT_HPP
