#include<iostream>
#include "map.hpp"

namespace RPG {
    void Map::draw() const
    {

        for (int i=0; i<7; ++i)
        {
            for (int l=0; l<12; ++l)
            {
                if((i==0)||(i==6)||(l==0)||(l==11))
                {
                    std::cout << '#';
                }
                else
                {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
        for (int i=0; i<ls.size(); ++i)
        {

        }
    }
    void Map::addMapObject(MapObject* mo)
    {
        ls.push_back(mo);
    }
}
