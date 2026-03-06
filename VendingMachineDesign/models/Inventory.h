#pragma once
#include <bits/stdc++.h>
#include "Item.h"

using namespace std;

class Inventory
{
private:
    vector<Item *> items;

public:
    void addItem(Item *item)
    {
        items.push_back(item);
    }

    Item *getItem(int code)
    {
        for (auto item : items)
        {
            if (item->getCode() == code)
            {
                return item;
            }
        }
        return nullptr;
    }

    vector<Item *> getItems()
    {
        return items;
    }
};