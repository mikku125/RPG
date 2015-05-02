#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>

#include "item.hpp"

namespace Rpg
{
    class Inventory
    {
    protected:
        std::vector<Item*> inv;

    public:
        Inventory()
        {}

        virtual void info() const;
        Item* getItem(const unsigned&);
        void addItem(Item*);
        void removeItem(const unsigned&);
        void takeItem(const unsigned&,Inventory*);
        unsigned getSize() const
        {
            return inv.size();
        }
    };
}
#endif // INVENTORY_HPP
