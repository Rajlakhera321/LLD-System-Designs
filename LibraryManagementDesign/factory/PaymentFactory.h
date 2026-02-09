#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPaymentGateway.h"
#include "../paymentGateway/StripeGateway.h"
#include "../paymentGateway/RazorpayGateway.h"

using namespace std;

class PaymentFactory
{
public:
    unique_ptr<IPaymentGateway> createPaymentGateway(string &type)
    {
        if (type == "stripe")
        {
            return make_unique<StripeGateway>();
        }
        else if (type == "razorpay")
        {
            return make_unique<RazorpayGateway>();
        }

        return NULL;
    }
};