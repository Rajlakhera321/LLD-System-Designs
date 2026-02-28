#pragma once
#include <bits/stdc++.h>
#include "../models/Vehicle.h"

using namespace std;

class VehicleRepository
{
private:
    vector<Vehicle *> vehicles;

public:
    void addVehicle(Vehicle *vehicle)
    {
        vehicles.push_back(vehicle);
    }

    Vehicle *getVehicleByNumber(const string &vehicleNumber)
    {
        for (auto vehicle : vehicles)
        {
            if (vehicle->getVehicleNumber() == vehicleNumber)
            {
                return vehicle;
            }
        }
        return nullptr;
    }

    Vehicle *getVehicleByDriverId(int driverId)
    {
        for (auto vehicle : vehicles)
        {
            if (vehicle->getDriver()->getId() == driverId)
            {
                return vehicle;
            }
        }
        return nullptr;
    }

    Vehicle *getVehicleByDriverName(const string &driverName)
    {
        for (auto vehicle : vehicles)
        {
            if (vehicle->getDriver()->getName() == driverName)
            {
                return vehicle;
            }
        }
        return nullptr;
    }
};