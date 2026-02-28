#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int userId;
    static int rideId;
    static int paymentId;

    static int generateUserId() { return ++userId; }
    static int generateRideId() { return ++rideId; }
    static int generatePaymentId() { return ++paymentId; }
};

int IdGenerator::userId = 0;
int IdGenerator::rideId = 0;
int IdGenerator::paymentId = 0;