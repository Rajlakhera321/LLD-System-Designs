#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IPaymentInterface.h"
#include "../../models/User.h"
#include "../../services/PaymentService.h"
#include "../../repositories/UserRepository.h"

using namespace std;

class Stripe : public IPaymentInterface
{
private:
    PaymentService *paymentService;
    RiderRepository *riderRepo;

public:
    Stripe(PaymentService *paymentService, RiderRepository *riderRepo) : paymentService(paymentService), riderRepo(riderRepo) {}
    void processPayment(double amount, const string &method, User *user) override
    {
        User *foundUser = riderRepo->getRiderById(user->getId());
        if (!foundUser)
        {
            cout << "Rider not found for payment processing." << endl;
            return;
        }

        cout << "Processing Stripe payment of amount: " << amount << " for user: " << foundUser->getName() << endl;
        Payment *payment = new Payment(amount, method, PaymentStatus::PENDING, foundUser);
        paymentService->addPayment(payment);
        cout << "Stripe: Payment processed successfully for user: " << foundUser->getName() << endl;
    }
};