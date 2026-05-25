#include "./RateLimiterService.h"

RateLimiterService::RateLimiterService(IRateLimitAlgo *rateLimiter) : rateLimiter(rateLimiter) {}

bool RateLimiterService::allowRequest(int userId, int timestamp, std::string endpoint)
{
    if (rateLimiter->isRateLimited(userId, timestamp, endpoint))
    {
        return false;
    }

    rateLimiter->addRequest(userId, timestamp, endpoint);
    return true;
}

RateLimiterService::~RateLimiterService()
{
    delete rateLimiter;
}