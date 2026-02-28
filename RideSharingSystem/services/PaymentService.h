#pragma once
#include <bits/stdc++.h>
#include "../repositories/PaymentRepository.h"

using namespace std;

class PaymentService
{
private:
    PaymentRepository *paymentRepo;

public:
    PaymentService(PaymentRepository *paymentRepo) : paymentRepo(paymentRepo) {}

    void addPayment(Payment *payment)
    {
        paymentRepo->addPayment(payment);
    }

    Payment *getPaymentById(int paymentId)
    {
        return paymentRepo->getPaymentById(paymentId);
    }

    vector<Payment *> getPaymentsByUserId(int userId)
    {
        return paymentRepo->getPaymentsByUserId(userId);
    }

    vector<Payment *> getAllPayments()
    {
        return paymentRepo->getAllPayments();
    }

    void updatePaymentStatus(int paymentId, PaymentStatus newStatus)
    {
        paymentRepo->updatePaymentStatus(paymentId, newStatus);
    }
};