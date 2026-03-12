#pragma once
#include <bits/stdc++.h>
#include "../enums/IngredientEnum.h"

using namespace std;

class Inventory
{
private:
    unordered_map<IngredientEnum, int> ingredients;

public:
    int getIngredient(IngredientEnum ingredient)
    {
        if (!hasIngredient(ingredient))
            return 0;

        return ingredients[ingredient];
    }

    auto getAllIngredients() const
    {
        return ingredients;
    }

    bool hasIngredient(IngredientEnum ingredient)
    {
        return ingredients.find(ingredient) != ingredients.end();
    }

    void consumeIngredient(IngredientEnum ingredient, int quantity)
    {
        if (hasIngredient(ingredient) && ingredients[ingredient] >= quantity)
        {
            ingredients[ingredient] -= quantity;
        }
    }

    void restockIngredient(IngredientEnum ingredient, int quantity)
    {
        if (hasIngredient(ingredient))
        {
            ingredients[ingredient] += quantity;
        }
        else
        {
            ingredients[ingredient] = quantity;
        }
    }
};