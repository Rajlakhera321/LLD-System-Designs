#pragma once
#include <bits/stdc++.h>
#include "User.h"

using namespace std;

class Vehicle
{
private:
    string vehicleNumber;
    string model;
    string color;
    User *driver;

public:
    Vehicle(User *driver, string &vehicleNo, string &model, string &color) : driver(driver), model(model), color(color), vehicleNumber(vehicleNo) {}

    string getVehicleNumber() const { return vehicleNumber; }
    string getModel() const { return model; }
    string getColor() const { return color; }

    User *getDriver() const { return driver; }
};