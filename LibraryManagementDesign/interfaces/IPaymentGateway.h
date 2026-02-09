#pragma once
#include <bits/stdc++.h>

using namespace std;

class IPaymentGateway
{
public:
    virtual bool processPayment(int userId, double amount) = 0;
    virtual ~IPaymentGateway() {}
};