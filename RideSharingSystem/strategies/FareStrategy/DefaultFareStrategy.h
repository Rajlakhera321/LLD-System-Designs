#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IFareInterface.h"
#include "../../services/LocationService.h"

using namespace std;

class DefaultFareStrategy : public IFareInterface
{
private:
    LocationService *locationService;

public:
    double calculateFare(LocationService *locationService, Location src, Location dest) override
    {
        double distanceKm = locationService->distance(src, dest);
        return 50 + distanceKm * 10; // base + per km fare
    }
};