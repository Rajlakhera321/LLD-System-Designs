#pragma once
#include <bits/stdc++.h>

class LeakBucket : public IRateLimitAlgo
{
private:
    int capacity;
    int leakRate;                                // requests per second
    std::map<int, std::queue<int> > userBuckets; // userId -> queue of request timestamps

public:
    LeakBucket(int capacity, int leakRate) : capacity(capacity), leakRate(leakRate) {}
}