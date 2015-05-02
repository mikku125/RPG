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
        unsigned nrMapObjs;
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
            nrMapObjs=0;
        }

        MapObject* operator[](const unsigned& i)
        {
            return mapObjVec[i];
        }
        MapObject* getMapObj(const unsigned& i)
        {
            return mapObjVec[i];
        }
        unsigned& getSize()
        {
            return nrMapObjs;
        }
        void addMapObj(MapObject*);
        void resetMap();
        void updateMap();
        void draw();
    };
}
#endif // MAP_HPP
