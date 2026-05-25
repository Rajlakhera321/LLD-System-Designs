#include "./LeakBucket.h"

void LeakBucket::addRequest(int userId, int timestamp, std::string endpoint)
{
    // Remove leaked requests
    while (!userBuckets[userId].empty() && userBuckets[userId].front() <= timestamp - 1000 / leakRate)
    {
        userBuckets[userId].pop();
    }

    // Add new request if bucket is not full
    if (userBuckets[userId].size() < capacity)
    {
        userBuckets[userId].push(timestamp);
    }
}

bool LeakBucket::isRateLimited(int userId, int timestamp, std::string endpoint)
{
    // Remove leaked requests
    while (!userBuckets[userId].empty() && userBuckets[userId].front() <= timestamp - 1000 / leakRate)
    {
        userBuckets[userId].pop();
    }

    // Check if bucket is full
    return userBuckets[userId].size() >= capacity;
}