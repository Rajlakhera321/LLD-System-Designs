#pragma once
#include "../factory/BeverageFactory.h"

class BeverageService
{
public:
    unique_ptr<Beverage> createBeverage(BeverageEnum type)
    {
        return BeverageFactory::createBeverage(type);
    }
};