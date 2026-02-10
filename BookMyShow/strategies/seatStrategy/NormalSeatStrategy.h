#pragma once
#include <bits/stdc++.h>
#include "../interfaces/ISeatInterface.h"
#include "../models/Seat.h"
#include "../enums/SeatType.h"

using namespace std;

class NormalSeatStrategy : public ISeatInterface
{
    Seat *createSeat(string row) override
    {
        return new Seat(row, SeatType::NORMAL);
    }
};