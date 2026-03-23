#pragma once
#include <bits/stdc++.h>
#include "../enums/IngredientEnum.h"

using namespace std;

class Inventory
{
private:
    unordered_map<IngredientEnum, int> stock;

    Inventory() {}

public:
    static Inventory &getInstance()
    {
        static Inventory instance;
        return instance;
    }

    Inventory(const Inventory &) = delete;
    void operator=(const Inventory &) = delete;

    void addIngredient(IngredientEnum ing, int qty)
    {
        stock[ing] += qty;
    }

    bool hasIngredients(const unordered_map<IngredientEnum, int> &recipe)
    {
        for (auto &it : recipe)
        {
            if (stock[it.first] < it.second)
                return false;
        }
        return true;
    }

    void consumeIngredients(const unordered_map<IngredientEnum, int> &recipe)
    {
        for (auto &it : recipe)
        {
            stock[it.first] -= it.second;
        }
    }
};