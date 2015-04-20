#ifndef MAP_HPP
#define MAP_HPP

#include<vector>

#include "mapobject.hpp"

namespace RPG {
    class Map {
    protected:
        std::vector<MapObject*> ls;
        std::vector<std::vector<char> > stage;

    public:
        Map(unsigned height=15, unsigned width=15)
        {
            std::vector<char> temp;
            for (unsigned i=0; i<height; ++i)
            {
                for (unsigned j=0; j<width; ++j)
                {
                    temp.push_back(' ');
                }
                stage.push_back(temp);
                temp.clear();
            }
        }

        void addMapObject(MapObject*);

        const char& getSpot(const unsigned& x, const unsigned& y) const
        {
            return stage[x][y];
        }

        MapObject* getMapObject(const unsigned& i) const
        {
            return ls[i];
        }

        unsigned getLsSize()
        {
            return ls.size();
        }

        void reset();

        void update();

        bool check();

        void draw();
    };
}
#endif // MAP_HPP
