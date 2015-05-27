#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <iostream>

#include "item.hpp"

namespace Rpg
{
    class Inventory
    {
    protected:
        std::vector<Item*> itemsVec;
        std::vector<Item*>::iterator cursor;

    public:
        Inventory()
        {}

        virtual void info() const;
        Item* getItem();
        void addItem(Item*);
        void removeItem();
        void giveItem(Inventory*);
        void takeItem(Inventory*);
        void moveCursorUp();
        void moveCursorDown();
        unsigned getSize() const
        {
            return itemsVec.size();
        }
    };
}
#endif // INVENTORY_HPP
