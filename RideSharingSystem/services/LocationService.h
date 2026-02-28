#pragma once
#include <bits/stdc++.h>
#include "../repositories/LocationRepository.h"

using namespace std;

class LocationService
{
private:
    LocationRepository *locationRepo;
    static LocationService *instance;
    LocationService(LocationRepository *locationRepo) : locationRepo(locationRepo) {}

public:
    static LocationService *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new LocationService(new LocationRepository());
        }
        return instance;
    }

    void addLocation(double lat, double lng)
    {
        Location *location = new Location(lat, lng);
        locationRepo->addLocation(location);
        cout << "Location added: (" << location->getLat() << ", " << location->getLng() << ")" << endl;
    }

    Location *getLocationByCoordinates(double lat, double lng)
    {
        return locationRepo->getLocationByCoordinates(lat, lng);
    }

    double distance(const Location &a, const Location &b)
    {
        return locationRepo->distance(a, b);
    }
};

LocationService *LocationService::instance = nullptr;