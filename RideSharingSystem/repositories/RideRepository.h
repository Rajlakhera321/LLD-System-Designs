#pragma once
#include <bits/stdc++.h>
#include "../models/Ride.h"

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

    vector<Ride *> getRidesByUserId(int userId)
    {
        vector<Ride *> result;
        for (auto ride : rides)
        {
            if (ride->getRider()->getId() == userId)
            {
                result.push_back(ride);
            }
        }
        return result;
    }

    vector<Ride *> getRidesByDriverId(int driverId)
    {
        vector<Ride *> result;
        for (auto ride : rides)
        {
            if (ride->getDriver()->getId() == driverId)
            {
                result.push_back(ride);
            }
        }
        return result;
    }
};
