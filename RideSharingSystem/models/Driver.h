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
    double currentLat, currentLag;
};