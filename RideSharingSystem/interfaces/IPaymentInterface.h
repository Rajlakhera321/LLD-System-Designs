#pragma once
#include <bits/stdc++.h>
#include "../models/User.h"

using namespace std;

class IPaymentInterface
{

public:
    virtual void processPayment(double amount, const string &method, User *user) = 0;
    virtual ~IPaymentInterface() {}
};