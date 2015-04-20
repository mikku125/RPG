#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>

#include "item.hpp"

namespace RPG
{
    class Inventory
    {
    protected:
        std::vector<Item*> inv;

    public:
        Inventory()
        {}

        virtual void info() const;

        Item* getItem(const unsigned& i)
        {
            return inv[i];
        }

        Item* operator[](const unsigned& i)
        {
            return inv[i];
        }

        void takeItem(Inventory*,const unsigned&);

        void takeAllItems(Inventory*);

        void addItem(Item*);

        void removeItem(Item*);

        void useItem(Item*);

        unsigned findItem(Item*);
    };
}
#endif // INVENTORY_HPP
