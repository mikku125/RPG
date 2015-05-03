#include <iostream>

#include "inventory.hpp"

namespace Rpg
{
    void Inventory::info() const
    {
        for (unsigned i=0; i<itemsVec.size(); ++i)
        {
            if (i == cursor)
            {
                std::cout << ">>> ";
            }
            itemsVec[i]->info();
            std::cout << std::endl;
        }
    }

    Item* Inventory::getItem(const unsigned& i)
    {
        return itemsVec[i];
    }

    Item* Inventory::getItem()
    {
        return itemsVec[cursor];
    }

    void Inventory::addItem(Item* item)
    {
        itemsVec.push_back(item);
    }

    void Inventory::removeItem(const unsigned& i)
    {
        for (unsigned j=i; j<itemsVec.size()-1; ++j)
        {
            itemsVec[j]=itemsVec[j+1];
        }
        itemsVec.pop_back();
        if (!(cursor<itemsVec.size() ) )
        {
            cursor = itemsVec.size()-1;
        }
    }

    void Inventory::removeItem()
    {
        for (unsigned j=cursor; j<itemsVec.size()-1; ++j)
        {
            itemsVec[j]=itemsVec[j+1];
        }
        itemsVec.pop_back();
        if (!(cursor<itemsVec.size() ) )
        {
            cursor = itemsVec.size()-1;
        }
    }

    void Inventory::giveItem(Inventory* inv)
    {
        inv->addItem(itemsVec[cursor] );
        removeItem(cursor);
    }

    void Inventory::takeItem(Inventory* inv)
    {
        addItem(inv->getItem() );
        inv->removeItem();
    }

    void Inventory::moveCursorUp()
    {
        if (cursor>0)
        {
            --cursor;
        }
    }

    void Inventory::moveCursorDown()
    {
        if (cursor<itemsVec.size()-1)
        {
            ++cursor;
        }
    }
}
