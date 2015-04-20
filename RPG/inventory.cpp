#include <iostream>

#include "inventory.hpp"

namespace RPG
{
    void Inventory::info() const
    {
        for (unsigned i=0; i<inv.size(); ++i)
        {
            inv[i]->info();
            std::cout << std::endl;
        }
    }

    void Inventory::addItem(Item* item)
    {
        inv.push_back(item);
    }

    void Inventory::takeItem(Inventory* inv2, const unsigned& i)
    {
        inv2->addItem(inv[i]);
        removeItem(inv[i]);
    }

    void Inventory::takeAllItems(Inventory* inv2)
    {
        while (!(inv.size()==0))
        {
            takeItem(inv2,0);
        }
    }

    void Inventory::removeItem(Item* item)
    {
        unsigned i = findItem(item);
        for (i; i<inv.size()-1; ++i)
        {
            inv[i]=inv[i+1];
        }
        inv.pop_back();
    }

    void Inventory::useItem(Item* item)
    {

    }

    unsigned Inventory::findItem(Item* item)
    {
        for (unsigned i=0; i<inv.size(); ++i)
        {
            if (inv[i] == item)
            {
                return i;
            }
        }
        return 0;
    }
}
