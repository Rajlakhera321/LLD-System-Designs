#pragma once
#include <bits/stdc++.h>
#include "../repositories/DriverRepository.h"

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
        cout << "Driver added: " << driver->getName() << " with ID: " << driver->getId() << endl;
    }

    Driver *getDriverById(int id)
    {
        return driverRepo->getDriverById(id);
    }

    void setLocationForDriver(Driver *driver, double lat, double lng)
    {
        driverRepo->setLocationForDriver(driver, lat, lng);
        cout << "Location updated for driver: " << driver->getName() << " to (" << lat << ", " << lng << ")" << endl;
    }
};