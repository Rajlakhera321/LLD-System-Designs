#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IPaymentInterface.h"

using namespace std;

class CoinStrategy : public IPaymentInterface
{
public:
    void pay(int amount) override
    {
        cout << "Paying with coins: " << amount << endl;
    }
};