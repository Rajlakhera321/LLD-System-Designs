#pragma once
#include <bits/stdc++.h>
#include "../models/Driver.h"

using namespace std;

class DriverRepository
{
private:
    vector<Driver *> drivers;

public:
    void addDriver(Driver *driver)
    {
        drivers.push_back(driver);
    }

    Driver *getDriverById(int id)
    {
        for (auto driver : drivers)
        {
            if (driver->getId() == id)
            {
                return driver;
            }
        }
        return nullptr;
    }

    vector<Driver *> getAvailableDrivers()
    {
        std::vector<Driver *> list;
        for (auto &p : drivers)
            if (p->getStatus() == DriverStatus::AVAILABLE)
                list.push_back(p);
        return list;
    }

    void setLocationForDriver(Driver *driver, double lat, double lng)
    {
        driver->setLocation(lat, lng);
    }
};