#ifndef MAP_HPP
#define MAP_HPP
#include "mapobject.hpp"
#include<vector>

namespace RPG {
    class Map {
    protected:
        MapObject ***lmap;
        MapObject *tile;
        unsigned xsize;
        unsigned ysize;
    public:
        Map(unsigned x=5, unsigned y=10)
        : xsize(x), ysize(y)
        {
            lmap = new MapObject** [x];
            tile = new MapObject("tile",0,0,' ',false);
            for (unsigned i=0; i<x; ++i)
            {
                lmap[i] = new MapObject* [y];
            }
            for (unsigned i=0; i<x; ++i)
            {
                for (unsigned l=0; l<y; ++l)
                {
                    lmap[i][l] = tile;
                }
            }
        }
        void draw();
        void reset();
        bool isTile(const unsigned&,const unsigned&);
        bool isMatch(const unsigned&,const unsigned&);
        void addMapObject(MapObject*);
        ~Map()
        {
            for (unsigned i=0; i<xsize; ++i)
            {
                delete [] lmap[i];
            }
            delete tile;
        }
    };
}
#endif // MAP_HPP
