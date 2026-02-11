#pragma once
#include <bits/stdc++.h>
#include "../models/User.h"
using namespace std;

class IPaymentInterface
{
public:
    virtual bool processPayment(User *user, int amount) = 0;
};