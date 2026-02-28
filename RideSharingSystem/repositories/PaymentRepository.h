#pragma once
#include <bits/stdc++.h>
#include "../models/Payment.h"

using namespace std;

class PaymentRepository
{
private:
    vector<Payment *> payments;

public:
    void addPayment(Payment *payment)
    {
        payments.push_back(payment);
    }

    Payment *getPaymentById(int paymentId)
    {
        for (auto payment : payments)
        {
            if (payment->getPaymentId() == paymentId)
            {
                return payment;
            }
        }
        return nullptr;
    }

    vector<Payment *> getPaymentsByUserId(int userId)
    {
        vector<Payment *> userPayments;
        for (auto payment : payments)
        {
            if (payment->getUser()->getId() == userId)
            {
                userPayments.push_back(payment);
            }
        }
        return userPayments;
    }

    vector<Payment *> getAllPayments()
    {
        return payments;
    }

    void updatePaymentStatus(int paymentId, PaymentStatus newStatus)
    {
        Payment *payment = getPaymentById(paymentId);
        if (payment)
        {
            payment->setStatus(newStatus);
        }
    }
};