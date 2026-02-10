#pragma once
#include <bits/stdc++.h>
#include "../models/Seat.h"

using namespace std;

class SeatRepository
{
private:
    vector<Seat *> seats;

public:
    void addSeat(Seat *s) { seats.push_back(s); }

    Seat *findById(int id)
    {
        for (auto s : seats)
            if (s->getSeatId() == id)
                return s;
        return nullptr;
    }

    vector<Seat *> findByRow(string row)
    {
        vector<Seat *> result;
        for (auto s : seats)
            if (s->getSeatRow() == row)
                result.push_back(s);
        return result;
    }

    vector<Seat *> findAll()
    {
        return seats;
    }
};
