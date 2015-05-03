#include "map.hpp"

#include <iostream>

namespace Rpg
{
    unsigned Map::findMapObj(MapObject* mapObj)
    {
        for (unsigned i=0; i<mapObjVec.size(); ++i)
        {
            if (mapObj == mapObjVec[i] )
            {
                return i;
            }
        }
        return 0;
    }

    void Map::addMapObj(MapObject* mapObj)
    {
        mapObjVec.push_back(mapObj);
    }

    void Map::removeMapObj(const unsigned& i)
    {
        for (unsigned j=i; j<mapObjVec.size()-1; ++j)
        {
            mapObjVec[j] = mapObjVec[j+1];
        }
        mapObjVec.pop_back();
    }

    void Map::removeMapObj(MapObject* mapObj)
    {
        unsigned i = findMapObj(mapObj);
        for (unsigned j=i; j<mapObjVec.size()-1; ++j)
        {
            mapObjVec[j] = mapObjVec[j+1];
        }
        mapObjVec.pop_back();
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
        for (unsigned i=0; i<mapObjVec.size(); ++i)
        {
            mp[mapObjVec[i]->getXpos() ][mapObjVec[i]->getYpos() ] = mapObjVec[i]->getSym();
        }
    }

    void Map::draw()
    {
        resetMap();
        updateMap();

        std::cout << "\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n \n\n\n\n\n";
        std::cout << "wsad - move, u - use/attack, i - open inventory, = - quit game/menu/fight" << std::endl << std::endl;
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
