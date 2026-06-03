#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"

class DBStorage : public IStorage
{
private:
    std::unordered_map<std::string, std::string> longToShortMapping;
    std::unordered_map<std::string, std::string> shortToLongMapping;

public:
    void saveUrlMapping(std::string shortUrl, std::string originalUrl) override;

    std::string getOriginalUrl(std::string shortUrl) override;

    std::string getShortUrl(std::string longUrl) override;
};