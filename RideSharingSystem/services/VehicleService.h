#pragma once
#include <bits/stdc++.h>
#include "../repositories/VehicleRepository.h"
#include "../repositories/DriverRepository.h"

using namespace std;

class VehicleService
{
private:
    VehicleRepository *vehicleRepo;
    DriverRepository *driverRepo;

public:
    VehicleService(VehicleRepository *vehicleRepo, DriverRepository *driverRepo) : vehicleRepo(vehicleRepo), driverRepo(driverRepo) {}

    void addVehicle(Driver *driver, string plateNo, string color, string model)
    {
        Vehicle *vehicle = new Vehicle(driver, plateNo, color, model);
        vehicleRepo->addVehicle(vehicle);
        cout << "Vehicle added: " << vehicle->getModel() << " with Plate No: " << vehicle->getVehicleNumber() << endl;
    }

    Vehicle *getVehicleByNumber(const string &vehicleNumber)
    {
        return vehicleRepo->getVehicleByNumber(vehicleNumber);
    }

    Vehicle *getVehicleByDriverName(const string &driverName)
    {
        return vehicleRepo->getVehicleByDriverName(driverName);
    }
};