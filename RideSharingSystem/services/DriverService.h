#pragma once
#include <bits/stdc++.h>
#include "repositories/DriverRepository.h"

using namespace std;

class DriverService
{
private:
    DriverRepository *driverRepo;

public:
    DriverService(DriverRepository *driverRepo) : driverRepo(driverRepo) {}

    void addDriver(string name, string phoneNo, string licenseNo)
    {
        Driver *driver = new Driver(name, phoneNo, licenseNo);
        driverRepo->addDriver(driver);
    }

    Driver *getDriverById(int id)
    {
        return driverRepo->getDriverById(id);
    }
};