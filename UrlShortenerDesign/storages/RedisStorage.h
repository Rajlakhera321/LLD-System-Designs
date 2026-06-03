#pragma once
#include "bits/stdc++.h"
#include "../interfaces/ICache.h"

class RedisStorage : public ICache
{
private:
    std::unordered_map<std::string, std::string> urlMapping;

public:
    void saveUrlMapping(std::string shortUrl, std::string originalUrl) override;

    std::string getOriginalUrl(std::string shortUrl) override;
};