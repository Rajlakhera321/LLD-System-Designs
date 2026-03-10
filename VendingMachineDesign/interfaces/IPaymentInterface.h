#pragma once
#include "bits/stdc++.h"

using namespace std;

class IPaymentInterface
{
public:
    virtual void pay(int amount) = 0;
    virtual ~IPaymentInterface() {}
};