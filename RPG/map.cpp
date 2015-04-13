#include<iostream>
#include "map.hpp"

namespace RPG {
    void Map::draw()
    {
        reset();
        for (unsigned i=0; i<ysize+2; ++i)
        {
            std::cout << '#';
        }
        std::cout << std::endl;
        for (unsigned i=0; i<xsize; ++i)
        {
            std::cout << '#';
            for (unsigned l=0; l<ysize; ++l)
            {
                std::cout << lmap[i][l] -> getSym();
            }
            std::cout << '#' << std::endl;
        }
        for (unsigned i=0; i<ysize+2; ++i)
        {
            std::cout << '#';
        }
        std::cout << std::endl;
    }
    void Map::reset()
    {
        for (unsigned i=0; i<xsize; ++i)
        {
            for (unsigned l=0; l<ysize; ++l)
            {
                if (!isTile(i,l) )
                {
                    if (!isMatch(i,l) )
                    {
                        lmap[lmap[i][l]->getXpos()][lmap[i][l]->getYpos()] = lmap[i][l];
                        lmap[i][l]=tile;
                    }
                }
            }
        }
    }
    bool Map::isTile(const unsigned& x, const unsigned& y)
    {
        if (lmap[x][y]->getName()=="tile")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Map::isMatch(const unsigned& x, const unsigned& y)
    {
        unsigned tempX = lmap[x][y] -> getXpos();
        unsigned tempY = lmap[x][y] -> getYpos();
        if ((x==tempX)&&(y==tempY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Map::addMapObject(MapObject* mapobj)
    {
        lmap[mapobj->getXpos()][mapobj->getYpos()] = mapobj;
    }
}
