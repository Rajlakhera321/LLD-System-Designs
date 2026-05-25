#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IRateLimitAlgo.h"

class FixedSizeWindow : public IRateLimitAlgo
{
private:
    int capacity;                                           // Max requests per window
    int windowSize;                                         // Window size in milliseconds
    std::unordered_map<int, std::queue<int> > userRequests; // userId -> queue of request timestamps

public:
    FixedSizeWindow(int capacity, int windowSize) : capacity(capacity), windowSize(windowSize) {}

    void addRequest(int userId, int timestamp, std::string endpoint) override;

    bool isRateLimited(int userId, int timestamp, std::string endpoint) override;
};