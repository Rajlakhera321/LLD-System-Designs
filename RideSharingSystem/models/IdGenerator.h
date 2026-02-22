#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int userId;
    static int rideId;

    static int generateUserId() { return ++userId; }
    static int generateRideId() { return ++rideId; }
};

int IdGenerator::userId = 0;
int IdGenerator::rideId = 0;