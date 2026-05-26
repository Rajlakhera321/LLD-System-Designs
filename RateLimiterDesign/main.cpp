#include "./service/RateLimiterService.h"
#include "./factories/RateLimiterFactory.h"
#include "./models/Request.h"
#include "./interfaces/IRateLimitAlgo.h"
#include "./strategies/FixedSizeWindow.h"
#include "./strategies/LeakBucket.h"
#include "vector"

int main()
{
    IRateLimitAlgo *rateLimiter = RateLimiterFactory::createRateLimiter("FixedSizeWindow", 5, 1000);
    RateLimiterService rateLimiterService(rateLimiter);

    // Simulate requests
    std::vector<int> timestamps = {
        1000,
        1100,
        1200,
        1300,
        1400,
        1500,
        1600};

    for (int timestamp : timestamps)
    {
        bool allowed = rateLimiterService.allowRequest(1, timestamp, "/api/data");
        std::cout << "Request at " << timestamp << " is " << (allowed ? "allowed" : "rate limited") << std::endl;
    }

    return 0;
}