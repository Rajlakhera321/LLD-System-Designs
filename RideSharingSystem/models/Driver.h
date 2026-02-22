#pragma once
#include <bits/stdc++.h>
#include "User.h"
#include "enums/DriverStatus.h"
#include "Vehicle.h"

using namespace std;

class Driver : public User
{
private:
    string licenseNumber;
    DriverStatus status;
    Vehicle *vehicle;
    double currentLat, currentLng;

public:
    Driver(string name, string phone, string license)
        : User(name, phone), licenseNumber(license),
          status(DriverStatus::AVAILABLE),
          currentLat(0), currentLng(0), vehicle(nullptr) {}

    // GETTERS
    string getLicense() const { return licenseNumber; }
    DriverStatus getStatus() const { return status; }
    double getLat() const { return currentLat; }
    double getLng() const { return currentLng; }
    Vehicle *getVehicle() const { return vehicle; }

    // SETTERS
    void setStatus(DriverStatus s) { status = s; }
    void setLocation(double lat, double lng)
    {
        currentLat = lat;
        currentLng = lng;
    }
    void setVehicle(Vehicle *v) { vehicle = v; }
};