#pragma once
#include <bits/stdc++.h>
#include "../enums/SeatType.h"
#include "../enums/SeatStatus.h"
#include "IdGenerator.h"

using namespace std;

class Seat
{
private:
    int seatId;
    string row;
    SeatType seatType;
    SeatStatus status;

public:
    Seat(string row, SeatType type) : row(row), seatType(type)
    {
        seatId = IdGenerator::generateSeatId();
        status = SeatStatus::AVAILABLE;
    }

    string getSeatRow() const { return row; }

    int getSeatId() const { return seatId; }

    SeatType getSeatType() const { return seatType; }

    bool isAvaliable() const { return status == SeatStatus::AVAILABLE; }

    void setBooked()
    {
        status = SeatStatus::BOOKED;
    }

    void setAvailable()
    {
        status = SeatStatus::AVAILABLE;
    }
};