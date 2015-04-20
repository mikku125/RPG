#include<iostream>

#include "map.hpp"

namespace RPG
{
    void Map::addMapObject(MapObject* mapObj)
    {
        ls.push_back(mapObj);
    }

    void Map::draw()
    {
        Map::reset();
        Map::update();

        std::cout << "\n\n\n\n\n"
        <<"\n\n\n\n\n"
        <<"\n\n\n\n\n"
        <<"\n\n\n\n\n";

        for (unsigned i=0; i<stage[0].size()+2; ++i)
        {
            std::cout<< "# ";
        }
        std::cout << std::endl;

        for (unsigned i=0; i<stage.size(); ++i)
        {
            std::cout << "# ";
            for (unsigned j=0; j<stage[i].size(); ++j)
            {
                std::cout << stage[i][j] << ' ';
            }
            std::cout << "# " << std::endl;
        }

        for (unsigned i=0; i<stage[0].size()+2; ++i)
        {
            std::cout<< "# ";
        }
        std::cout << std::endl;

        std::cout << std::endl;
    }

    void Map::reset()
    {
        for (unsigned i=0; i<stage.size(); ++i)
        {
            for (unsigned j=0; j<stage[i].size(); ++j)
            {
                stage[i][j] = ' ';
            }
        }
    }

    void Map::update()
    {
        for (unsigned i=0; i<ls.size(); ++i)
        {
            stage[ls[i]->getXpos() ][ls[i]->getYpos() ] = ls[i]->getSymb();
        }
    }

}
