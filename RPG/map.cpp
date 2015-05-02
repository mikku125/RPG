#include "map.hpp"

#include <iostream>

namespace Rpg
{
    void Map::addMapObj(MapObject* mapObj)
    {
        mapObjVec.push_back(mapObj);
        ++nrMapObjs;
    }

    void Map::resetMap()
    {
        for (unsigned i=0; i<15; ++i)
        {
            for (unsigned j=0; j<15; ++j)
            {
                mp[i][j] = ' ';
            }
        }
    }

    void Map::updateMap()
    {
        for (unsigned i=0; i<nrMapObjs; ++i)
        {
            mp[mapObjVec[i]->getXpos() ][mapObjVec[i]->getYpos() ] = mapObjVec[i]->getSym();
        }
    }

    void Map::draw()
    {
        resetMap();
        updateMap();

        std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";

        for (unsigned i=0; i<17; ++i)
        {
            std::cout << "# ";
        }
        std::cout << '\n';

        for (unsigned i=0; i<15; ++i)
        {
            std::cout << "# ";
            for (unsigned j=0; j<15; ++j)
            {
                std::cout << mp[i][j] << ' ';
            }
            std::cout <<"# \n";
        }

        for (unsigned i=0; i<17; ++i)
        {
            std::cout << "# ";
        }
        std::cout << '\n';
    }
}
