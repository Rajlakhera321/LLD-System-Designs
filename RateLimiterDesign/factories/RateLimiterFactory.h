#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IRateLimitAlgo.h"
#include "../strategies/FixedSizeWindow.h"
#include "../strategies/LeakBucket.h"

class RateLimiterFactory
{
public:
    static IRateLimitAlgo *createRateLimiter(std::string type, int capacity, int rate);
};