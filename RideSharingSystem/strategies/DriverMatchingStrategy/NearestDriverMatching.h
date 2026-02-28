#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IDriverMatchingInterface.h"
#include "../../services/LocationService.h"

using namespace std;

class NearestDriverMatching : public IDriverMatchingInterface
{
private:
    LocationService *locationService;

public:
    NearestDriverMatching(LocationService *locationService) : locationService(locationService) {}
    Driver *findMatchingDrivers(vector<Driver *> drivers, Location location) override
    {
        Driver *best = nullptr;
        double bestDist = 1e18;

        for (auto d : drivers)
        {
            double dist = locationService->distance(
                location,
                Location(d->getLat(), d->getLng()));
            if (dist < bestDist)
            {
                best = d;
                bestDist = dist;
            }
        }
        return best;
    }
};