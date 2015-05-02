#include <iostream>

#include "inventory.hpp"

namespace Rpg
{
    void Inventory::info() const
    {
        for (unsigned i=0; i<inv.size(); ++i)
        {
            inv[i]->info();
            std::cout << std::endl;
        }
    }

    Item* Inventory::getItem(const unsigned& i)
    {
        return inv[i];
    }

    void Inventory::addItem(Item* item)
    {
        inv.push_back(item);
    }


    void Inventory::removeItem(const unsigned& i)
    {
        for (unsigned j=i; j<inv.size()-1; ++j)
        {
            inv[j]=inv[j+1];
        }
        inv.pop_back();
    }
    void Inventory::takeItem(const unsigned& i, Inventory* inv1)
    {
        inv1->addItem(inv[i] );
        removeItem(i);
    }

}
