#ifndef MAP_HPP
#define MAP_HPP
#include "mapobject.hpp"
#include<vector>

namespace RPG {
    class Map {
    protected:
        std::vector<MapObject*> ls;
        std::vector<std::vector<char> > mp;
    public:
        Map(unsigned height=5, unsigned width=10)
        {
            std::vector<char> temp;
            for (unsigned i=0; i<width; ++i)
            {
                temp.push_back(' ');
            }
            for (unsigned i=0; i<height; ++i)
            {
                mp.push_back(temp);
            }
        }
        void draw();
        void reset();
        void addMapObject(MapObject*);
    };
}
#endif // MAP_HPP
