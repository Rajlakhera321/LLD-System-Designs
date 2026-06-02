#pragma once
#include "bits/stdc++.h"
#include "./interfaces/IEncoder.h"
#include "./interfaces/IStorage.h"
#include "./models/IDGenerator.h"
#include "./storages/DBStorage.h"
#include "./storages/RedisStorage.h"

class UrlShortenerService
{
private:
    IEncoder *encoder;
    DBStorage *dbStorage;
    RedisStorage *redisStorage;
    std::string domain = "https://tinyurl.com/"; // longUrl -> shortUrl

public:
    UrlShortenerService(IEncoder *encoder, DBStorage *dbStorage, RedisStorage *redisStorage) : encoder(encoder), dbStorage(dbStorage), redisStorage(redisStorage) {}

    std::string shortenUrl(const std::string &longUrl);

    std::string getLongUrl(const std::string &shortUrl);
};