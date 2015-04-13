#ifndef MAP_HPP
#define MAP_HPP
#include "mapobject.hpp"
#include<vector>

namespace RPG {
    class Map {
    protected:
        std::vector<MapObject*> ls;
    public:
        Map(){}
        void draw() const;
        void addMapObject(MapObject*);
    };
}
#endif // MAP_HPP
