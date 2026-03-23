#pragma once
#include <memory>
#include <bits/stdc++.h>
#include "../models/Beverage.h"
#include "../strategies/EspressoStrategy.h"
#include "../strategies/LatteStrategy.h"
#include "../enums/BeverageEnum.h"

class BeverageFactory
{
public:
    static unique_ptr<Beverage> createBeverage(BeverageEnum type)
    {

        switch (type)
        {
        case BeverageEnum::Espresso:
            return make_unique<Beverage>(
                make_unique<EspressoStrategy>());

        case BeverageEnum::Latte:
            return make_unique<Beverage>(
                make_unique<LatteStrategy>());

        default:
            return nullptr;
        }
    }
};