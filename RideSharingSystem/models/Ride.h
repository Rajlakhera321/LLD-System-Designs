#pragma once
#include <bits/stdc++.h>
#include "Driver.h"
#include "Rider.h"
#include "Vehicle.h"
#include "enums/RideStatus.h"
#include "Location.h"
#include "IdGenerator.h"

using namespace std;

class Ride
{
private:
    int rideId;
    Driver *driver;
    Rider *rider;
    Location src;
    Location dest;
    Vehicle *vehicle;
    RideStatus status;
    double fare;

public:
    Ride(Driver *driver, Rider *rider, Location src, Location dest, Vehicle *vehicle, RideStatus status) : rideId(IdGenerator::generateRideId()), driver(driver), rider(rider), src(src), dest(dest), vehicle(vehicle), status(RideStatus::REQUESTED), fare(0) {}

    int getId() const { return rideId; }
    Driver *getDriver() const { return driver; }
    Rider *getRider() const { return rider; }
    Location getSrc() const { return src; }
    Location getDest() const { return dest; }
    RideStatus getStatus() const { return status; }
    double getFare() const { return fare; }

    void setStatus(RideStatus s) { status = s; }
    void setFare(double f) { fare = f; }
};