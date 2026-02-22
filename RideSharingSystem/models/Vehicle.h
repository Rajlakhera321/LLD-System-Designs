#pragma once
#include <bits/stdc++.h>
#include "Driver.h"

using namespace std;

class Vehicle
{
private:
    string vehicleNumber;
    string model;
    string color;
    Driver *driver;

public:
    Vehicle(Driver *driver, string vehicleNo, string model, string color) : driver(driver), model(model), color(color), vehicleNumber(vehicleNo) {}

    string getVehicleNumber() const { return vehicleNumber; }
    string getModel() const { return model; }

    Driver *getDriver() const { return driver; }
};