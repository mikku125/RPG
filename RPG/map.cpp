#include<iostream>
#include "map.hpp"

namespace RPG {
    void Map::draw()
    {
        Map::reset();
        for (unsigned i=0; i<ls.size(); ++i)
        {
            mp[ls[i]->getXpos()][ls[i]->getYpos()] = ls[i]->getSym();
        }
        for (unsigned i=0; i<(mp[0]).size()+2; ++i)
        {
            std::cout << '#';
        }
        std::cout << std::endl;
        for (unsigned i=0; i<mp.size(); ++i)
        {
            std::cout << '#';
            for (unsigned l=0; l<(mp[0]).size(); ++l)
            {
                std::cout << mp[i][l];
            }
            std::cout << '#' << std::endl;
        }
        for (unsigned i=0; i<(mp[0]).size()+2; ++i)
        {
            std::cout << '#';
        }
    }
    void Map::reset()
    {
        for (unsigned i=0; i<mp.size(); ++i)
        {
            for (unsigned l=0; l<(mp[0]).size(); ++l)
            {
                mp[i][l]=' ';
            }
        }
    }
    void Map::addMapObject(MapObject* mo)
    {
        ls.push_back(mo);
    }
}
