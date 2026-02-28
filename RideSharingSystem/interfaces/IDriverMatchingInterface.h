#pragma once
#include <bits/stdc++.h>
#include "../models/Driver.h"
#include "../models/Location.h"

using namespace std;

class IDriverMatchingInterface
{
public:
    virtual Driver *findMatchingDrivers(vector<Driver *>, Location) = 0;
    virtual ~IDriverMatchingInterface() {}
};