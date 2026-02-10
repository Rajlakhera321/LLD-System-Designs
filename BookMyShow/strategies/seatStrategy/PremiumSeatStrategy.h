#pragma once
#include <bits/stdc++.h>
#include "../interfaces/ISeatInterface.h"
#include "../models/Seat.h"
#include "../enums/SeatType.h"

using namespace std;

class PremiumSeatStrategy : public ISeatInterface
{
    Seat *createSeat(string row) override
    {
        return new Seat(row, SeatType::PREMIUM);
    }
};