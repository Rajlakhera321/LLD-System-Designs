#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IRateLimitAlgo.h"

class RateLimiterService
{
private:
    IRateLimitAlgo *rateLimiter;

public:
    RateLimiterService(IRateLimitAlgo *rateLimiter);

    bool allowRequest(int userId, int timestamp, std::string endpoint);

    ~RateLimiterService();
};