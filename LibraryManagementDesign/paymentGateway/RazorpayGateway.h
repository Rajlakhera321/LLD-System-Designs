#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPaymentGateway.h"

using namespace std;

class RazorpayGateway : public IPaymentGateway
{
public:
    bool processPayment(int userId, double amount) override
    {
        cout << "Processing Razorpay payment for user "
             << userId << " Amount: " << amount << endl;
        return true; // simulate success
    }
};