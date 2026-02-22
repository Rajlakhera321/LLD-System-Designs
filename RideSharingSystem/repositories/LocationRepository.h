#pragma once
#include <bits/stdc++.h>
#include "models/Location.h"

using namespace std;

class LocationRepository
{
private:
    vector<Location *> locations;

public:
    void addLocation(Location *location)
    {
        locations.push_back(location);
    }

    Location *getLocationByCoordinates(double lat, double lng)
    {
        for (auto location : locations)
        {
            if (location->getLat() == lat && location->getLng() == lng)
            {
                return location;
            }
        }
        return nullptr;
    }

    double distance(const Location &a, const Location &b)
    {
        double x = a.getLat() - b.getLat();
        double y = a.getLng() - b.getLng();
        return sqrt(x * x + y * y);
    }
};