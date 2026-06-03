#pragma once
#include "bits/stdc++.h"
#include "./interfaces/IEncoder.h"
#include "./interfaces/IStorage.h"
#include "./interfaces/ICache.h"
#include "./models/IDGenerator.h"

class UrlShortenerService
{
private:
    std::unique_ptr<IEncoder> encoder;
    std::unique_ptr<IStorage> dbStorage;
    std::unique_ptr<ICache> redisStorage;
    std::string domain = "https://tinyurl.com/"; // longUrl -> shortUrl

public:
    UrlShortenerService(std::unique_ptr<IEncoder> encoder, std::unique_ptr<IStorage> dbStorage, std::unique_ptr<ICache> redisStorage) : encoder(std::move(encoder)), dbStorage(std::move(dbStorage)), redisStorage(std::move(redisStorage)) {}

    std::string shortenUrl(const std::string &longUrl);

    std::string getLongUrl(const std::string &shortUrl);
};