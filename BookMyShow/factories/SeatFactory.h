#pragma once
#include <bits/stdc++.h>
#include "../interfaces/ISeatInterface.h"
#include "../strategies/seatStrategy/NormalSeatStrategy.h"
#include "../strategies/seatStrategy/PremiumSeatStrategy.h"
#include "../strategies/seatStrategy/ReclinerSeatStrategy.h"

using namespace std;

class SeatFactory
{
public:
    ISeatInterface *createSeatFactory(string type)
    {
        if (type == "premium")
        {
            return new PremiumSeatStrategy();
        }
        else if (type == "normal")
        {
            return new NormalSeatStrategy();
        }
        else if (type == "recliner")
        {
            return new ReclinerSeatStrategy();
        }
        return nullptr;
    }
};