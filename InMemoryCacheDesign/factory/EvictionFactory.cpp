#include "./EvictionFactory.h"

EvictionPolicy *EvictionFactory::createEvictionPolicy(const string &policyType)
{
    if (policyType == "LRU")
        return new LRU();
    else if (policyType == "LFU")
        return new LFU();
    else
        throw invalid_argument("Invalid eviction policy type");
}