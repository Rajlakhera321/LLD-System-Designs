#include "./RateLimiterFactory.h"

IRateLimitAlgo *RateLimiterFactory::createRateLimiter(std::string type, int capacity, int rate)
{
    if (type == "FixedSizeWindow")
    {
        return new FixedSizeWindow(capacity, rate);
    }
    else if (type == "LeakBucket")
    {
        return new LeakBucket(capacity, rate);
    }
    return nullptr;
}