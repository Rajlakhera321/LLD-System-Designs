#pragma once
#include <bits/stdc++.h>
#include "Seat.h"
#include "../enums/SeatStatus.h"
#include "IdGenerator.h"

using namespace std;

class ShowSeat
{
private:
    int showSeatId;
    Seat *seat;
    SeatStatus status;
    int price;

public:
    ShowSeat(Seat *seat, SeatStatus status, int price) : seat(seat), status(status), price(price)
    {
        showSeatId = IdGenerator::generateShowSeatId();
    }
};