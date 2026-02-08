#pragma once
#include <bits/stdc++.h>
#include "FineStrategy.h"

using namespace std;

class NormalFineStrategy : public FineStrategy
{
public:
    int calculateFine(int daysLate) override
    {
        return daysLate * 10;
    }
};