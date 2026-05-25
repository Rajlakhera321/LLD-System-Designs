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
    std::vector<int> timestamps = {1000, 1500, 2000, 2500, 3000, 3500, 2800, 4000, 4500, 5000};

    for (int timestamp : timestamps)
    {
        bool allowed = rateLimiterService.allowRequest(1, timestamp, "/api/data");
        std::cout << "Request at " << timestamp << " is " << (allowed ? "allowed" : "rate limited") << std::endl;
    }

    return 0;
}