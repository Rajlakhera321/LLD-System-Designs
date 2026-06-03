#pragma once
#include "bits/stdc++.h"

class IStorage
{
public:
    virtual void saveUrlMapping(std::string shortUrl, std::string originalUrl) = 0;
    virtual std::string getOriginalUrl(std::string shortUrl) = 0;

    virtual std::string getShortUrl(std::string longUrl) = 0; // Added method to get short URL from long URL
    virtual ~IStorage() {}                                    // Default destructor
};