#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPaymentGateway.h"

using namespace std;

class StripeGateway : public IPaymentGateway
{
public:
    bool processPayment(int userId, double amount) override
    {
        cout << "Processing Stripe payment for user "
             << userId << " Amount: " << amount << endl;
        return true;
    }
};