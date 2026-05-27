#pragma once
#include "bits/stdc++.h"

class IStorage
{
public:
    virtual void saveUrlMapping(std::string shortUrl, std::string originalUrl) = 0;
    virtual std::string getOriginalUrl(std::string shortUrl) = 0;
    virtual ~IStorage() {} // Default destructor
};