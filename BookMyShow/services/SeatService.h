#pragma once
#include <bits/stdc++.h>
#include "../factories/SeatFactory.h"
#include "../interfaces/ISeatInterface.h"
#include "../repositories/SeatRepository.h"

using namespace std;

class SeatService
{
private:
    SeatFactory factory;
    SeatRepository *repo;

public:
    SeatService(SeatRepository *repo) : repo(repo) {}

    Seat *createSeat(string type, string row)
    {
        ISeatInterface *strategy = factory.createSeatFactory(type);

        if (!strategy)
        {
            cout << "Invalid seat type!" << endl;
            return nullptr;
        }

        Seat *s = strategy->createSeat(row);
        repo->addSeat(s);
        delete strategy;

        return s;
    }

    vector<Seat *> getSeatsByRow(string row)
    {
        return repo->findByRow(row);
    }
};