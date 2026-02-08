#pragma once
#include <bits/stdc++.h>
#include "FineStrategy.h"

using namespace std;

class PremiumFineStrategy : public FineStrategy
{
public:
    int calculateFine(int daysLate) override
    {
        return daysLate * 5;
    }
};