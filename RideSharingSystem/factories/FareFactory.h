#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IFareInterface.h"
#include "../strategies/FareStrategy/DefaultFareStrategy.h"
#include "../strategies/FareStrategy/SurgeFareStrategy.h"

class FareFactory
{
public:
    static IFareInterface *getStrategy(bool surge)
    {
        return surge ? (IFareInterface *)new SurgeFareStrategy() : (IFareInterface *)new DefaultFareStrategy();
    }
};