#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>

#include "item.hpp"

namespace Rpg
{
    class Inventory
    {
    protected:
        std::vector<Item*> itemsVec;
        unsigned cursor;

    public:
        Inventory()
        {
            cursor = 0;
        }

        virtual void info() const;
        Item* getItem(const unsigned&);
        void addItem(Item*);
        void removeItem(const unsigned&);
        void giveItem(Inventory*);
        void moveCursorUp();
        void moveCursorDown();
        unsigned getSize() const
        {
            return itemsVec.size();
        }
    };
}
#endif // INVENTORY_HPP
