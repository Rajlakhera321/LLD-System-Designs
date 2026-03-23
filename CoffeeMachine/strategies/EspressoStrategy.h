#pragma once
#include "../interfaces/IPreparation.h"
#include "../enums/IngredientEnum.h"

class EspressoStrategy : public IPreparation
{
public:
    unordered_map<IngredientEnum, int> getRecipe() override
    {
        return {
            {IngredientEnum::CoffeeBeans, 10},
            {IngredientEnum::Water, 50}};
    }

    string getName() override
    {
        return "Espresso";
    }
};