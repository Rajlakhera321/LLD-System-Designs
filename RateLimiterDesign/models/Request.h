#pragma once
#include <bits/stdc++.h>

class Request
{
private:
    int userId;
    int timestamp;
    int requestCount;
    string endpoint;

public:
    Request(int userId, int timestamp, string endpoint) : userId(userId), timestamp(timestamp), requestCount(1), endpoint(endpoint) {}

    int getUserId() const;

    int getTimestamp() const;

    int getRequestCount() const;

    void incrementRequestCount();

    string getEndpoint() const;
};