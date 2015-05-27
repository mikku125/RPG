#include <iostream>

#include "inventory.hpp"

namespace Rpg
{
    void Inventory::info() const
    {
        for (std::vector<Item*>::const_iterator i = itemsVec.begin(); i != itemsVec.end(); ++i)
        {
            if ( *i == *cursor )
            {
                std::cout << ">>> ";
            }
            (*i)->info();
            std::cout << std::endl;
        }
    }

    Item* Inventory::getItem()
    {
        return *cursor;
    }

    void Inventory::addItem(Item* item)
    {
        itemsVec.push_back(item);
        cursor = itemsVec.begin();
    }

    void Inventory::removeItem()
    {
        itemsVec.erase(cursor);
    }

    void Inventory::giveItem(Inventory* inv)
    {
        inv->addItem(*cursor);
        removeItem();
    }

    void Inventory::takeItem(Inventory* inv)
    {
        addItem(inv->getItem() );
        inv->removeItem();
    }

    void Inventory::moveCursorUp()
    {
        if (cursor != itemsVec.begin() )
        {
            --cursor;
        }
    }

    void Inventory::moveCursorDown()
    {
        if (cursor != itemsVec.end() - 1 )
        {
            ++cursor;
        }
    }
}
