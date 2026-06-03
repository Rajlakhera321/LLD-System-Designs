#pragma once
#include "bits/stdc++.h"

class ICache
{
public:
    virtual void saveUrlMapping(std::string shortUrl, std::string originalUrl) = 0;
    virtual std::string getOriginalUrl(std::string shortUrl) = 0;

    virtual ~ICache() {} // Default destructor
};