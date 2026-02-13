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
    ShowSeat(Seat *seat, int price) : seat(seat), price(price)
    {
        status = SeatStatus::AVAILABLE;
        showSeatId = IdGenerator::generateShowSeatId();
    }

    SeatStatus getStatus() const
    {
        return status;
    }

    void setStatus(auto status)
    {
        this->status = status;
    }

    int getPrice() const
    {
        return price;
    }
};