#pragma once
#include <bits/stdc++.h>

using namespace std;

class Location
{
private:
    double lat;
    double lng;

public:
    Location(double lat, double lng) : lat(lat), lng(lng) {}

    double getLat() const
    {
        return lat;
    }

    double getLng() const
    {
        return lng;
    }
};