#pragma once
#include <bits/stdc++.h>
#include "models/Ride.h"

using namespace std;

class RideRepository
{
private:
    vector<Ride *> rides;

public:
    void addRide(Ride *ride)
    {
        rides.push_back(ride);
    }

    Ride *getRideById(int id)
    {
        for (auto ride : rides)
        {
            if (ride->getId() == id)
            {
                return ride;
            }
        }
        return nullptr;
    }
};
