#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IPaymentInterface.h"
#include "../../models/User.h"

using namespace std;

class StripeStrategy : public IPaymentInterface
{
public:
    bool processPayment(User *user, int amount) override
    {
        cout << "Payment of amount " << amount << " done for user " << user->getName() << " using stripe." << endl;
        return true;
    }
};