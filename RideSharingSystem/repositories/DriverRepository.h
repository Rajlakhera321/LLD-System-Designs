#pragma once
#include <bits/stdc++.h>
#include "models/Driver.h"

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
};