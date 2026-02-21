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
    User *user;

public:
    Vehicle(User *user, string vehicleNo, string model, string color) : user(user), model(model), color(color), vehicleNumber(vehicleNo) {}
};