#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPaymentInterface.h"
#include "../repositories/PaymentRepository.h"
#include "../repositories/RiderRepository.h"
#include "../strategies/paymentStrategy/Stripe.h"

using namespace std;

class PaymentFactory
{
public:
    static IPaymentInterface *createPaymentProcessor(const string &method, PaymentService *paymentService, RiderRepository *riderRepo)
    {
        if (method == "Stripe")
        {
            return new Stripe(paymentService, riderRepo);
        }
        // Add more payment methods here as needed
        return nullptr;
    }
};