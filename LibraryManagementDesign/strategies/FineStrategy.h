#pragma once
#include <bits/stdc++.h>

using namespace std;

class FineStrategy
{
public:
    virtual int calculateFine(int daysLate) = 0;
    virtual ~FineStrategy() = default;
};