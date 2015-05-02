#ifndef MAP_HPP
#define MAP_HPP

#include "mapobject.hpp"
#include "unit.hpp"
#include "player.hpp"

#include <vector>

namespace Rpg
{
    class Map
    {
    protected:
        std::vector<MapObject*> mapObjVec;
        char mp[15][15];

    public:
        Map()
        {
            for (unsigned i=0; i<15; ++i)
            {
                for (unsigned j=0; j<15; ++j)
                {
                    mp[i][j]=' ';
                }
            }
        }

        unsigned findMapObj(MapObject*);

        MapObject* getMapObj(const unsigned& i)
        {
            return mapObjVec[i];
        }

        void removeMapObj(const unsigned&);
        void removeMapObj(MapObject*);

        unsigned getSize()
        {
            return mapObjVec.size();
        }

        void addMapObj(MapObject*);
        void resetMap();
        void updateMap();
        void draw();
    };
}
#endif // MAP_HPP
