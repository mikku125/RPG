#include<iostream>
#include "map.hpp"

namespace RPG {
    void Map::draw()
    {
        std::cout << std::endl << std::endl << std::endl;
        Map::reset();
        for (int i=0; i<ls.size(); ++i)
        {
            mp[ls[i]->getXpos()][ls[i]->getYpos()] = ls[i]->getSym();
        }
        for (int i=0; i<mp.size(); ++i)
        {
            for (int l=0; l<(mp[0]).size(); ++l)
            {
                std::cout << mp[i][l];
            }
            std::cout << std::endl;
        }
    }
    void Map::reset()
    {
            for (int i=0; i<mp.size(); ++i)
            {
                for (int l=0; l<(mp[0]).size()+2; ++l)
                {
                    if((i==0)||(i==mp.size()-1)||(l==0)||(l==(mp[0]).size()-1))
                    {
                        mp[i][l]='#';
                    }
                    else
                    {
                        mp[i][l]=' ';
                    }
                }
            }
    }
    void Map::addMapObject(MapObject* mo)
    {
        ls.push_back(mo);
 //       mp[mo->getXpos()][mo->getYpos()]=mo->getSym();
    }
}
