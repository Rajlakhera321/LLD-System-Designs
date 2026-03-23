#pragma once
#include <bits/stdc++.h>
#include "../models/Beverage.h"

using namespace std;

class BeverageRepository
{
private:
    unordered_map<BeverageEnum, Beverage> beverages;

public:
    void addBeverage(const Beverage &bev)
    {
        beverages.insert({bev.getName(), bev});
    }

    Beverage *getBeverage(BeverageEnum name)
    {
        auto it = beverages.find(name);
        if (it == beverages.end())
            return NULL;
        return &it->second;
    }

    bool hasBeverage(BeverageEnum name)
    {
        return beverages.find(name) != beverages.end();
    }
};