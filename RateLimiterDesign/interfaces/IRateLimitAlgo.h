#pragma once
#include <bits/stdc++.h>

class IRateLimitAlgo
{
public:
    void virtual addRequest(int userId, int timestamp, std::string endpoint) = 0;
    bool virtual isRateLimited(int userId, int timestamp, std::string endpoint) = 0;
    virtual ~IRateLimitAlgo() = default;
};