#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IFareInterface.h"

class SurgeFareStrategy : public IFareInterface
{
public:
    double calculateFare(LocationService *locationService, Location src, Location dest) override
    {
        double distanceKm = locationService->distance(src, dest);
        return (50 + distanceKm * 10) * 2.0; // 2x surge
    }
};