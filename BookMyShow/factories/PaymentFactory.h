#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPaymentInterface.h"
#include "../strategies/paymentStrategy/RazorpayStrategy.h"
#include "../strategies/paymentStrategy/StripeStrategy.h"
using namespace std;

class PaymentFactory
{
public:
    IPaymentInterface *createPayment(string &type)
    {
        if (type == "stripe")
        {
            return new StripeStrategy();
        }
        else if (type == "razorpay")
        {
            return new RazorpayStrategy();
        }

        return nullptr;
    }
};