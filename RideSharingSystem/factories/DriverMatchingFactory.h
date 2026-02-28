#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IDriverMatchingInterface.h"
#include "../strategies/DriverMatchingStrategy/NearestDriverMatching.h"
#include "../services/LocationService.h"

using namespace std;

class DriverMatchingFactory
{
public:
    static IDriverMatchingInterface *createDriverMatchingStrategy(const string &strategyType)
    {
        if (strategyType == "NearestDriver")
        {
            cout << "Creating NearestDriverMatching strategy" << endl;
            return new NearestDriverMatching(LocationService::getInstance());
        }
        // Add more strategies here as needed
        return nullptr;
    }
};