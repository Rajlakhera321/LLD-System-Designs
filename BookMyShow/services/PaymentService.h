#pragma once
#include <bits/stdc++.h>
#include "../factories/PaymentFactory.h"
#include "../models/User.h"

using namespace std;

class PaymentService
{
private:
    PaymentFactory factory;

public:
    bool processPayment(User *user, int amount, string paymentType)
    {
        IPaymentInterface *method = factory.createPayment(paymentType);

        if (!method)
        {
            cout << "Invalid payment method!" << endl;
            return false;
        }

        bool result = method->processPayment(user, amount);
        delete method;
        return result;
    }
};